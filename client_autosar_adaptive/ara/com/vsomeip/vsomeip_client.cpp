#include "vsomeip_client.h"
#include <typeinfo>

namespace ara
{
    namespace com
    {
        vsomeip_client::vsomeip_client() {}

        vsomeip_client& vsomeip_client::get_client() {
            static vsomeip_client instance;
            return instance;
        }

        void vsomeip_client::init(const ara::com::InstanceIdentifier instanceIdentifier) {
            app_ = ::vsomeip::runtime::get()->create_application(instanceIdentifier.ToString());
            if (!app_->init()) {
                std::cerr << "Couldn't initialize application" << std::endl;
            }
        }

        // std::shared_ptr< ::vsomeip::application > vsomeip_client::get_application(const ara::com::InstanceIdentifier instanceIdentifier) {
            
        // }

        void vsomeip_client::start() {
            app_->start();
        }

        void vsomeip_client::set_service_id(const ara::com::InstanceIdentifier instanceIdentifier) {
            mServiceId = instanceIdentifier.GetInstanceId();
            mInstanceId = instanceIdentifier.GetInstanceId();
        }

        void vsomeip_client::set_event_id(const ::vsomeip::service_t EventId, const ::vsomeip::service_t EventGroupId) {
            mEventId = EventId;
            mEventGroupId = EventGroupId;
        }

        void vsomeip_client::register_availability_handler() {
            app_->register_availability_handler(mServiceId, mInstanceId,
                std::bind(&vsomeip_client::on_availability,
                          this,
                          std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
        }

        void vsomeip_client::register_message_handler() {
            std::cout << mServiceId << " " << mInstanceId << " " << mEventId << std::endl;
            app_->register_message_handler(
                    mServiceId, mInstanceId, mEventId,
                    std::bind(&vsomeip_client::on_message, this,
                            std::placeholders::_1));
        }

        void vsomeip_client::request_event() {
            std::set<vsomeip::eventgroup_t> its_groups;
            its_groups.insert(mEventGroupId);
            app_->request_event(
                    mServiceId,
                    mServiceId,
                    mEventId,
                    its_groups,
                    vsomeip::event_type_e::ET_FIELD);
        }

        void vsomeip_client::register_availability_observer(std::function<void(bool)> observer) {
            availability_observer_ = observer;
        }
    
        // void vsomeip_client::register_on_message_observer(std::function<void(const std::shared_ptr<::vsomeip::message>&)> observer) {
        //     on_message_observer_ = observer;
        // }

        void vsomeip_client::subscribe() {
            app_->subscribe(mServiceId, mInstanceId, mEventGroupId);
        }

        void vsomeip_client::stop() {
            app_->clear_all_handler();
            app_->unsubscribe(mServiceId, mInstanceId, mEventGroupId);
            app_->release_event(mServiceId, mInstanceId, mEventId);
            app_->release_service(mServiceId, mInstanceId);
            app_->stop();
        }

        // void vsomeip_client::on_state(::vsomeip::state_type_e _state) {
        //     if (_state == ::vsomeip::state_type_e::ST_REGISTERED) {
        //         app_->request_service(mServiceId, mInstanceId);
        //     }
        // }

        // Triggered when availability changes.
        void vsomeip_client::on_availability(::vsomeip::service_t _service, ::vsomeip::instance_t _instance, bool _is_available) {
            std::cout << "Service [" << std::hex << _service << "." << _instance << "] is "
                        << (_is_available ? "available." : "NOT available.") << std::endl;

            // Call the registered observer, if available.
            if (_is_available) {
                availability_observer_(_is_available);
            }
        }

        void vsomeip_client::on_message(const std::shared_ptr<::vsomeip::message> &_response) {
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
            std::shared_ptr<::vsomeip::payload> its_payload =
                    _response->get_payload();
            // its_message << "(" << std::dec << its_payload->get_length() << ") ";
            // for (uint32_t i = 0; i < its_payload->get_length(); ++i)
            //     its_message << std::hex << std::setw(2) << std::setfill('0')
            //         << (int) its_payload->get_data()[i] << " ";

            // std::cout << its_message.str() << std::endl;

            message_buffer.push(its_payload->get_data()[its_payload->get_length() - 1]);

        }

        ::vsomeip::byte_t vsomeip_client::get_samples() {
            ::vsomeip::byte_t samples = message_buffer.front();
            message_buffer.pop();
            return samples;        
        }

    }    
}



