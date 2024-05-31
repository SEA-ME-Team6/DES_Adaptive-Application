#ifndef RequiredInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#define RequiredInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#include "AdaptiveAUTOSARDDSIdl.h"
#include "AdaptiveAUTOSARDDSIdlPubSubTypes.h"
namespace proxy_io {
    class RequiredInterface_AEB_t final {
        public:
        eprosima_dds::RequiredInterface_AEB mEventData;
        eprosima_dds::RequiredInterface_AEBPubSubType mEventDataType;
        RequiredInterface_AEB_t(): mEventData{}, mEventDataType{} {
            mEventDataType.setName("double");
        }
        ~ RequiredInterface_AEB_t() = default;
        RequiredInterface_AEB_t(const RequiredInterface_AEB_t&) = default;
        RequiredInterface_AEB_t& operator =(const RequiredInterface_AEB_t&) & = default;
        RequiredInterface_AEB_t(RequiredInterface_AEB_t&&) = default;
        RequiredInterface_AEB_t& operator =(RequiredInterface_AEB_t&&) & = default;
        void eventData( const double implValue) {
            mEventData.m_double(implValue);
        }
        double eventData() {
            return mEventData.m_double();
        }
    }; /* class RequiredInterface_AEB_t */
} /* namespace proxy_io */
namespace proxy_io {
} /* namespace proxy_io */
#endif //RequiredInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
