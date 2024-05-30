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
#include <functional>
#include <queue>
#include <mutex>

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
        class vsomeip_client {
            public:
                static vsomeip_client& get_client();

                void init(const ara::com::InstanceIdentifier& instanceIdentifier);
                void start();

                void set_service_id(const ara::com::InstanceIdentifier& instanceIdentifier);
                void set_event_id(const ::vsomeip::service_t& eventId, const ::vsomeip::service_t& eventGroupId); 
                
                void register_state_handler();
                void register_availability_handler();
                void register_message_handler();
                void register_availability_observer(std::function<void(bool)> observer);
                void unregister_availability_handler(const uint16_t& serviceId, const uint16_t& instanceId);

                void request_event();
                void subscribe();
                void stop();

                std::function<void(bool)> availability_observer_;
                std::function<void(const std::shared_ptr<::vsomeip::message>&)> on_message_observer_;

                float get_samples();
            
            private:
                vsomeip_client();

                void on_state(::vsomeip::state_type_e _state);
                void on_availability(::vsomeip::service_t _service, ::vsomeip::instance_t _instance, bool _is_available);
                void on_message(const std::shared_ptr<::vsomeip::message> &_response);

                std::shared_ptr< ::vsomeip::application > app_;
                
                std::queue<float> message_buffer_;
                float last_sample_;

                std::mutex mutex_;

                uint16_t serviceId_;
                uint16_t instanceId_;
                uint16_t eventId_;
                uint16_t eventGroupId_;

        };
    }
}

#endif // VSOMEIP_CLIENT_H
