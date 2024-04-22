#ifndef FIND_SERVICE_HANDLE_H
#define FIND_SERVICE_HANDLE_H

#include <functional>
#include <vector>
#include "handle_type.h"
#include "service_handle_container.h"

namespace ara {
    namespace com {
        struct FindServiceHandle {
            private:
                uint16_t service_id;
                uint16_t instance_id;

            // bool operator==(const FindServiceHandle& other) const;
            // bool operator<(const FindServiceHandle& other) const;
            // FindServiceHandle& operator=(const FindServiceHandle& other);
        };

        template <typename HandleType>
        using FindServiceHandler = std::function<void(ServiceHandleContainer<HandleType>, FindServiceHandle)>;
    }
}
#endif