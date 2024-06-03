#ifndef SKELETION_EVENT_H
#define SKELETION_EVENT_H

#include "./service_handle_type.h"
#include "./sample_allocate_ptr.h"
#include "./vsomeip/vsomeip_server.h"

namespace ara 
{
    namespace com 
    {
        template<typename T>
        class SkeletonEvent {
        private:
            ara::com::vsomeip_server& service_server = ara::com::vsomeip_server::get_server();
       
        public:
            using SampleType = float;

            explicit SkeletonEvent() = default;  

            // Init() is Non Standard
            void Init(const ara::com::ServiceHandleType& handle, const uint16_t& eventId, const uint16_t& eventGroupId) {
                service_server.init(handle, eventId, eventGroupId);
                service_server.register_state_handler();
                service_server.offer_event();

                std::thread([this]() {
                    service_server.start();
                }).detach();
            }

            void Deinit() {
                service_server.stop();
            };

            ara::core::Result<void> Send(const SampleType &data) {
                service_server.notify(data);
                return ara::core::Result<void>();
            };

            ara::core::Result<ara::com::SampleAllocateePtr<SampleType>> Allocate() {
                ara::com::SampleAllocateePtr<SampleType> allocatedMemory(nullptr);
                return allocatedMemory;            
            };

            /**
            * After sending data you loose ownership and can’t access
            * the data through the SampleAllocateePtr anymore.
            * Implementation of SampleAllocateePtr will be with the
            * semantics of std::unique_ptr (see types.h)
            */
            ara::core::Result<void> Send(ara::com::SampleAllocateePtr<SampleType> data) {
                service_server.notify(*data);
                return ara::core::Result<void>();
            };
        };
    }
}

#endif