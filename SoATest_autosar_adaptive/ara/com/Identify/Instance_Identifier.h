#include <string>

namespace ara
{
    namespace com
    {
    class InstanceIdentifier
    {
    public:
        explicit InstanceIdentifier(std::string instanceidentifier);
        std::string ToString() const;
        bool operator==(const InstanceIdentifier& other) const;
        bool operator<(const InstanceIdentifier& other) const;
        InstanceIdentifier& operator=(const InstanceIdentifier& other);
    };
    }
}