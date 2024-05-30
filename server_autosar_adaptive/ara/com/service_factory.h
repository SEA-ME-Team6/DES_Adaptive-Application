#ifndef SERVICE_FACTORY_H
#define SERVICE_FACTORY_H

#include <iostream>
#include "./find_service_handle.h"
#include "./vsomeip/vsomeip_client.h"

namespace ara 
{
    namespace com 
    {
        using HandleType = ara::com::ServiceHandleType;
        class ServiceFactory {

        private:

        public:
            static ara::core::Result<ara::com::ServiceHandleContainer<HandleType>> FindService(const ara::com::InstanceIdentifier& instance);
            static ara::core::Result<ara::com::FindServiceHandle> StartFindService(const ara::com::FindServiceHandler<HandleType>& handler, const ara::com::InstanceIdentifier& instance);
            static void StopFindService(ara::com::FindServiceHandle handle);
        };
    } // namespace com
} // namespace ara

#endif
