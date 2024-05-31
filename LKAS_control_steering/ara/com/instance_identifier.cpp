#include "./instance_identifier.h"

#include <string>
#include <iostream>

namespace ara
{
    namespace com
    {
        InstanceIdentifier::InstanceIdentifier() : instanceId_(0) {}
        
        InstanceIdentifier::InstanceIdentifier(
            const std::string &serializedFormat) : serializedFormat_{serializedFormat}
        {
            unsigned long InstanceId = std::stoi(serializedFormat_);
            instanceId_ = static_cast<uint16_t>(InstanceId);
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

        const uint16_t InstanceIdentifier::GetInstanceId() const {
            return instanceId_;
        }

        bool InstanceIdentifier::operator==(const InstanceIdentifier &other) const noexcept 
        {
            return serializedFormat_ == other.serializedFormat_;
        }

        bool InstanceIdentifier::operator<(const InstanceIdentifier &other) const noexcept
        {
            return serializedFormat_ < other.serializedFormat_;
        }
    }
}