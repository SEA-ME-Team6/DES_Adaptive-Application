#pragma once

#include <iostream>
#include <vector>
#include <csignal>
#include <atomic>
#include <algorithm>
#include <exception>
#include <cmath>
#include <numeric>
#include <memory>
#include <ctime>

#include <semaphore.h>
#include <signal.h>
#include <cstring>



#include "WorkerPool.hpp"
#include "Timer.hpp"

namespace platform {
namespace runtime {

/** @brief A global flag to control the termination of executor
 */
volatile std::sig_atomic_t haltExecutor = false;
sem_t haltSemaphore;


/** @brief The signal handler which is invoked to terminate the executor when
 *        a SIGINT or SIGTERM signal occurs
 *
 *  @param The signal number
*/
void ctrlCHandler(int signalNum) {
    if((signalNum == SIGINT) || (signalNum == SIGTERM)) {
        // Consider aborting the program directly to avoid the synchronization problem
        haltExecutor = true;
        sem_post(&haltSemaphore);
    }
}


/** @brief An executor monitors events given by users and dispatches the handlers of triggered events
 *          to threads for execution. Currently the supported types of events are periodic and aperiodic.
 *
 *  Usage:
 *     platform::runtime::Executor executor;
 *
 *     executor.addEvent([](){ std::this_thread::sleep_for(std::chrono::seconds(5)); },
 *                        [](){ std::cout << "Event B is triggered" << std::endl; });
 *
 *     executor.addPeriodicEvent([](){ std::cout << "Event A (period=2 ticks) is triggered\n" << std::endl; }, 2);
 *
 *     executor.run();
*/
class Executor {

    private:

        /** @brief A logger using standard output streams
         *
         *  Default logger type which is used as the logger template parameter in the `run()` methods
         *  when users do not provide a logger. For example, when logging is not needed.
         */
        struct DefaultLogger {
            std::ostream& LogVerbose() { return std::cout; }
            std::ostream& LogError()   { return std::cerr; }
        };

    public:

        Executor(size_t numWorkers=0) : workerPool(numWorkers) { }

        ~Executor() {
            stop();
        }

        Executor(const Executor& other) = delete;
        Executor(Executor&& other) = delete;

        Executor& operator = (const Executor& other) = delete;
        Executor& operator = (Executor&& other) = delete;

        /** @brief Function for adding a periodic event.
         *
         *  @param handler The event handler which gets called when the event is triggered
         *  @param tick The period of the event
         *  @param offset A time shift relative to the period
        */
        void addPeriodicEvent(std::function<void()>&& handler, const size_t tick, const size_t offset=0) {
            periodicEvents.push_back(std::unique_ptr<PeriodicEvent>(
                        new PeriodicEvent(tick, std::move(handler), offset)));
        }

        /** @brief Function for adding an aperiodic event.
         *
         *  @param waitFun The event to be monitored
         *  @param handler The event handler which gets called when the event is triggered
         *  @param haltFun The function to enable the waiting thread to return early from the waitFun
        */
        void addEvent(std::function<bool()>&& waitFun, std::function<void()> &&handler,
                std::function<void()> &&haltFun) {
            aperiodicEvents.push_back(std::unique_ptr<AperiodicEvent>(
                        new AperiodicEvent(std::move(waitFun), std::move(handler), std::move(haltFun))));
        }

        /** @brief Set up the base rate of timer. This is only used for periodic events.
         *
         *  A base rate is the time unit (in seconds) of a tick, e.g. if baseRate = 2 seconds,
         *  then one tick is 2 seconds. A periodic event uses ticks to represent the length
         *  of its period,
         *
         *  Example:
         *    Assume baseRate = 2 seconds, then a periodic event with 3 ticks means this
         *    event will repeatedly trigger every 6 seconds (3 ticks * baseRate)
         *
         *  @param rate The base rate in seconds
        */
        void setBaseRateInSeconds(const std::chrono::duration<double> rate) {
            assert(rate.count() > 0.0);
            baseRate = rate;
        }

        /** @brief Run with a stop condition.
         *
         *  @param condition A callable to decide if the execution should stop
        */
        void run(std::function<bool()>&& condition) {
            run<std::function<bool()>, DefaultLogger>(condition, nullptr, -1);
        }

        /** @brief Run with a stop condition passed in the current tick.
         *
         *  @param condition A callable passed in the current tick to decide if the execution should stop
        */
        void run(std::function<bool(size_t)>&& condition) {
            run<std::function<bool(size_t)>, DefaultLogger>(condition, nullptr, -1);
        }

