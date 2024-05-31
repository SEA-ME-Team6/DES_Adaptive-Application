#ifndef ProvidedInterface_ARA_COM_SOMEIP_DYNAMIC_EVENT_WRAPPER_H
#define ProvidedInterface_ARA_COM_SOMEIP_DYNAMIC_EVENT_WRAPPER_H
namespace skeleton_io {
    class ProvidedInterface_Steering_t final {
        public:
        std::string mEventData;
        ProvidedInterface_Steering_t() = default;
        ~ ProvidedInterface_Steering_t() = default;
        ProvidedInterface_Steering_t(const ProvidedInterface_Steering_t&) = default;
        ProvidedInterface_Steering_t& operator =(const ProvidedInterface_Steering_t&) & = default;
        ProvidedInterface_Steering_t(ProvidedInterface_Steering_t&&) = default;
        ProvidedInterface_Steering_t& operator =(ProvidedInterface_Steering_t&&) & = default;
        void eventData(double implValue) {
             mEventData = ara::com::_RtpsSerialize<double>{}(implValue);
        }
        double eventData() {
            return ara::com::_RtpsDeserialize<double>{}(0, mEventData);
        }
    }; /* class ProvidedInterface_Steering_t */
} /* namespace skeleton_io */
namespace skeleton_io {
} /* namespace skeleton_io */
#endif //RequiredInterface_ARA_COM_SOMEIP_DYNAMIC_EVENT_WRAPPER_H
