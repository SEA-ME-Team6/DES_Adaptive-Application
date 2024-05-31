#ifndef METHOD_CALL_PROCCESSING_MODE_H
#define METHOD_CALL_PROCCESSING_MODE_H

namespace ara 
{
    namespace com 
    {
        enum class MethodCallProcessingMode : uint8_t{
            kPoll,
            kEvent,
            kEventSingleThread
        };
    }
}

#endif