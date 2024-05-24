#include "service_factory.h"

namespace ara 
{
    namespace com 
    {

        ara::core::Result<ara::com::ServiceHandleContainer<HandleType>> ServiceFactory::FindService(ara::com::InstanceIdentifier& instance) {
            vsomeip_client sd_client = ara::com::vsomeip_client::get_client();
            sd_client.Init(instance);
            sd_client.set_service_id(instance);

            ServiceHandleContainer<HandleType> container;

            sd_client.register_availability_observer([&](bool is_available) {
                if (is_available) {

                    ara::com::ServiceHandleType service_handle(instance);
                    container.push_back(service_handle);

                    ara::com::FindServiceHandle handle(instance.GetInstanceId(), instance.GetInstanceId());
                }
            });
            sd_client.register_availability_handler();
            sd_client.start();

            return container;
        }

        ara::core::Result<ara::com::FindServiceHandle> ServiceFactory::StartFindService(ara::com::FindServiceHandler<HandleType> handler, ara::com::InstanceIdentifier instance) {
            while (true) {
                ara::core::Result<ara::com::ServiceHandleContainer<HandleType>> result = FindService(instance);

                if (result.HasValue()) {
                    handler(result.Value(), ara::com::FindServiceHandle(instance.GetInstanceId(), instance.GetInstanceId()));
                }
                
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }

        }

    } // namespace com
} // namespace ara