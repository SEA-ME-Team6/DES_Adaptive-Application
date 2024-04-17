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

namespace ara
{
    namespace com
    {
        class vsomeip_client {
            public:
                explicit vsomeip_client();
                bool init(const ara::com::ServiceHandleType& handle, const uint16_t EventId, const uint16_t EventGroupId);
                void start();
                void subscribe();
                void stop();

            private:
                void on_state(::vsomeip::state_type_e _state);
                void on_availability(::vsomeip::service_t _service, ::vsomeip::instance_t _instance, bool _is_available);
                void on_message(const std::shared_ptr<::vsomeip::message> &_response);

                std::shared_ptr< ::vsomeip::application > app_;
                bool use_tcp_;
                uint16_t mSampleCount;

                ara::com::InstanceIdentifier mInstanceIdentifier;

                uint16_t mServiceId;
                uint16_t mInstanceId;
                uint16_t mEventId;
                uint16_t mEventGroupId;
        };
    }
}

#endif // VSOMEIP_CLIENT_H