        /** @brief Run with a stop condition and a logger.
         *
         *  Example:
         *     CustomLogger logger;
         *     int counter = 0;
         *
         *     // Users provide a stop condition and a logger.
         *     executor.run([&counter](){ return counter ++ > 10; }, logger);
         *
         *  @param condition A callable that checks if the execution should stop (return true)
         *  @param logger A user-provided logger
        */
        // A logger and a stop condition
        template <typename LoggerT>
        void run(std::function<bool()>&& condition, LoggerT& logger) {
            run(condition, &logger, -1);
        }

        /** @brief Run with a stop condition passed in the current tick and a logger.
         *
         *  Example:
         *     CustomLogger logger;
         *     int counter = 0;
         *
         *     // Run with a stop condition checking current tick, and a logger
         *     executor.run([&counter](size_t currentTick){
         *         return (counter ++ > 10) || currentTick > 10;
         *      }, logger);
         *
         *  @param condition A callable passed in the current tick (size_t) to decide if the execution should stop
         *  @param logger A user-provided logger
        */
        template <typename LoggerT>
        void run(std::function<bool(size_t)>&& condition, LoggerT& logger) {
            run(condition, &logger, -1);
        }

        /** @brief Run with a logger and an optional time limit (default is -1 which means infinite)
         *
         *  @param logger A user-provided logger
         *  @param tickLimit Total number of ticks allowed for the execution
        */
        template <typename LoggerT>
        void run(LoggerT& logger, int tickLimit=-1) {
            auto fcn = []() -> bool { return false; };
            run(fcn, &logger, tickLimit);
        }

        /** @brief Run without an optional time limit (default is -1 which means infinite)
         *
         *  Example:
         *      executor.run();
         *
         *  @param tickLimit Total number of ticks allowed for the execution
         */
        void run(int tickLimit=-1) {
            auto fcn = []() -> bool { return false; };
            run<decltype(fcn), DefaultLogger>(fcn, nullptr, tickLimit);
        }

    private:

        /** @brief The event base class - each event (regardless of the type) must have a handler
         *
         *  The executor guarantees:
         *    1. The handler will be invoked as many times as the event gets triggered.
         *    2. The handler will be invoked sequentially even the event gets triggered multiple 
         *    times in a short period.
         *
         *  Users need to guarantee:
         *     There is no data race between concurrent events and handlers.
         */
        struct Event {
            Event(std::function<void()> &&aHandler): handler(std::move(aHandler)) {}

            std::function<void()> handler;

            /** @brief remainRuns records the number of times the handler needs to be executed
             *
             *  Whenever the event gets triggered, remainRuns is incremented by 1
             *  and the remainRuns is decremented by 1 everytime after the handler is executed.
             *  This can be used for overrun detection.
             */
            std::atomic<int> remainRuns {0};

            void operator()() {
               auto numRuns = remainRuns.load();
               while(numRuns > 0) {
                   for(int i=0; i<numRuns; i++) {
                       handler();
                   }
                   const int numFinishedRuns {numRuns};
                   numRuns = remainRuns.fetch_sub(numFinishedRuns) - numFinishedRuns;
               }
            }
        };

        struct PeriodicEvent final: public Event {
            PeriodicEvent(size_t aTick, std::function<void()> &&aHandler, size_t aOffset):
                Event(std::move(aHandler)), tick(aTick), offset(aOffset) {}
            size_t tick {1};
            size_t offset {0};
        };

        /** @brief Aperiodic events are triggered irregularly
         *
         *  An aperiodic event might never be triggered or triggered after a long time, and thus
         *  a haltFun is required to allow the thread waiting for the aperiodic event to return
         *  early when the executor terminates.
         */
        struct AperiodicEvent final: public Event {
            AperiodicEvent(std::function<bool()> &&event, std::function<void()> &&handler, std::function<void()> &&haltFun):
                Event(std::move(handler)), waitFun(std::move(event)), haltFun(std::move(haltFun)) {}
            std::function<bool()> waitFun;
            std::function<void()> haltFun;
        };

        std::vector<std::unique_ptr<PeriodicEvent>> periodicEvents;
        std::vector<std::unique_ptr<AperiodicEvent>> aperiodicEvents;

        std::vector<std::thread> waiters;
        utility::WorkerPool workerPool;

        bool start {false};
        std::chrono::duration<double> baseRate {0.0};

        std::condition_variable cv;
        std::mutex mtx;

        /** @brief The function to be called by the threads monitoring aperiodic events
         *
         *  The function executed by the threads which wait for aperiodic events.
         *  Executor creates a thread (called waiter) to wait for each aperiodic event. The waiter
         *  will call the `waitFun` which returns when the aperiodic event is triggered.
         *  The `index` is the index of the aperiodic event in the vector.
         *
         *  @param index The index of the aperiodic event monitored by the thread
        */
        void waiterLoop(const int index);


