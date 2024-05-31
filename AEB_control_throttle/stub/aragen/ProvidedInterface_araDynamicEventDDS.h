#ifndef ProvidedInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#define ProvidedInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#include "AdaptiveAUTOSARDDSIdl.h"
#include "AdaptiveAUTOSARDDSIdlPubSubTypes.h"
namespace skeleton_io {
    class ProvidedInterface_Throttle_t final {
        public:
        eprosima_dds::ProvidedInterface_Throttle mEventData;
        eprosima_dds::ProvidedInterface_ThrottlePubSubType mEventDataType;
        ProvidedInterface_Throttle_t(): mEventData{}, mEventDataType{} {
            mEventDataType.setName("double");
        }
        ~ ProvidedInterface_Throttle_t() = default;
        ProvidedInterface_Throttle_t(const ProvidedInterface_Throttle_t&) = default;
        ProvidedInterface_Throttle_t& operator =(const ProvidedInterface_Throttle_t&) & = default;
        ProvidedInterface_Throttle_t(ProvidedInterface_Throttle_t&&) = default;
        ProvidedInterface_Throttle_t& operator =(ProvidedInterface_Throttle_t&&) & = default;
        void eventData( const double implValue) {
            mEventData.m_double(implValue);
        }
        double eventData() {
            return mEventData.m_double();
        }
    }; /* class ProvidedInterface_Throttle_t */
} /* namespace skeleton_io */
namespace skeleton_io {
} /* namespace skeleton_io */
#endif //RequiredInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
