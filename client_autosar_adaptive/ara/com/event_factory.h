#ifndef EVENT_FACTORY_H
#define EVENT_FACTORY_H

#include <cstdint>
#include "proxy_event.h"

namespace ara 
{
    namespace com 
    {
        template<typename T>
        class EventFactory {
        public:
            static ara::com::ProxyEvent<T> CreateProxyEvent(const ara::com::ServiceHandleType& handle, const uint16_t mEventId, const uint16_t mEventGroupId) {
                ara::com::ProxyEvent<T> proxy_event;
                proxy_event.Init(mEventId, mEventGroupId);
                return proxy_event;
            }

        };
    } // namespace com
} // namespace ara

#endif // PROXY_EVENT_H
