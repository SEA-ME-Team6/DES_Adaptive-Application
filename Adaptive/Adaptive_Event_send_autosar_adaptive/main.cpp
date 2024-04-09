/* Code generated for Simulink model Adaptive_Event_send */
/* Generated on 19-Mar-2024 */

#include <cstdint>
#include <exception>
#include <chrono>
#include <functional>
#include "PosixExecutor.hpp"
#include <ara/core/initialization.h>
#include <ara/core/result.h>
#include <ara/core/string_view.h>
#include <ara/exec/execution_client.h>
#include <ara/log/common.h>
#include <ara/log/logger.h>
#include <ara/log/log_stream.h>
#ifdef __cplusplus
extern "C" {
#endif
#include "xcp_slave.h"
#ifdef __cplusplus
}
#endif
#include "Adaptive_Event_send.h"
Adaptive_Event_send rtObj;
void xcpRunBackground(std::future<void> &stopXCPServerRunFuture) {
  while (stopXCPServerRunFuture.wait_for(std::chrono::milliseconds(10)) ==
         std::future_status::timeout) {
    xcpSlaveRunBackground();
  } /* while */
}

/* main() handles the following: */
/*  - Instantiates the model object and owns its memory. */
/*  - Reports the Execution state to ARA */
/*  - Calls the model's initialize and terminate functions. */
/*  - Creates an executor instance to schedule the periodic step functions */
/*       - A timer that is set to the base rate is created in the executor */
/*       - The step functions are added to the executor and run */
/*         based on their sample periods */
int32_t main() {
  /* Used to control the flow in case of error in any api's used. */
  bool bProceed{true};
  /* Used to decide whether ara function clusters has been initialized. */
  bool bAraInitialized{true};
  /* ara function cluster init. */
  const ara::core::Result<void> initStatus{ara::core::Initialize()};

  if (!initStatus.HasValue()) {
    bProceed = false;
    bAraInitialized = false;
  } /* if */

  if (bAraInitialized) {
    ara::log::Logger &araLog{ara::log::CreateLogger(
        ara::core::StringView{"Adap"},
        ara::core::StringView{
            "Logger for Adaptive_Event_send's main function."},
        ara::log::LogLevel::kWarn)};

    /* Report Execution state */
    ara::exec::ExecutionClient exec_client;
    try {
      if (!exec_client.ReportExecutionState(
              ara::exec::ExecutionState::kRunning)) {
        araLog.LogError() << "Unable to report running state: "
                             "ara::exec::ExecutionReturnType::kGeneralError.\n";
        bProceed = false;
      } else {
        araLog.LogVerbose() << "Adaptive application entering running state.";
      } /* if */
    } catch (std::exception const &e) {
      araLog.LogError() << "Unable to report running state due to exception: "
                        << e.what() << ".\n";
      bProceed = false;
    }

    if (bProceed) {
      /* Arguments for XCP Slave Transport Layer as specified in Model Settings
       * (configset). */
      int32_t lArgc = 6;
      const void *lArgv[] = {"-port", "22",       "-protocol",
                             "TCP",   "-verbose", "1"};
      /* Initialize Functions */
      try {
        rtObj.initialize();
        if (xcpSlaveInit(lArgc, lArgv)) {
          araLog.LogError() << "XCP Initialization failed.\n";
          bProceed = false;
        } else {
          araLog.LogVerbose() << "XCP Server initialized successfully.\n";
        } /* if */
      } catch (std::exception const &e) {
        araLog.LogError() << "Unable to initialize: " << e.what() << ".\n";
        bProceed = false;
      }
    } /* if */

    if (bProceed) {
      /* Create an executor instance to schedule the periodic step functions */
      /* Whenever the period of a step function passes, the executor */
      /* schedules that step function to be executed on a thread. */
      platform::runtime::Executor fcnExecutor;

      /* Base rate is the time unit of a tick */
      const double baseRate{1.000000};
      fcnExecutor.setBaseRateInSeconds(std::chrono::duration<double>(baseRate));

      /* Register periodic step functions in the executor. */
      fcnExecutor.addPeriodicEvent(
          [&araLog]() {
            try {
              rtObj.step();
              xcpSlaveEvent(0);
            } catch (std::exception const &e) {
              araLog.LogError() << "Error executing step: " << e.what();
            }
          },
          1);

      std::promise<void> stopXCPServerRunPromise;
      auto stopXCPServerRunFuture = stopXCPServerRunPromise.get_future();
      fcnExecutor.addEvent(
          [&stopXCPServerRunFuture]() {
            xcpRunBackground(stopXCPServerRunFuture);
            return false;
          },
          nullptr,
          [&stopXCPServerRunPromise]() {
            stopXCPServerRunPromise.set_value();
          });

      araLog.LogVerbose() << "Starting Step function.";
#if defined(rtmSetStopRequested) && defined(rtmGetStopRequested)
      fcnExecutor.run(
          [&rtObj]() { return rtmGetStopRequested(rtObj.getRTM()); }, araLog);
#else
      fcnExecutor.run(araLog);
#endif
    } /* if */

    if (bProceed) {
      try {
        xcpSlaveReset();
        araLog.LogVerbose() << "XCP Server Reset successfully.";
        /* Terminate Functions */
        rtObj.terminate();
      } catch (std::exception const &e) {
        araLog.LogError() << "Unable to terminate: " << e.what() << ".\n";
        bProceed = false;
      }
    } /* if */

    araLog.LogVerbose() << "Exiting adaptive application.\n";
    const ara::core::Result<void> deinitStatus{ara::core::Deinitialize()};
    if (!deinitStatus.HasValue()) {
      bAraInitialized = false;
    } /* if */
  }   /* if */

  constexpr int32_t APP_SUCCESS{0};
  constexpr int32_t APP_FAIL{1};
  return ((bAraInitialized && bProceed) ? APP_SUCCESS : APP_FAIL);
}
