#ifndef VSOMEIP_CLIENT_H
#define VSOMEIP_CLIENT_H

#ifndef VSOMEIP_ENABLE_SIGNAL_HANDLING
#include <csignal>
#endif
#include <chrono>
#include <condition_variable>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>
#include <string>
#include <vsomeip/vsomeip.hpp>

#include "../handle_type.h"
#include "../service_handle_container.h"
#include "../find_service_handle.h"
#include "../handle_type.h"
#include "../instance_identifier.h"

namespace ara
{
    namespace com
    {
        using HandleType = ara::com::ServiceHandleType;
        class vsomeip_client {
            public:
                explicit vsomeip_client();
                void start();
                void set_service_id(const ara::com::InstanceIdentifier instanceIdentifier);
                void set_event_id(const ::vsomeip::service_t EventId, const ::vsomeip::service_t EventGroupId); 
                void register_availability_handler(std::function<void(ServiceHandleContainer<HandleType>, FindServiceHandle)> handler, const ara::com::InstanceIdentifier instanceIdentifier);
                void subscribe();
                void stop();

            private:
                // void on_state(::vsomeip::state_type_e _state);
                // void on_availability(::vsomeip::service_t _service, ::vsomeip::instance_t _instance, bool _is_available);
                // void on_message(const std::shared_ptr<::vsomeip::message> &_response);

                std::function<void(::vsomeip::service_t, ::vsomeip::instance_t, bool)> wrapper_availability_handler(ara::com::FindServiceHandler<HandleType> original_handler, const ara::com::InstanceIdentifier instanceIdentifier);

                std::shared_ptr< ::vsomeip::application > app_;
                bool use_tcp_;
                uint16_t mSampleCount;

                uint16_t mServiceId;
                uint16_t mInstanceId;
                uint16_t mEventId;
                uint16_t mEventGroupId;
        };
    }
}

#endif // VSOMEIP_CLIENT_H
