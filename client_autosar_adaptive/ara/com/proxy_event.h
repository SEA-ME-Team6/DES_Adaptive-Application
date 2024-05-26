#ifndef PROXY_EVENT_H
#define PROXY_EVENT_H

#include <functional>
#include <limits>
#include <string>
#include "sampleptr.h"
#include "./vsomeip/vsomeip_client.h"

namespace ara 
{
    namespace com 
    {
        template<typename T>
        class ProxyEvent {

        private:
            uint16_t mSampleCount;
            vsomeip_client& event_client = ara::com::vsomeip_client::get_client();
        
        public:
            using SampleType = T;
            ProxyEvent() : mSampleCount(0) {}

            // Init() is Non Standard
            void Init(const uint16_t EventId, const uint16_t EventGroupId) {
                // std::cout << "event client: " << event_client << std::endl;
                event_client.set_event_id(EventId, EventGroupId);
                event_client.register_message_handler();
                event_client.request_event();
            }

            void Deinit() {};

            ara::core::Result<void> Subscribe(size_t maxSampleCount) {
                mSampleCount = maxSampleCount;
                event_client.subscribe();
                std::cout << "Subscribe" << std::endl;
                event_client.start();
                std::cout << "Restart" << std::endl;
                return ara::core::Result<void>();
            }

            template <typename F>
            ara::core::Result<size_t> GetNewSamples(F&& f, size_t maxNumberOfSamples = std::numeric_limits<size_t>::max()) {
                if (mSampleCount <= maxNumberOfSamples) {
                }
                SampleType sampleValue = event_client.get_samples();
                std::cout << "GetNewSamples" << std::endl;
                SamplePtr<SampleType const> ptr;
                ptr.Set(&sampleValue);
                f(std::move(ptr));
                return ara::core::Result<size_t>(maxNumberOfSamples);
            }
        };
    } // namespace com
} // namespace ara

#endif // PROXY_EVENT_H
