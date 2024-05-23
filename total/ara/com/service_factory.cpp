#include "service_factory.h"

namespace ara 
{
    namespace com 
    {

        ara::core::Result<ara::com::ServiceHandleContainer<HandleType>> ServiceFactory::FindService(ara::com::InstanceIdentifier& instance) {
            // auto& client = ara::com::vsomeip_client::get_instance();
                    
        }

        ara::core::Result<ara::com::FindServiceHandle> ServiceFactory::StartFindService(ara::com::FindServiceHandler<HandleType> handler, ara::com::InstanceIdentifier instance) {
            vsomeip_client sd_client = ara::com::vsomeip_client::get_client();
            sd_client.Init(instance);
            sd_client.set_service_id(instance);
            sd_client.register_availability_observer([&](bool is_available) {
                if (is_available) {
                    ServiceHandleContainer<HandleType> container;

                    ara::com::ServiceHandleType service_handle(instance);
                    container.push_back(service_handle);

                    ara::com::FindServiceHandle handle(instance.GetInstanceId(), instance.GetInstanceId());
                    handler(container, handle);
                }
            });
            sd_client.register_availability_handler();
            sd_client.start();

            ara::com::FindServiceHandle success_handle(instance.GetInstanceId(), instance.GetInstanceId());
            return ara::core::Result<ara::com::FindServiceHandle>(success_handle);
        }   

    } // namespace com
} // namespace ara