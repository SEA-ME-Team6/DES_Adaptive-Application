#include "vsomeip_client.h"

namespace ara
{
    namespace com
    {
        vsomeip_client::vsomeip_client() : app_(::vsomeip::runtime::get()->create_application()) {
            if (!app_->init()) {
                std::cerr << "Couldn't initialize application" << std::endl;
            }
        }

        void vsomeip_client::start() {
            app_->start();
        }

        void vsomeip_client::set_service_id(const ara::com::InstanceIdentifier instanceIdentifier) {
            mInstanceIdentifier = instanceIdentifier;
            mServiceId = instanceIdentifier.GetInstanceId();
            mInstanceId = instanceIdentifier.GetInstanceId();
        }

        void vsomeip_client::set_event_id(const ::vsomeip::service_t EventId, const ::vsomeip::service_t EventGroupId) {
            mEventId = EventId;
            mEventGroupId = EventGroupId;
        }

        void vsomeip_client::register_availability_handler(std::function<void(ServiceHandleContainer<HandleType>, FindServiceHandle)> handler) {
            auto vsomeip_handler = wrapper_availability_handler(handler);
            app_->register_availability_handler(mServiceId, mInstanceId, vsomeip_handler);
        }

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

        // void vsomeip_client::on_availability(::vsomeip::service_t _service, ::vsomeip::instance_t _instance, bool _is_available) {
        //     std::cout << "Service ["
        //             << std::setw(4) << std::setfill('0') << std::hex << _service << "." << _instance
        //             << "] is "
        //             << (_is_available ? "available." : "NOT available.")
        //             << std::endl;
        // }

        // void vsomeip_client::on_message(const std::shared_ptr<::vsomeip::message> &_response) {
        //     std::stringstream its_message;
        //     its_message << "Received a notification for Event ["
        //             << std::setw(4)    << std::setfill('0') << std::hex
        //             << _response->get_service() << "."
        //             << std::setw(4) << std::setfill('0') << std::hex
        //             << _response->get_instance() << "."
        //             << std::setw(4) << std::setfill('0') << std::hex
        //             << _response->get_method() << "] to Client/Session ["
        //             << std::setw(4) << std::setfill('0') << std::hex
        //             << _response->get_client() << "/"
        //             << std::setw(4) << std::setfill('0') << std::hex
        //             << _response->get_session()
        //             << "] = ";
        //     std::shared_ptr<::vsomeip::payload> its_payload =
        //             _response->get_payload();
        //     its_message << "(" << std::dec << its_payload->get_length() << ") ";
        //     for (uint32_t i = 0; i < its_payload->get_length(); ++i)
        //         its_message << std::hex << std::setw(2) << std::setfill('0')
        //             << (int) its_payload->get_data()[i] << " ";
        //     std::cout << its_message.str() << std::endl;
        // }

        std::function<void(::vsomeip::service_t, ::vsomeip::instance_t, bool)> vsomeip_client::wrapper_availability_handler(ara::com::FindServiceHandler<HandleType> original_handler) {
            return [this, original_handler](::vsomeip::service_t service, ::vsomeip::instance_t instance, bool is_available) {
                if (is_available) {
                    ServiceHandleContainer<HandleType> container;

                    ara::com::ServiceHandleType service_handle(this->mInstanceIdentifier);
                    container.push_back(service_handle);

                    ara::com::FindServiceHandle handle(this->mServiceId, this->mInstanceId);

                    original_handler(container, handle);
                }
            };
        }

    }
}



