#include "./instance_identifier.h"

namespace ara
{
    namespace com
    {
        // InstanceIdentifier::InstanceIdentifier() {}
        
        InstanceIdentifier::InstanceIdentifier(std::string serializedFormat) : serializedFormat_{serializedFormat}
        {
        }

        static ara::core::Result<InstanceIdentifier> InstanceIdentifier::Create(std::string serializedFormat) noexcept
        {
            instanceId = stoi(serializedFormat);
            if (instanceId >= std::numeric_limits<uint16_t>::min() && instanceId <= std::numeric_limits<uint16_t>::max()) {
                return ara::core::Result<InstanceIdentifier>::Ok();
            }
            else
                return ara::core::Result<InstanceIdentifier>::Error("Invalid serializedFormat value: out of range");

        }

        std::string InstanceIdentifier::ToString() const
        {
            return serializedFormat_;
        }

        inline bool operator==(const InstanceIdentifier &other) const noexcept 
        {
            return serializedFormat_ == other.serializedFormat_;
        }

        inline bool operator<(const InstanceIdentifier &other) const noexcept
        {
            return serializedFormat_ < other.serializedFormat_;
        }

    }
}