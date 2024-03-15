#include "./instance_identifier.h"

namespace ara
{
    namespace com
    {
        InstanceIdentifier::InstanceIdentifier(
            std::string serializedFormat) : serializedFormat_{serializedFormat}
        {
        }

        InstanceIdentifier::InstanceIdentifier(
            const InstanceIdentifier &other) : serializedFormat_{other.serializedFormat_}
        {
        }

        InstanceIdentifier::InstanceIdentifier(
            InstanceIdentifier &&other) noexcept : serializedFormat_{std::move(other.serializedFormat_)}
        {
        }

        InstanceIdentifier &InstanceIdentifier::operator=(
            const InstanceIdentifier &other)
        {
            serializedFormat_ = other.serializedFormat_;
            return *this;
        }
        InstanceIdentifier &InstanceIdentifier::operator=(
            InstanceIdentifier &&other)
        {
            serializedFormat_ = std::move(other.serializedFormat_);
            return *this;
        }

        std::string InstanceIdentifier::ToString() const noexcept
        {
            return serializedFormat_;
        }

        ara::core::Result<InstanceIdentifier> InstanceIdentifier::Create(std::string serializedFormat) noexcept
        {
            InstanceIdentifier _InstanceIdentifier{serializedFormat};
            ara::core::Result<InstanceIdentifier> _result{std::move(_InstanceIdentifier)};

            return _result;
        }
    }
}