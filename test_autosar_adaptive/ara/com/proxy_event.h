#ifndef PROXY_EVENT_H
#define PROXY_EVENT_H

#include <functional>
#include <limits>
#include "../core/result.h"
#include "handle_type.h"
#include "sampleptr.h"

namespace ara 
{
    namespace com 
    {
        class ProxyEvent {

        private:
            size_t mSampleCount;
            std::string mInstanceId;
            std::string mEventId;
        
        public:
            using SampleType = double;

            explicit ProxyEvent() = default;  

            // Init() is Non Standard
            void Init(const ara::com::HandleType& handle, const std::string& eventId);

            ara::core::Result<void> Subscribe(size_t maxSampleCount);

            template <typename F>
            ara::core::Result<size_t> GetNewSamples(F&& f, size_t maxNumberOfSamples = std::numeric_limits<size_t>::max()) {
                size_t processedSamples = 0;
                if (maxNumberOfSamples <= this->mSampleCount) {
                    for (size_t i = 0; i < maxNumberOfSamples; ++i) {
                        ara::com::SamplePtr<SampleType const> samplePtr;
                        f(std::move(samplePtr));
                    }
                }
                return ara::core::Result<size_t>(processedSamples);

            };
        };
    }
}

#endif