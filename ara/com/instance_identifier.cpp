#include "instance_identifier.h"

#include <string>
#include <iostream>

namespace ara
{
    namespace com
    {
        InstanceIdentifier::InstanceIdentifier() : mInstanceId(0) {}
        
        InstanceIdentifier::InstanceIdentifier(
            const std::string &serializedFormat) : serializedFormat_{serializedFormat}
        {
            unsigned long temp = std::stoi(serializedFormat_);
            mInstanceId = static_cast<uint16_t>(temp);
            // std::cout << "typeid : " << typeid(temp).name() << std::endl;

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
            return mInstanceId;
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