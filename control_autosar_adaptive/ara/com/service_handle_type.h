#ifndef HANDLE_TYPE_H
#define HANDLE_TYPE_H

#include "./instance_identifier.h"

namespace ara
{
    namespace com 
    {
        class ServiceHandleType {
        public:
            ServiceHandleType() {}       
            explicit ServiceHandleType(const ara::com::InstanceIdentifier& id) : mInstanceID(id) {}
            
            ServiceHandleType(const ServiceHandleType& other) = default;
            ServiceHandleType(ServiceHandleType&& other) noexcept = default;
            ServiceHandleType& operator=(const ServiceHandleType& other) = default;
            ServiceHandleType& operator=(ServiceHandleType&& other) noexcept = default;
            
            inline bool operator==(const ServiceHandleType& other) const {
                return mInstanceID == other.mInstanceID;
            }

            const ara::com::InstanceIdentifier& GetInstanceId() const {
                return mInstanceID;
            }
            ara::com::InstanceIdentifier mInstanceID;
        private:
        };

    } // namespace com
} // namespace ara

#endif // HANDLE_TYPE_H
