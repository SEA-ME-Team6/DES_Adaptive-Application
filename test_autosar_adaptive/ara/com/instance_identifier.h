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

        public:
            /// @brief Constructor
            /// @param serializedFormat Shortname-path
            InstanceIdentifier();
            explicit InstanceIdentifier(std::string serializedFormat);
            InstanceIdentifier(const InstanceIdentifier &other);
            InstanceIdentifier(InstanceIdentifier &&other) noexcept;

            InstanceIdentifier &operator=(const InstanceIdentifier &other);
            InstanceIdentifier &operator=(InstanceIdentifier &&other);

            /// @brief InstanceIdentifier factory
            /// @param serializedFormat Shortname-path
            /// @returns Result containing the created InstanceIdentifier
            static ara::core::Result<InstanceIdentifier> Create(std::string serializedFormat) noexcept;

            /// @brief Convert the instance to a string
            /// @returns Meta-model ID (Shortname-path)
            std::string ToString() const noexcept;

            inline bool operator==(const InstanceIdentifier &other) const noexcept
            {
                return serializedFormat_ == other.serializedFormat_;
            }

            inline bool operator==(std::string other) const noexcept
            {
                return serializedFormat_ == other;
            }

            inline bool operator!=(const InstanceIdentifier &other) const noexcept
            {
                return serializedFormat_ != other.serializedFormat_;
            }

            inline bool operator!=(std::string other) const noexcept
            {
                return serializedFormat_ != other;
            }

            inline bool operator<(const InstanceIdentifier &other) const noexcept
            {
                return serializedFormat_ < other.serializedFormat_;
            }

            inline bool operator>(const InstanceIdentifier &other) const noexcept
            {
                return serializedFormat_ > other.serializedFormat_;
            }

        };

    }
}

#endif