#ifndef EVENT_FACTORY_H
#define EVENT_FACTORY_H

#include <cstdint>
#include "proxy_event.h"

namespace ara 
{
    namespace com 
    {
        class EventFactory {
        private:
        public:
            template<typename T>
            static ara::com::ProxyEvent<double> CreateProxyEvent(const ara::com::ServiceHandleType& handle, T Param1, T Param2) {
                ara::com::ProxyEvent<double> proxy_event;
                if constexpr(std::is_same<T, uint16_t>::value) {
                    proxy_event.Init_SOMEIP(handle, Param1, Param2);
                }
                else if constexpr(std::is_same<T, std::string>::value) {
                    proxy_event.Init_DDS(handle, Param1, Param2);
                }
                return proxy_event;
            }

        };
    } // namespace com
} // namespace ara

#endif // PROXY_EVENT_H
