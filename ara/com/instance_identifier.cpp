#include "instance_identifier.h"

namespace ara
{
    namespace com
    {
        InstanceIdentifier::InstanceIdentifier() {}
        
        InstanceIdentifier::InstanceIdentifier(
            const std::string &serializedFormat) : serializedFormat_{serializedFormat}
        {
        }

        ara::core::Result<InstanceIdentifier> InstanceIdentifier::Create(const std::string &serializedFormat) noexcept
        {
            InstanceIdentifier _instanceIdentifier{serializedFormat};
            ara::core::Result<InstanceIdentifier> _result{std::move(_instanceIdentifier)};
            return _result;
        }

        std::string InstanceIdentifier::ToString() const
        {
            return serializedFormat_;
        }

        inline bool InstanceIdentifier::operator==(const InstanceIdentifier &other) const noexcept 
        {
            return serializedFormat_ == other.serializedFormat_;
        }

        inline bool InstanceIdentifier::operator<(const InstanceIdentifier &other) const noexcept
        {
            return serializedFormat_ < other.serializedFormat_;
        }
    }
}