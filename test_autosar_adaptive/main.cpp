/* Code generated for Simulink model test */
/* Generated on 09-Feb-2024 */

#include <cstdint>
#include <exception>
#include <chrono>
#include <functional>
#include "PosixExecutor.hpp"
#include "ara/core/initialization.h"
#include "ara/core/result.h"
#include "ara/core/string_view.h"
#include "ara/exec/execution_client.h"
#include "ara/log/common.h"
#include "ara/log/logger.h"
#include "ara/log/log_stream.h"
// #include "test.h"

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

//   if (bAraInitialized) {
//     ara::log::Logger &araLog{ara::log::CreateLogger(
//         ara::core::StringView{"test"},
//         ara::core::StringView{"Logger for test's main function."})};

//     /* Report Execution state */
//     ara::exec::ExecutionClient exec_client;
//     try {
//       if (!exec_client.ReportExecutionState(
//               ara::exec::ExecutionState::kRunning)) {
//         araLog.LogError() << "Unable to report running state: "
//                              "ara::exec::ExecutionReturnType::kGeneralError.\n";
//         bProceed = false;
//       } else {
//         araLog.LogVerbose() << "Adaptive application entering running state.";
//       } /* if */
//     } catch (std::exception const &e) {
//       araLog.LogError() << "Unable to report running state due to exception: "
//                         << e.what() << ".\n";
//       bProceed = false;
//     }

//     test test_Obj;
//     if (bProceed) {
//       /* Initialize Functions */
//       try {
//         test_Obj.initialize();
//       } catch (std::exception const &e) {
//         araLog.LogError() << "Unable to initialize: " << e.what() << ".\n";
//         bProceed = false;
//       }
//     } /* if */

//     if (bProceed) {
//       /* Create an executor instance to schedule the periodic step functions */
//       /* Whenever the period of a step function passes, the executor */
//       /* schedules that step function to be executed on a thread. */
//       platform::runtime::Executor fcnExecutor;

//       /* Base rate is the time unit of a tick */
//       const double baseRate{0.200000};
//       fcnExecutor.setBaseRateInSeconds(std::chrono::duration<double>(baseRate));

//       /* Register periodic step functions in the executor. */
//       fcnExecutor.addPeriodicEvent(
//           [&test_Obj, &araLog]() {
//             try {
//               test_Obj.step();
//             } catch (std::exception const &e) {
//               araLog.LogError() << "Error executing step: " << e.what();
//             }
//           },
//           1);

//       araLog.LogVerbose() << "Starting Step function.";
// #if defined(rtmSetStopRequested) && defined(rtmGetStopRequested)
//       fcnExecutor.run(
//           [&test_Obj]() { return rtmGetStopRequested(test_Obj.getRTM()); },
//           araLog);
// #else
//       fcnExecutor.run(araLog);
// #endif
//     } /* if */

//     if (bProceed) {
//       try {
//         /* Terminate Functions */
//         test_Obj.terminate();
//       } catch (std::exception const &e) {
//         araLog.LogError() << "Unable to terminate: " << e.what() << ".\n";
//         bProceed = false;
//       }
//     } /* if */

//     araLog.LogVerbose() << "Exiting adaptive application.\n";
//     const ara::core::Result<void> deinitStatus{ara::core::Deinitialize()};
//     if (!deinitStatus.HasValue()) {
//       bAraInitialized = false;
//     } /* if */
//   }   /* if */

//   constexpr int32_t APP_SUCCESS{0};
//   constexpr int32_t APP_FAIL{1};
//   return ((bAraInitialized && bProceed) ? APP_SUCCESS : APP_FAIL);
}
