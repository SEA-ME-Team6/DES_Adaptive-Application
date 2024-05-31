#ifndef ProvidedInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#define ProvidedInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#include "AdaptiveAUTOSARDDSIdl.h"
#include "AdaptiveAUTOSARDDSIdlPubSubTypes.h"
namespace skeleton_io {
    class ProvidedInterface_Steering_t final {
        public:
        eprosima_dds::ProvidedInterface_Steering mEventData;
        eprosima_dds::ProvidedInterface_SteeringPubSubType mEventDataType;
        ProvidedInterface_Steering_t(): mEventData{}, mEventDataType{} {
            mEventDataType.setName("double");
        }
        ~ ProvidedInterface_Steering_t() = default;
        ProvidedInterface_Steering_t(const ProvidedInterface_Steering_t&) = default;
        ProvidedInterface_Steering_t& operator =(const ProvidedInterface_Steering_t&) & = default;
        ProvidedInterface_Steering_t(ProvidedInterface_Steering_t&&) = default;
        ProvidedInterface_Steering_t& operator =(ProvidedInterface_Steering_t&&) & = default;
        void eventData( const double implValue) {
            mEventData.m_double(implValue);
        }
        double eventData() {
            return mEventData.m_double();
        }
    }; /* class ProvidedInterface_Steering_t */
} /* namespace skeleton_io */
namespace skeleton_io {
} /* namespace skeleton_io */
#endif //RequiredInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