        /** @brief Schedule periodic events if any
         *
         *  Create a timer armed with the base rate to schedule the periodic events and dispatch
         *  the handlers of triggered events to execution. This function is called by the main
         *  thread only when periodic events exist.
         *
         *  @param logger An optional logger which will be called to emit information
         *  @param tickLimit An optional time limit
        */
        template <typename LoggerT, typename CallableT>
        void schedulePeriodicEvents(LoggerT* logger, int tickLimit=-1, CallableT& condition = nullptr);


        /** @brief Register the SIGINT & SIGTERM signal handler which will terminate the executor when signaled
         */
        bool registerCtrlC() {
            if(std::signal(SIGINT, ctrlCHandler) == SIG_ERR ||
               std::signal(SIGTERM, ctrlCHandler) == SIG_ERR) {
                return false;
            }
            return true;
        }

        /** @brief Invoke the halt function to enable early return from aperiodic events
         *
         *  Notify waiters to return from waitFun. Without this, waiters might get stuck indefinitely
         */
        void unblockWaiters() {
            std::for_each(aperiodicEvents.begin(), aperiodicEvents.end(),
                    [](std::unique_ptr<AperiodicEvent>& e){ e->haltFun(); });
        }

        /**  @brief Terminate the executor and join all threads (workers & waiters)
         */
        void stop();

        /**  @brief Check the given condition to see the executor should stop or not
         */
        template<typename CallableT>
        bool shouldStop(CallableT& condition, size_t currentTick, std::false_type) {
            return condition(currentTick);
        }
        template<typename CallableT>
        bool shouldStop(CallableT& condition, size_t, std::true_type) {
            return condition();
        }

        /** @brief This function implements the logic to schedule all events
         *
         *  All other run() methods will call this function to start the event execution
         *
         *  @param logger An optional logger which will be called to emit information
         *  @param tickLimit An optional time limit
         */
        template <typename CallableT, typename LoggerT>
        void run(CallableT& condition, LoggerT *logger=nullptr, int tickLimit=-1);


        /** @brief An utility function to calculate the greatest common divisor of two numbers
         */
        size_t gcd(size_t a, size_t b) const { return (b == 0) ? a : gcd(b, a%b); }

        /** @brief An utility function to disable handler of SIGINT and SIGTERM
         */
        template<typename LoggerT>
        void blockSignals(LoggerT* logger=nullptr);

