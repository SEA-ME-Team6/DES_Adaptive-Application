#ifndef HANDLE_TYPE_H
#define HANDLE_TYPE_H

#include <../com/instance_identifier.h>

namespace ara
{
    namespace com 
    {
        class ServiceHandleType {
        public:

            ServiceHandleType() {}       
            explicit ServiceHandleType(const ara::com::InstanceIdentifier& id) : instanceIdentifier(id) {}
            
            ServiceHandleType(const ServiceHandleType& other) = default;
            ServiceHandleType(ServiceHandleType&& other) noexcept = default;
            ServiceHandleType& operator=(const ServiceHandleType& other) = default;
            ServiceHandleType& operator=(ServiceHandleType&& other) noexcept = default;
            
            inline bool operator==(const ServiceHandleType& other) const {
                return instanceIdentifier == other.instanceIdentifier;
            }

            const ara::com::InstanceIdentifier& GetinstanceIdentifier() const {
                return instanceIdentifier;
            }
            ara::com::InstanceIdentifier instanceIdentifier;
        private:
        };

    } // namespace com
} // namespace ara

#endif // HANDLE_TYPE_H
