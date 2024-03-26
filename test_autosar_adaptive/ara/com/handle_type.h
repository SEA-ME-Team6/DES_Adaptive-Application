#ifndef HANDLE_TYPE_H
#define HANDLE_TYPE_H

#include <../com/instance_identifier.h>

namespace ara
{
    namespace com 
    {
        class HandleType {
        public:
            ara::com::InstanceIdentifier instanceId;

            HandleType() = default;            
            explicit HandleType(const ara::com::InstanceIdentifier& id) : instanceId(id) {}
            
            HandleType(const HandleType& other) = default;
            HandleType(HandleType&& other) noexcept = default;
            HandleType& operator=(const HandleType& other) = default;
            HandleType& operator=(HandleType&& other) noexcept = default;
            
            bool operator==(const HandleType& other) const {
                return instanceId == other.instanceId;
            }

            const ara::com::InstanceIdentifier& GetInstanceId() const {
                return instanceId;
            }
        private:
            
        };

    } // namespace com
} // namespace ara

#endif // HANDLE_TYPE_H
