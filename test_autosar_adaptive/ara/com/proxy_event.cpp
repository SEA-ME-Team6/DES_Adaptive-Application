#include "proxy_event.h"

namespace ara 
{
    namespace com 
    {
        void ProxyEvent::Init(const HandleType& handle, const std::string& eventId) {
                this->mInstanceId = handle.GetInstanceId().ToString();
                this->mEventId = eventId;
        }

        ara::core::Result<void> ProxyEvent::Subscribe(size_t maxSampleCount) {
                this->mSampleCount = maxSampleCount;
                // Have to modify
        }

    }
}