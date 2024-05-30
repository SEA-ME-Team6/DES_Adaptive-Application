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
            explicit ServiceHandleType(const ara::com::InstanceIdentifier& id) : instanceId_(id) {}
            
            ServiceHandleType(const ServiceHandleType& other) = default;
            ServiceHandleType(ServiceHandleType&& other) noexcept = default;
            ServiceHandleType& operator=(const ServiceHandleType& other) = default;
            ServiceHandleType& operator=(ServiceHandleType&& other) noexcept = default;
            
            inline bool operator==(const ServiceHandleType& other) const {
                return instanceId_ == other.instanceId_;
            }

            const ara::com::InstanceIdentifier& GetInstanceId() const {
                return instanceId_;
            }
            ara::com::InstanceIdentifier instanceId_;
        private:
        };

    } // namespace com
} // namespace ara

#endif // HANDLE_TYPE_H
