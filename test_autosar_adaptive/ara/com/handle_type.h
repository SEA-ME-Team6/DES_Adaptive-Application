#ifndef SERVICE_HANDLE_TYPE_H
#define SERVICE_HANDLE_TYPE_H

#include <../com/instance_identifier.h>

namespace ara
{
    namespace com 
    {

        class HandleType {
        public:
            explicit HandleType(const ara::com::InstanceIdentifier& id) : instanceId(id) {}

            bool operator==(const HandleType& other) const {
                return instanceId == other.instanceId;
            }

            const ara::com::InstanceIdentifier& GetInstanceId() const {
                return instanceId;
            }

        private:
            ara::com::InstanceIdentifier instanceId;
        };

    } // namespace core
} // namespace ara

#endif // SERVICE_HANDLE_TYPE_H
