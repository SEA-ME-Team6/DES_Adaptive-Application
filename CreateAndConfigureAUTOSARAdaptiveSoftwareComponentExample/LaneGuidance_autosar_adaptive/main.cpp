/* Code generated for Simulink model LaneGuidance */
/* Generated on 24-Jan-2024 */

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
#include "LaneGuidance.h"

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

  ara::log::Logger &araLog{ara::log::CreateLogger(
      ara::core::StringView{"Lane"},
      ara::core::StringView{"Logger for LaneGuidance's main function."},
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

  LaneGuidance LaneGuidance_Obj;
  if (bProceed) {
    /* Initialize Functions */
    try {
      LaneGuidance_Obj.initialize();
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
    const double baseRate{0.100000};
    fcnExecutor.setBaseRateInSeconds(std::chrono::duration<double>(baseRate));

    /* Register periodic step functions in the executor. */
    fcnExecutor.addPeriodicEvent(
        [&LaneGuidance_Obj, &araLog]() {
          try {
            LaneGuidance_Obj.step();
          } catch (std::exception const &e) {
            araLog.LogError() << "Error executing step: " << e.what();
          }
        },
        1);

    araLog.LogVerbose() << "Starting Step function.";
#if defined(rtmSetStopRequested) && defined(rtmGetStopRequested)
    fcnExecutor.run(
        [&LaneGuidance_Obj]() {
          return rtmGetStopRequested(LaneGuidance_Obj.getRTM());
        },
        araLog);
#else
    fcnExecutor.run(araLog);
#endif
  } /* if */

  if (bProceed) {
    try {
      /* Terminate Functions */
      LaneGuidance_Obj.terminate();
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

  constexpr int32_t APP_SUCCESS{0};
  constexpr int32_t APP_FAIL{1};
  return ((bAraInitialized && bProceed) ? APP_SUCCESS : APP_FAIL);
}