        /** @brief An utility function to enable handler of SIGINT and SIGTERM
         */
        template<typename LoggerT>
        void unblockSignals(LoggerT* logger=nullptr);
};


void Executor::stop() {
    {
        std::lock_guard<std::mutex> lock {mtx};
        start = false;
        haltExecutor = true;
    }
    cv.notify_all();

    const auto joinThread = [](std::thread& thd){
      if(thd.joinable()) {
          thd.join();
      }
    };

    std::for_each(waiters.begin(), waiters.end(), joinThread);
}

void Executor::waiterLoop(const int index) {
    std::unique_lock<std::mutex> lock {mtx};
    cv.wait(lock, [this]() -> bool { return haltExecutor || this->start; });

    while(start && !haltExecutor) {
        lock.unlock();
        const bool isTriggered = aperiodicEvents[index]->waitFun();
        if(!isTriggered) {
            break;
        }

        const bool isDispatched = (aperiodicEvents[index]->remainRuns.fetch_add(1) != 0);
        if(!isDispatched) {
            workerPool.post([this, index](){ (*this->aperiodicEvents[index])(); });
        }
        lock.lock();
    }
}

template <typename LoggerT, typename CallableT>
void Executor::schedulePeriodicEvents(LoggerT *logger, int tickLimit, CallableT& condition) {

    // Sort periodic events in decreasing order based on the ticks. This is for ERT's
    // rate-monotonic scheduling (short cycle events get triggered first.).
    std::sort(periodicEvents.begin(), periodicEvents.end(),
        [](const std::unique_ptr<PeriodicEvent>& e1, const std::unique_ptr<PeriodicEvent>& e2) -> bool {
            return e1->tick < e2->tick;
        }
    );

    const auto lcm = std::accumulate(periodicEvents.begin(), periodicEvents.end(), 1U,
        [this](size_t lcm, const std::unique_ptr<PeriodicEvent>& event) -> size_t {
            return (lcm * event->tick) / gcd(lcm, event->tick);
        }
    );

    utility::Timer timer {baseRate};

    // Notify waiters to start monitoring aperiodic events if any
    if(!aperiodicEvents.empty()) {
        std::lock_guard<std::mutex> lock {mtx};
        start = true;
        cv.notify_all();
    }

    blockSignals<LoggerT>(logger);
    timer.start();
    unblockSignals<LoggerT>(logger);

    size_t tickCounter {0};
    size_t currentTick {0};

    while(tickLimit != 0) {
        // Wait for timer pass one tick (period)
        try {
            timer.wait();
        }
        catch (const std::exception&) {
            if(logger != nullptr) {
                logger->LogError() << "Error: an error occurs in timer wait function\n";
            }
            break;
        }

        // The haltExecutor might be set (signaled) when waiting for the timer to expire. 
        // So, we have to check haltExecutor after a tick passed and before dispatching 
        // the event handlers.
        if(haltExecutor) {
            break;
        }

        for(size_t i=0; i<periodicEvents.size(); i++) {
            if((tickCounter+1) % periodicEvents[i]->tick == periodicEvents[i]->offset) {
                if(periodicEvents[i]->remainRuns.fetch_add(1) == 0) {
                    workerPool.post([this, i](){ (*this->periodicEvents[i])(); });
                }
                else {
                    // Prior executions are not finished yet while the event gets triggered again
                    if(logger != nullptr) {
                        logger->LogVerbose() << "INFO: Overrun detected: Periodic event " << i << " triggers too fast\n";
                    }
                }
            }
        }

        tickCounter = (tickCounter+1)%lcm;
        currentTick ++;

        const bool isLastTick {(tickLimit > 0) && (--tickLimit == 0)};
        using isVoidInputType = std::is_constructible<std::function<bool(void)>,
                                                  typename std::remove_reference<CallableT>::type>;
        if(isLastTick || shouldStop(condition, currentTick, isVoidInputType())) {
            workerPool.wait();
            break;
        }

    } // End of periodic event schedule loop

}

template <typename CallableT, typename LoggerT>
void Executor::run(CallableT& condition, LoggerT* logger, int tickLimit) {

    // tickLimit should be either a positive number if a runtime limit is given
    // OR -1 if there is no limit imposed (terminated by signal only)
    assert(tickLimit != 0);

    if(!registerCtrlC()) {
        if(logger != nullptr) {
            logger->LogError() << "Signal Registration fails!\n";
        }
        return;
    }
    sem_init(&haltSemaphore, 0, 0U);

    if(periodicEvents.empty() && aperiodicEvents.empty()) {
        // Currently aperiodic step functions (adaptive AUTOSAR model) are
        // called directly inside main.cpp. If there is no periodic step
        // functions, the executor should still wait until signaled termination.
        sem_wait(&haltSemaphore);
        sem_destroy(&haltSemaphore);
        return;
    }

    workerPool.start();
    for(size_t i {0}; i<aperiodicEvents.size(); i++) {
        waiters.emplace_back([this, i] () { this->waiterLoop(i); });
    }

    if(!periodicEvents.empty()) {
        schedulePeriodicEvents<LoggerT, CallableT>(logger, tickLimit, condition);
    }
    else {
        {
            // Notify waiters to start monitoring aperiodic events
            std::lock_guard<std::mutex> lock {mtx};
            start = true;
            cv.notify_all();
        }

        if(tickLimit < 0) {
            // Wait until interrupted by signals if users do not specify a time limit 
            // Note: with semaphore, only main thread can be interrupted and there is 
            //       no need to periodically wake up to check the halt flag
            sem_wait(&haltSemaphore);
        }
        else {
            struct timespec ts;
            ts.tv_sec = tickLimit*std::chrono::duration<double>(baseRate).count();
            ts.tv_nsec = (tickLimit*std::chrono::duration<double>(baseRate).count() - ts.tv_sec)*1e9;
            // Wait until either time out or interrupted by signals
            sem_timedwait(&haltSemaphore, &ts);
        }
    }
    sem_destroy(&haltSemaphore);
    unblockWaiters();
    stop();
}


template <typename LoggerT>
void Executor::blockSignals(LoggerT *logger)
{
    constexpr int32_t FAIL_SIGN{-1};

    sigset_t sigset;
    sigemptyset(&sigset);
    sigaddset(&sigset, SIGRTMIN);
    sigaddset(&sigset, SIGTERM);
    if (pthread_sigmask(SIG_SETMASK, &sigset, NULL) == FAIL_SIGN && logger != nullptr) {
        logger->LogError() << "Blocking signals failed: " << std::strerror(errno);
    }
}

template <typename LoggerT>
void Executor::unblockSignals(LoggerT *logger)
{
    constexpr int32_t FAIL_SIGN{-1};

    sigset_t sigset;
    sigemptyset(&sigset);
    sigaddset(&sigset, SIGRTMIN);
    sigaddset(&sigset, SIGTERM);
    if (pthread_sigmask(SIG_UNBLOCK, &sigset, NULL) == FAIL_SIGN && logger != nullptr) {
        logger->LogError() << "Unblocking signals failed: " << std::strerror(errno);
    }
}



} // End of runtime namespace
} // End of platform namespace


