#ifndef INSTANCE_IDENTIFIER_H
#define INSTANCE_IDENTIFIER_H

#include <string>
#include <vector>
#include "./result.h"

namespace ara
{
    namespace com
    {
        /// @brief AUTOSAR shortname-path wrapper
        class InstanceIdentifier final
        {
        private:
            std::string serializedFormat_;
            uint16_t instanceId;

        public:
            /// @brief Constructor
            /// @param serializedFormat Shortname-path
            InstanceIdentifier() {}
            explicit InstanceIdentifier(std::string serializedFormat);

            /// @brief InstanceIdentifier factory
            /// @param serializedFormat Shortname-path
            /// @returns Result containing the created InstanceIdentifier
            static ara::core::Result<InstanceIdentifier> Create(std::string serializedFormat) noexcept;

            /// @brief Convert the instance to a string
            /// @returns Meta-model ID (Shortname-path)
            std::string ToString() const;

            inline bool operator==(const InstanceIdentifier &other) const noexcept;

            inline bool operator<(const InstanceIdentifier &other) const noexcept;

        };

    }
}

#endif