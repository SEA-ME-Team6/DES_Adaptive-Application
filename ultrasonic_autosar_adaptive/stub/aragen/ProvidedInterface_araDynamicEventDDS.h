#ifndef ProvidedInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#define ProvidedInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#include "AdaptiveAUTOSARDDSIdl.h"
#include "AdaptiveAUTOSARDDSIdlPubSubTypes.h"
namespace skeleton_io {
    class ProvidedInterface_Brake_t final {
        public:
        eprosima_dds::ProvidedInterface_Brake mEventData;
        eprosima_dds::ProvidedInterface_BrakePubSubType mEventDataType;
        ProvidedInterface_Brake_t(): mEventData{}, mEventDataType{} {
            mEventDataType.setName("double");
        }
        ~ ProvidedInterface_Brake_t() = default;
        ProvidedInterface_Brake_t(const ProvidedInterface_Brake_t&) = default;
        ProvidedInterface_Brake_t& operator =(const ProvidedInterface_Brake_t&) & = default;
        ProvidedInterface_Brake_t(ProvidedInterface_Brake_t&&) = default;
        ProvidedInterface_Brake_t& operator =(ProvidedInterface_Brake_t&&) & = default;
        void eventData( const double implValue) {
            mEventData.m_double(implValue);
        }
        double eventData() {
            return mEventData.m_double();
        }
    }; /* class ProvidedInterface_Brake_t */
} /* namespace skeleton_io */
namespace skeleton_io {
} /* namespace skeleton_io */
#endif //ProvidedInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
