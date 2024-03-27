#ifndef ARA_CORE_INITIALIZATION_H
#define ARA_CORE_INITIALIZATION_H

#include "result.h"

namespace ara 
{
    namespace core 
    {

        Result<void> Initialize() noexcept
        {
            return Result<void>();
        };

        Result<void> Deinitialize() noexcept
        {
            return Result<void>();
        };

    }
}

#endif // ARA_CORE_INITIALIZATION_H
