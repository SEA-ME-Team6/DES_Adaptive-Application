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

#include <vsomeip/vsomeip.hpp>

namespace ara
{
    namespace com
    {
        namespace vsomeip
        {
            class vsomeip_client {
                public:
                    explicit vsomeip_client(bool _use_tcp);
                    bool init();
                    void start();
                    void subscribe();
                    void stop();

                private:
                    void on_state(vsomeip::state_type_e _state);
                    void on_availability(vsomeip::service_t _service, vsomeip::instance_t _instance, bool _is_available);
                    void on_message(const std::shared_ptr<vsomeip::message> &_response);

                    std::shared_ptr<vsomeip::application> app_;
                    bool use_tcp_;
            };
        }
    }
}

#endif // VSOMEIP_CLIENT_H
