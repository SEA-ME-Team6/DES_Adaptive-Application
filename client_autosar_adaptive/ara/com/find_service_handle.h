#ifndef FIND_SERVICE_HANDLE_H
#define FIND_SERVICE_HANDLE_H

#include <functional>
#include <vector>

namespace ara {
    namespace com {
        struct FindServiceHandle {
            private:
                uint16_t serviceId_;
                uint16_t instanceId_;
            public:
                FindServiceHandle();
                FindServiceHandle(const uint16_t serviceId, const uint16_t instanceId) : serviceId_(serviceId), instanceId_(instanceId) {}

            // bool operator==(const FindServiceHandle& other) const;
            // bool operator<(const FindServiceHandle& other) const;
            // FindServiceHandle& operator=(const FindServiceHandle& other);
        };

        template <typename HandleType>
        using FindServiceHandler = std::function<void(ServiceHandleContainer<HandleType>, FindServiceHandle)>;
    }
}
#endif