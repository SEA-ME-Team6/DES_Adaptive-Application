#include "vsomeip_server.h"
#include <typeinfo>

namespace ara
{
    namespace com
    {
        vsomeip_server::vsomeip_server() :
                app_(vsomeip::runtime::get()->create_application()),
                is_registered_(false),
                blocked_(false),
                running_(true),
                is_offered_(false),
                offer_thread_(std::bind(&vsomeip_server::run, this)) {}

        vsomeip_server& vsomeip_server::get_server() {
            static vsomeip_server instance;
            return instance;          
        }

        void vsomeip_server::init(const ara::com::ServiceHandleType& handle, const uint16_t& eventId, const uint16_t& eventGroupId) {
            if (!app_->init()) {
                std::cerr << "Couldn't initialize application" << std::endl;
            }
            set_service_id(handle.GetInstanceId());
            set_event_id(eventId, eventGroupId);
        }

        void vsomeip_server::start() {
            app_->start();
        }

        void vsomeip_server::set_service_id(const ara::com::InstanceIdentifier& instanceIdentifier) {
            serviceId_ = instanceIdentifier.GetInstanceId();
            instanceId_ = instanceIdentifier.GetInstanceId();
        }

        void vsomeip_server::set_event_id(const ::vsomeip::service_t& eventId, const ::vsomeip::service_t& eventGroupId) {
            eventId_ = eventId;
            eventGroupId_ = eventGroupId;
        }

        void vsomeip_server::register_state_handler() {
            app_->register_state_handler(
                    std::bind(&vsomeip_server::on_state, this,
                            std::placeholders::_1));
        }

        void vsomeip_server::offer_event() {
            std::set<vsomeip::eventgroup_t> its_groups;
            its_groups.insert(eventGroupId_);
            app_->offer_event(
                    serviceId_,
                    instanceId_,
                    eventId_,
                    its_groups,
                    vsomeip::event_type_e::ET_FIELD, std::chrono::milliseconds::zero(),
                    false, true, nullptr, vsomeip::reliability_type_e::RT_UNKNOWN);
            {
                std::lock_guard<std::mutex> its_lock(payload_mutex_);
                payload_ = vsomeip::runtime::get()->create_payload();
            }

            blocked_ = true;
            condition_.notify_one();
        }

        void vsomeip_server::run() {
            std::unique_lock<std::mutex> its_lock(mutex_);
            while (!blocked_)
                condition_.wait(its_lock);

            bool is_offer(true);
            while (running_) {
                if (is_offer)
                    offer();
                else
                    stop_offer();

                for (int i = 0; i < 10 && running_; i++)
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

                is_offer = !is_offer;
            }
        }

        void vsomeip_server::offer() {
            std::lock_guard<std::mutex> its_lock(notify_mutex_);
            app_->offer_service(serviceId_, instanceId_);
            is_offered_ = true;
        }

        void vsomeip_server::notify(const float &data) {
            vsomeip::byte_t its_data[10];
            uint32_t its_size = 1;

            if (is_offered_ && running_) {
                if (its_size > sizeof(its_data))
                    its_size = sizeof(its_data);

                its_data[0] = data;

                payload_->set_data(its_data, its_size);

                std::cout << "Setting event (Length=" << std::dec << its_size << ")." << std::endl;
                app_->notify(serviceId_, instanceId_, eventId_, payload_);
            }
        }

        void vsomeip_server::stop() {
            running_ = false;
            blocked_ = true;
            condition_.notify_one();
            app_->clear_all_handler();
            stop_offer();
            if (std::this_thread::get_id() != offer_thread_.get_id()) {
                if (offer_thread_.joinable()) {
                    offer_thread_.join();
                }
            } else {
                offer_thread_.detach();
            }
            app_->stop();
        }
        
        void vsomeip_server::stop_offer() {
            app_->stop_offer_service(serviceId_, instanceId_);
            is_offered_ = false;
        }

        void vsomeip_server::on_state(vsomeip::state_type_e _state) {
            std::cout << "Application " << app_->get_name() << " is "
            << (_state == vsomeip::state_type_e::ST_REGISTERED ?
                    "registered." : "deregistered.") << std::endl;

            if (_state == vsomeip::state_type_e::ST_REGISTERED) {
                if (!is_registered_) {
                    is_registered_ = true;
                }
            } else {
                is_registered_ = false;
            }
        }
    }
}