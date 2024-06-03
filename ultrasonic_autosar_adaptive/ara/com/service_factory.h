#ifndef SERVICE_FACTORY_H
#define SERVICE_FACTORY_H

#include <iostream>
#include "./find_service_handle.h"
#include "./vsomeip/vsomeip_client.h"
#include "./service_handle_type.h"
#include "./service_handle_container.h"

namespace ara 
{
    namespace com 
    {
        class ServiceFactory {
        private:

        public:
            static ara::com::ServiceHandleType FindService(const ara::com::InstanceIdentifier& instance);
            static ara::core::Result<ara::com::FindServiceHandle> StartFindService(const ara::com::FindServiceHandler<ara::com::ServiceHandleType>& handler, const ara::com::InstanceIdentifier& instance);
            static void StopFindService(ara::com::FindServiceHandle handle);
        };
    } // namespace com
} // namespace ara

#endif
