#ifndef RequiredInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#define RequiredInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#include "AdaptiveAUTOSARDDSIdl.h"
#include "AdaptiveAUTOSARDDSIdlPubSubTypes.h"
namespace proxy_io {
    class RequiredInterface_In1_t final {
        public:
        eprosima_dds::RequiredInterface_In1 mEventData;
        eprosima_dds::RequiredInterface_In1PubSubType mEventDataType;
        RequiredInterface_In1_t(): mEventData{}, mEventDataType{} {
            mEventDataType.setName("double");
        }
        ~ RequiredInterface_In1_t() = default;
        RequiredInterface_In1_t(const RequiredInterface_In1_t&) = default;
        RequiredInterface_In1_t& operator =(const RequiredInterface_In1_t&) & = default;
        RequiredInterface_In1_t(RequiredInterface_In1_t&&) = default;
        RequiredInterface_In1_t& operator =(RequiredInterface_In1_t&&) & = default;
        void eventData( const double implValue) {
            mEventData.m_double(implValue);
        }
        double eventData() {
            return mEventData.m_double();
        }
    }; /* class RequiredInterface_In1_t */
} /* namespace proxy_io */
namespace proxy_io {
} /* namespace proxy_io */
#endif //RequiredInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
