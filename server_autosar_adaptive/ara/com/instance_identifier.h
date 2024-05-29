#ifndef INSTANCE_IDENTIFIER_H
#define INSTANCE_IDENTIFIER_H

#include <string>
#include <vector>
#include "../core/result.h"

namespace ara
{
    namespace com
    {
        /// @brief AUTOSAR shortname-path wrapper
        class InstanceIdentifier final
        {
        private:
            std::string mSerializedFormat;

            /// @brief InstanceID for SOMEIP Binding 
            /// @param mInstanceId Non Standard
            uint16_t mInstanceId;

        public:
            static const InstanceIdentifier Any;
            /// @brief Constructor
            /// @param serializedFormat Shortname-path
            InstanceIdentifier();
            InstanceIdentifier(const std::string &serializedFormat);

            /// @brief InstanceIdentifier factory
            /// @param serializedFormat Shortname-path
            /// @returns Result containing the created InstanceIdentifier
            static ara::core::Result<InstanceIdentifier> Create(const std::string &serializedFormat) noexcept;

            /// @brief Convert the instance to a string
            /// @returns Meta-model ID (Shortname-path)
            std::string ToString() const;

            /// Non Standard
            const uint16_t GetInstanceId() const;

            inline bool operator==(const InstanceIdentifier &other) const noexcept;

            inline bool operator<(const InstanceIdentifier &other) const noexcept;
        };

    }
}

#endif