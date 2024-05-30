#include <thread>
#include <mutex>
#include <condition_variable>
#include "./service_factory.h"

namespace ara 
{
    namespace com 
    {

        ara::core::Result<ara::com::ServiceHandleContainer<HandleType>> ServiceFactory::FindService(const ara::com::InstanceIdentifier& instance) {
            ara::com::vsomeip_client& sd_client = ara::com::vsomeip_client::get_client();
            sd_client.init(instance);
            sd_client.set_service_id(instance);
            
            bool find_service = false;
            ara::com::ServiceHandleContainer<HandleType> container;
            std::mutex mtx;
            std::condition_variable cv;
            
            sd_client.register_availability_observer([&](bool is_available) {
                if (is_available) {
                    {
                        std::unique_lock<std::mutex> lock(mtx);
                        find_service = true;
                        ara::com::ServiceHandleType service_handle(instance);
                        container.push_back(service_handle);
                    }
                    cv.notify_one();
                }
            });

            sd_client.register_state_handler();
            sd_client.register_availability_handler();

            std::thread start_thread([&]() {
                sd_client.start();
            });

            {
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [&]() { return find_service; });
            }
            
            sd_client.stop();

            start_thread.join();

            return container;
        }

        ara::core::Result<ara::com::FindServiceHandle> ServiceFactory::StartFindService(const ara::com::FindServiceHandler<HandleType>& handler, const ara::com::InstanceIdentifier& instance) {
            /* In Standard AUTOSAR StartFindService calls FindService continuously,
            * But we use routing manager in vsomeip
            * It waits until finding service
            * So, we dont need to use while loop 
            */
            ara::core::Result<ara::com::ServiceHandleContainer<HandleType>> result = FindService(instance);

            if (result.HasValue()) {
                // Access the first ServiceHandleType from the ServiceHandleContainer
                ara::com::ServiceHandleContainer<HandleType> service_handle_container = result.Value();
                if (!service_handle_container.empty()) {
                    ara::com::HandleType first_service_handle = service_handle_container.front();
                    ara::com::FindServiceHandle find_service(first_service_handle.GetInstanceId().GetInstanceId(), first_service_handle.GetInstanceId().GetInstanceId());
                    handler(service_handle_container, find_service);
                    return find_service;
                }
            }

            return ara::core::Result<ara::com::FindServiceHandle>::FromError(result.Error());        
        }

        void ServiceFactory::StopFindService(ara::com::FindServiceHandle handle) {
            ara::com::vsomeip_client& stop_find_client = ara::com::vsomeip_client::get_client();
            stop_find_client.unregister_availability_handler(handle.GetServiceId(), handle.GetInstanceId());
        }
        

    } // namespace com
} // namespace ara