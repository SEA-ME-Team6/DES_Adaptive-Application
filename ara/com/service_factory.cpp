#include "service_factory.h"

namespace ara 
{
    namespace com 
    {

        ara::core::Result<ara::com::ServiceHandleContainer<HandleType>> ServiceFactory::FindService(ara::com::InstanceIdentifier& instance) {
            // auto& client = ara::com::vsomeip_client::get_instance();
                    
        }

        ara::core::Result<ara::com::FindServiceHandle> ServiceFactory::StartFindService(ara::com::FindServiceHandler<HandleType> handler, ara::com::InstanceIdentifier instance) {
            ara::com::vsomeip_client vsomeip_client;
            vsomeip_client.set_service_id(instance);
            // vsomeip_client.register_availability_observer([&](bool is_available) {
            //     if (is_available) {
            //         std::cout << "Service is available. Proceeding with further actions." << std::endl;
            //     } else {
            //         std::cout << "Service is not available. Aborting actions." << std::endl;
            //     }
            // });
            vsomeip_client.register_availability_handler();
            vsomeip_client.start();
        }   

    } // namespace com
} // namespace ara