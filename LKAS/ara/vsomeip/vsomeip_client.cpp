#include "vsomeip_client.h"

namespace ara
{
    namespace com
    {
        namespace vsomeip
        {
            vsomeip_client::vsomeip_client(bool _use_tcp) : app_(vsomeip::runtime::get()->create_application()), use_tcp_(_use_tcp) {
            }

            bool vsomeip_client::init() {
                if (!app_->init()) {
                    std::cerr << "Couldn't initialize application" << std::endl;
                    return false;
                }
                std::cout << "Client settings [protocol="
                        << (use_tcp_ ? "TCP" : "UDP")
                        << "]"
                        << std::endl;

                app_->register_state_handler(
                        std::bind(&vsomeip_client::on_state, this,
                                std::placeholders::_1));

                app_->register_message_handler(
                        SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, vsomeip::ANY_METHOD,
                        std::bind(&vsomeip_client::on_message, this,
                                std::placeholders::_1));

                app_->register_availability_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID,
                        std::bind(&vsomeip_client::on_availability,
                                    this,
                                    std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

                std::set<vsomeip::eventgroup_t> its_groups;
                its_groups.insert(SAMPLE_EVENTGROUP_ID);
                app_->request_event(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_EVENT_ID, its_groups, vsomeip::event_type_e::ET_FIELD);
            }

            void vsomeip_client::start() {
                app_->start();
            }

            void vsomeip_client::subscribe() {
                app_->subscribe(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_EVENTGROUP_ID);
            }

            void vsomeip_client::stop() {
                app_->clear_all_handler();
                app_->unsubscribe(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_EVENTGROUP_ID);
                app_->release_event(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_EVENT_ID);
                app_->release_service(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID);
                app_->stop();
            }

            void vsomeip_client::on_state(vsomeip::state_type_e _state) {
                if (_state == vsomeip::state_type_e::ST_REGISTERED) {
                    app_->request_service(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID);
                }
            }

            void vsomeip_client::on_availability(vsomeip::service_t _service, vsomeip::instance_t _instance, bool _is_available) {
                std::cout << "Service ["
                        << std::setw(4) << std::setfill('0') << std::hex << _service << "." << _instance
                        << "] is "
                        << (_is_available ? "available." : "NOT available.")
                        << std::endl;
            }

            void vsomeip_client::on_message(const std::shared_ptr<vsomeip::message> &_response) {
                std::stringstream its_message;
                its_message << "Received a notification for Event ["
                        << std::setw(4)    << std::setfill('0') << std::hex
                        << _response->get_service() << "."
                        << std::setw(4) << std::setfill('0') << std::hex
                        << _response->get_instance() << "."
                        << std::setw(4) << std::setfill('0') << std::hex
                        << _response->get_method() << "] to Client/Session ["
                        << std::setw(4) << std::setfill('0') << std::hex
                        << _response->get_client() << "/"
                        << std::setw(4) << std::setfill('0') << std::hex
                        << _response->get_session()
                        << "] = ";
                std::shared_ptr<vsomeip::payload> its_payload =
                        _response->get_payload();
                its_message << "(" << std::dec << its_payload->get_length() << ") ";
                for (uint32_t i = 0; i < its_payload->get_length(); ++i)
                    its_message << std::hex << std::setw(2) << std::setfill('0')
                        << (int) its_payload->get_data()[i] << " ";
                std::cout << its_message.str() << std::endl;
            }

        }
    }
}



