#ifndef RequiredInterface_ARA_COM_SOMEIP_DYNAMIC_EVENT_WRAPPER_H
#define RequiredInterface_ARA_COM_SOMEIP_DYNAMIC_EVENT_WRAPPER_H
namespace proxy_io {
    class RequiredInterface_In1_t final {
        public:
        std::string mEventData;
        RequiredInterface_In1_t() = default;
        ~ RequiredInterface_In1_t() = default;
        RequiredInterface_In1_t(const RequiredInterface_In1_t&) = default;
        RequiredInterface_In1_t& operator =(const RequiredInterface_In1_t&) & = default;
        RequiredInterface_In1_t(RequiredInterface_In1_t&&) = default;
        RequiredInterface_In1_t& operator =(RequiredInterface_In1_t&&) & = default;
        void eventData(double implValue) {
             mEventData = ara::com::_RtpsSerialize<double>{}(implValue);
        }
        double eventData() {
            return ara::com::_RtpsDeserialize<double>{}(0, mEventData);
        }
    }; /* class RequiredInterface_In1_t */
} /* namespace proxy_io */
namespace proxy_io {
} /* namespace proxy_io */
#endif //RequiredInterface_ARA_COM_SOMEIP_DYNAMIC_EVENT_WRAPPER_H
