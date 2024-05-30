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

        void vsomeip_client::start() {
            std::cout << "Start called from thread: " << std::this_thread::get_id() << std::endl;
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

        void vsomeip_client::register_state_handler() {
            app_->register_state_handler(
                    std::bind(&vsomeip_client::on_state, this,
                            std::placeholders::_1));
        }

        void vsomeip_client::register_availability_handler() {
            app_->register_availability_handler(mServiceId, mInstanceId,
                std::bind(&vsomeip_client::on_availability,
                          this,
                          std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
        }

        void vsomeip_client::register_message_handler() {
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

        void vsomeip_client::subscribe() {
            app_->subscribe(mServiceId, mInstanceId, mEventGroupId);
        }

        void vsomeip_client::stop() {
            // app_->clear_all_handler();
            // app_->unsubscribe(mServiceId, mInstanceId, mEventGroupId);
            // app_->release_event(mServiceId, mInstanceId, mEventId);
            // app_->release_service(mServiceId, mInstanceId);
            app_->unregister_availability_handler(mServiceId, mInstanceId);
            app_->stop();
        }

        void vsomeip_client::on_state(::vsomeip::state_type_e _state) {
            if (_state == ::vsomeip::state_type_e::ST_REGISTERED) {
                app_->request_service(mServiceId, mInstanceId);
            }
        }

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
            std::shared_ptr<::vsomeip::payload> its_payload =
                    _response->get_payload();
            std::unique_lock<std::mutex> lock(mutex_);
            message_buffer.push(static_cast<float>(its_payload->get_data()[0]));
        }

        float vsomeip_client::get_samples() {
            std::unique_lock<std::mutex> lock(mutex_);
            if (!message_buffer.empty()) {
                last_sample = message_buffer.front();
                message_buffer.pop();
            }
            return last_sample;     
        }
    }    
}



