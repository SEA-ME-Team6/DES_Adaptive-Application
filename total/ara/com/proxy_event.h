#ifndef PROXY_EVENT_H
#define PROXY_EVENT_H

#include <functional>
#include <limits>
#include <string>
#include "../core/result.h"
#include "handle_type.h"
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
            vsomeip_client event_client = ara::com::vsomeip_client::get_client();
        
        public:
            using SampleType = T;
            ProxyEvent() : mSampleCount(0) {}

            // Init() is Non Standard
            void Init(const uint16_t EventId, const uint16_t EventGroupId) {
                event_client.set_event_id(EventId, EventGroupId);
                event_client.register_message_handler();
            }

            void Deinit() {};

            ara::core::Result<void> Subscribe(size_t maxSampleCount) {
                mSampleCount = maxSampleCount;
                event_client.subscribe();
                return ara::core::Result<void>();
            }

            template <typename F>
            ara::core::Result<size_t> GetNewSamples(F&& f, size_t maxNumberOfSamples = std::numeric_limits<size_t>::max()) {
                if (mSampleCount <= maxNumberOfSamples) {
                }

                SampleType sampleValue = static_cast<SampleType>(event_client.get_samples());
                SamplePtr<const SampleType> samplePtr(&sampleValue);
                f(samplePtr);
                
                return ara::core::Result<size_t>(maxNumberOfSamples);
            }
        };
    } // namespace com
} // namespace ara

#endif // PROXY_EVENT_H
