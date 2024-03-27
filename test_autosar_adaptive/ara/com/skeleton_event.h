#ifndef SKELETION_EVENT_H
#define SKELETION_EVENT_H

#include "handle_type.h"
#include "sample_allocate_ptr.h"

namespace ara 
{
    namespace com 
    {
        template<typename T>
        class SkeletonEvent {
        private:
            std::string mInstanceId;
            uint16_t mEventId, mEventGroupId;

        public:
            using SampleType = double;

            explicit SkeletonEvent() = default;  

            // Init() is Non Standard
            void Init(const ara::com::HandleType& handle, uint16_t mEventId, uint16_t mEventGroupId) {
                this->mInstanceId = handle.GetInstanceId().ToString();
                this->mEventId = mEventId;
                this->mEventGroupId = mEventGroupId;
            }

            void Deinit() {};

            ara::core::Result<void> Send(const SampleType &data) {};

            ara::core::Result<ara::com::SampleAllocateePtr<SampleType>> Allocate() {};

            /**
            * After sending data you loose ownership and can’t access
            * the data through the SampleAllocateePtr anymore.
            * Implementation of SampleAllocateePtr will be with the
            * semantics of std::unique_ptr (see types.h)
            */
            ara::core::Result<void> Send(ara::com::SampleAllocateePtr<SampleType> data) {};
        };
    }
}

#endif