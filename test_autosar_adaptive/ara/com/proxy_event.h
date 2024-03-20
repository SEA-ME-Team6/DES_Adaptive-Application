#include <functional>
#include <limits>
#include "../core/result.h"
#include "handle_type.h"

namespace ara 
{
    namespace com 
    {
        template <typename T>
        class ProxyEvent {

        private:
            std::string mInstanceId;
            std::string mEventId;
        
        public:
            using HandleType = ara::com::HandleType;

            explicit ProxyEvent() = default;  

            void Init(const HandleType& handle, const std::string& eventId) {
                mInstanceId = handle.GetInstanceId().ToString();
                mEventId = eventId;
            }

            ara::core::Result<void> Subscribe(size_t maxSampleCount);

            template <typename F>
            ara::core::Result<size_t> GetNewSamples(F&& f, size_t maxNumberOfSamples = std::numeric_limits<size_t>::max());

        };
    }
}