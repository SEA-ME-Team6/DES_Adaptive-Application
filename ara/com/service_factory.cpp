#include "service_factory.h"

namespace ara 
{
    namespace com 
    {

        ara::core::Result<ara::com::ServiceHandleContainer<HandleType>> ServiceFactory::FindService(ara::com::InstanceIdentifier& instance) {
            // auto& client = ara::com::vsomeip_client::get_instance();
                    
        }

        ara::core::Result<ara::com::FindServiceHandle> ServiceFactory::StartFindService(ara::com::FindServiceHandler<HandleType> handler, ara::com::InstanceIdentifier instance) {
            std::shared_ptr<ara::com::vsomeip_client> vsomeip_client;

            vsomeip_client->set_service_id(instance);
            vsomeip_client->register_availability_handler(handler);
        }

     
    } // namespace com
} // namespace ara