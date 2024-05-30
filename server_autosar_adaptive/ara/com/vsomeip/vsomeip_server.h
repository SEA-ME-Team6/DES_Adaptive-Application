#ifndef VSOMEIP_SERVER_H
#define VSOMEIP_SERVER_H

#ifndef VSOMEIP_ENABLE_SIGNAL_HANDLING
#include <csignal>
#endif
#include <chrono>
#include <condition_variable>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>
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
        class vsomeip_server {
            public:
                static vsomeip_server& get_server();

                void init(const ara::com::ServiceHandleType& handle, const uint16_t& eventId, const uint16_t& eventGroupId);
                void start();
                void stop();

                void set_service_id(const ara::com::InstanceIdentifier& instanceIdentifier);
                void set_event_id(const ::vsomeip::service_t& eventId, const ::vsomeip::service_t& eventGroupId);

                void register_state_handler();
                void offer_event();
                void notify(const float &data);
            
            private:
                vsomeip_server();

                void run();
                void offer();
                void stop_offer();

                void on_state(vsomeip::state_type_e _state);
                
                std::shared_ptr<vsomeip::application> app_;
                bool is_registered_;

                std::mutex mutex_;
                std::condition_variable condition_;
                bool blocked_;
                bool running_;

                std::mutex notify_mutex_;
                bool is_offered_;

                std::mutex payload_mutex_;
                std::shared_ptr<vsomeip::payload> payload_;

                // blocked_ / is_offered_ must be initialized before starting the threads!
                std::thread offer_thread_;

                uint16_t serviceId_;
                uint16_t instanceId_;
                uint16_t eventId_;
                uint16_t eventGroupId_;
        };
    }
}

#endif
