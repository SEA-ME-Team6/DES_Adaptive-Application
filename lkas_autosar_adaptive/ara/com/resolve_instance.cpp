#include <vector>
#include <optional>

#include "./resolve_instance.h"

namespace ara
{
    namespace com
    {
        namespace runtime
        {
            ara::core::Result<ara::com::InstanceIdentifierContainer> ResolveInstanceIDs(const ara::core::InstanceSpecifier& instanceSpec) {
                ara::com::InstanceIdentifierContainer container;
                container.push_back(ara::com::InstanceIdentifier(instanceSpec.ToString()));
                return ara::core::Result<InstanceIdentifierContainer>(container);
            }
        }
    }
}
