#ifndef ProvidedInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#define ProvidedInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#include "AdaptiveAUTOSARDDSIdl.h"
#include "AdaptiveAUTOSARDDSIdlPubSubTypes.h"
namespace skeleton_io {
    class ProvidedInterface_Out1_t final {
        public:
        eprosima_dds::ProvidedInterface_Out1 mEventData;
        eprosima_dds::ProvidedInterface_Out1PubSubType mEventDataType;
        ProvidedInterface_Out1_t(): mEventData{}, mEventDataType{} {
            mEventDataType.setName("double");
        }
        ~ ProvidedInterface_Out1_t() = default;
        ProvidedInterface_Out1_t(const ProvidedInterface_Out1_t&) = default;
        ProvidedInterface_Out1_t& operator =(const ProvidedInterface_Out1_t&) & = default;
        ProvidedInterface_Out1_t(ProvidedInterface_Out1_t&&) = default;
        ProvidedInterface_Out1_t& operator =(ProvidedInterface_Out1_t&&) & = default;
        void eventData( const double implValue) {
            mEventData.m_double(implValue);
        }
        double eventData() {
            return mEventData.m_double();
        }
    }; /* class ProvidedInterface_Out1_t */
} /* namespace skeleton_io */
namespace skeleton_io {
} /* namespace skeleton_io */
#endif //ProvidedInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
