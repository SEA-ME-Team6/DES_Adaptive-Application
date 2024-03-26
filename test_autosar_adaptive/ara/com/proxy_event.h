#ifndef PROXY_EVENT_H
#define PROXY_EVENT_H

#include <functional>
#include <limits>
#include <string>
#include "../core/result.h"
#include "handle_type.h"
#include "sampleptr.h"

namespace ara 
{
    namespace com 
    {
        template<typename T>
        class ProxyEvent {

        private:
            std::string mInstanceId;
            uint16_t mSampleCount;
            uint16_t mEventId;
            uint16_t mEventGroupId;
        
        public:
            using SampleType = T;

            explicit ProxyEvent() = default;  

            // Init() is Non Standard
            void Init(const ara::com::HandleType& handle, uint16_t eventId, uint16_t eventGroupId) {
                mInstanceId = handle.GetInstanceId().ToString();
                mEventId = eventId;
                mEventGroupId = eventGroupId;
            }

            ara::core::Result<void> Subscribe(size_t maxSampleCount) {
                mSampleCount = maxSampleCount;
                // Have to modify
                return ara::core::Result<void>();
            }

            template <typename F>
            ara::core::Result<size_t> GetNewSamples(F&& f, size_t maxNumberOfSamples = std::numeric_limits<size_t>::max()) {
                size_t processedSamples = 0;
                // Sample fetching logic goes here
                return ara::core::Result<size_t>(processedSamples);
            }
        };
    } // namespace com
} // namespace ara

#endif // PROXY_EVENT_H
