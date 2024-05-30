#ifndef PROXY_EVENT_H
#define PROXY_EVENT_H

#include <functional>
#include <limits>
#include <string>
#include "./sampleptr.h"
#include "./vsomeip/vsomeip_client.h"

namespace ara 
{
    namespace com 
    {
        template<typename T>
        class ProxyEvent {
        private:
            uint16_t maxSampleCount_;
            ara::com::vsomeip_client& event_client = ara::com::vsomeip_client::get_client();
        
        public:
            using SampleType = float;
            ProxyEvent() : maxSampleCount_(0) {}

            // Init() is Non Standard
            void Init(const uint16_t& eventId, const uint16_t& eventGroupId) {
                event_client.set_event_id(eventId, eventGroupId);
                event_client.register_message_handler();
                event_client.request_event();
            }

            void Deinit() {};

            ara::core::Result<void> Subscribe(size_t maxSampleCount) {
                maxSampleCount_ = maxSampleCount;
                event_client.subscribe();
                
                std::thread([this]() {
                    event_client.start();
                }).detach();
                
                /* If the user wants to get notified,
                * when subscription has succeeded, he needs to register a handler
                * via \see SetSubscriptionStateChangeHandler(). This handler gets
                * then called after subscription was successful.
                * But In our case, We don't use Handler
                */
                return ara::core::Result<void>();
            }

            template <typename F>
            ara::core::Result<size_t> GetNewSamples(F&& f, size_t maxNumberOfSamples = std::numeric_limits<size_t>::max()) {
                ara::core::Result<size_t> result = maxNumberOfSamples;

                if (maxSampleCount_ <= maxNumberOfSamples) {
                    return ara::core::Result<size_t>::FromError(result.Error());
                }

                SampleType sampleValue = event_client.get_samples();
                SamplePtr<SampleType const> ptr;
                ptr.Set(&sampleValue);

                f(std::move(ptr));

                return result;
            }
        };
    } // namespace com
} // namespace ara

#endif // PROXY_EVENT_H
