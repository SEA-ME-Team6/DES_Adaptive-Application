#include <functional>
#include "../ara/core/result.h"
namespace ara 
{
    namespace com 
    {
        template <typename T>
        class ProxyEvent {
        public:
            ara::core::Result<void> Subscribe(size_t maxSampleCount);

            template <typename F>
            ara::core::Result<size_t> GetNewSamples(F&& f, size_t maxNumberOfSamples = std::numeric_limits<size_t>::max());

        };

    }
}