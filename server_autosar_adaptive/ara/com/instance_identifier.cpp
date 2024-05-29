#include "instance_identifier.h"

#include <string>
#include <iostream>

namespace ara
{
    namespace com
    {
        InstanceIdentifier::InstanceIdentifier() : mInstanceId(0) {}
        
        InstanceIdentifier::InstanceIdentifier(
            const std::string &serializedFormat) : mSerializedFormat{serializedFormat}
        {
            unsigned long InstanceId = std::stoi(mSerializedFormat);
            mInstanceId = static_cast<uint16_t>(InstanceId);
        }

        ara::core::Result<InstanceIdentifier> InstanceIdentifier::Create(const std::string &serializedFormat) noexcept
        {
            InstanceIdentifier _instanceIdentifier{serializedFormat};
            ara::core::Result<InstanceIdentifier> _result{std::move(_instanceIdentifier)};
            return _result;
        }

        std::string InstanceIdentifier::ToString() const
        {
            return mSerializedFormat;
        }

        const uint16_t InstanceIdentifier::GetInstanceId() const {
            return mInstanceId;
        }

        inline bool InstanceIdentifier::operator==(const InstanceIdentifier &other) const noexcept 
        {
            return mSerializedFormat == other.mSerializedFormat;
        }

        inline bool InstanceIdentifier::operator<(const InstanceIdentifier &other) const noexcept
        {
            return mSerializedFormat < other.mSerializedFormat;
        }
    }
}