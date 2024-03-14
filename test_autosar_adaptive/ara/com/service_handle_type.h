#ifndef SERVICE_HANDLE_TYPE_H
#define SERVICE_HANDLE_TYPE_H

#include <../core/instance_specifier.h>

namespace ara
{
    namespace com 
    {

        class ServiceHandleType {
        public:
            explicit ServiceHandleType(const ara::core::InstanceSpecifier& id) : instanceId(id) {}

            bool operator==(const ServiceHandleType& other) const {
                return instanceId == other.instanceId;
            }

            const ara::core::InstanceSpecifier& GetInstanceId() const {
                return instanceId;
            }

        private:
            ara::core::InstanceSpecifier instanceId;
        };

    } // namespace core
} // namespace ara

#endif // SERVICE_HANDLE_TYPE_H
