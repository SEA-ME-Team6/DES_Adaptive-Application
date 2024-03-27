#ifndef ARA_CORE_INITIALIZATION_H
#define ARA_CORE_INITIALIZATION_H

#include "result.h"
#include <mutex>

namespace ara 
{
    namespace core 
    {

        Result<void> Initialize() noexcept
        {
            static std::mutex initializationMutex;
            static bool isInitialized;
            
            std::lock_guard<std::mutex> lock(initializationMutex);

            if (!isInitialized) {
                // Perform initialization logic here
                // For example, initialize system resources, start background threads, etc.

                isInitialized = true;
            }
            return Result<void>::FromValue();
        };

        Result<void> Deinitialize() noexcept
        {
            static std::mutex initializationMutex;
            static bool isInitialized;

            std::lock_guard<std::mutex> lock(initializationMutex);
            if (isInitialized) {
                // Perform deinitialization logic here
                // For example, orderly shutdown of background threads, deallocate resources, etc.

                isInitialized = false;
            }
            return Result<void>::FromValue();
        };

    }
}

#endif // ARA_CORE_INITIALIZATION_H

