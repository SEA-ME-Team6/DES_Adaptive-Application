#ifndef RESOLOVE_INSTANCE_H
#define RESOLOVE_INSTANCE_H

#include <vector>
#include <optional>
#include "../core/result.h"
#include "../core/instance_specifier.h"
#include "./instance_identifier.h"
#include "./instance_identifier_container.h"

namespace ara
{
    namespace com
    {
        namespace runtime
        {
            ara::core::Result<ara::com::InstanceIdentifierContainer> ResolveInstanceIDs(const ara::core::InstanceSpecifier& instanceSpec);
        }
    }
}

#endif