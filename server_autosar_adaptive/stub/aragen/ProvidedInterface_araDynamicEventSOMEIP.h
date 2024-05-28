#ifndef ProvidedInterface_ARA_COM_SOMEIP_DYNAMIC_EVENT_WRAPPER_H
#define ProvidedInterface_ARA_COM_SOMEIP_DYNAMIC_EVENT_WRAPPER_H
namespace skeleton_io {
    class ProvidedInterface_Out1_t final {
        public:
        std::string mEventData;
        ProvidedInterface_Out1_t() = default;
        ~ ProvidedInterface_Out1_t() = default;
        ProvidedInterface_Out1_t(const ProvidedInterface_Out1_t&) = default;
        ProvidedInterface_Out1_t& operator =(const ProvidedInterface_Out1_t&) & = default;
        ProvidedInterface_Out1_t(ProvidedInterface_Out1_t&&) = default;
        ProvidedInterface_Out1_t& operator =(ProvidedInterface_Out1_t&&) & = default;
        void eventData(double implValue) {
             mEventData = ara::com::_RtpsSerialize<double>{}(implValue);
        }
        double eventData() {
            return ara::com::_RtpsDeserialize<double>{}(0, mEventData);
        }
    }; /* class ProvidedInterface_Out1_t */
} /* namespace skeleton_io */
namespace skeleton_io {
} /* namespace skeleton_io */
#endif //ProvidedInterface_ARA_COM_SOMEIP_DYNAMIC_EVENT_WRAPPER_H
