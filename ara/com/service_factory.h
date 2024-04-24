#ifndef SERVICE_FACTORY_H
#define SERVICE_FACTORY_H

#include "instance_identifier.h"
#include "vsomeip/vsomeip_client.h"
#include "handle_type.h"
#include "find_service_handle.h"

namespace ara 
{
    namespace com 
    {
        using HandleType = ara::com::ServiceHandleType;
        class ServiceFactory {

        private:
        
        public:
            static ara::core::Result<ara::com::ServiceHandleContainer<HandleType>> FindService(ara::com::InstanceIdentifier& instance);
            static ara::core::Result<ara::com::FindServiceHandle> StartFindService(ara::com::FindServiceHandler<HandleType> handler, ara::com::InstanceIdentifier instance);

        };
    } // namespace com
} // namespace ara

#endif
