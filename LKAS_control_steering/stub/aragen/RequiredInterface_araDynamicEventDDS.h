#ifndef RequiredInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#define RequiredInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#include "AdaptiveAUTOSARDDSIdl.h"
#include "AdaptiveAUTOSARDDSIdlPubSubTypes.h"
namespace proxy_io {
    class RequiredInterface_LKAS_t final {
        public:
        eprosima_dds::RequiredInterface_LKAS mEventData;
        eprosima_dds::RequiredInterface_LKASPubSubType mEventDataType;
        RequiredInterface_LKAS_t(): mEventData{}, mEventDataType{} {
            mEventDataType.setName("double");
        }
        ~ RequiredInterface_LKAS_t() = default;
        RequiredInterface_LKAS_t(const RequiredInterface_LKAS_t&) = default;
        RequiredInterface_LKAS_t& operator =(const RequiredInterface_LKAS_t&) & = default;
        RequiredInterface_LKAS_t(RequiredInterface_LKAS_t&&) = default;
        RequiredInterface_LKAS_t& operator =(RequiredInterface_LKAS_t&&) & = default;
        void eventData( const double implValue) {
            mEventData.m_double(implValue);
        }
        double eventData() {
            return mEventData.m_double();
        }
    }; /* class RequiredInterface_LKAS_t */
} /* namespace proxy_io */
namespace proxy_io {
} /* namespace proxy_io */
#endif //RequiredInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
