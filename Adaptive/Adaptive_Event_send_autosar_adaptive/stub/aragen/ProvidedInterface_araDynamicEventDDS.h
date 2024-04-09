#ifndef ProvidedInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#define ProvidedInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#include "AdaptiveAUTOSARDDSIdl.h"
#include "AdaptiveAUTOSARDDSIdlPubSubTypes.h"
namespace skeleton_io {
    class ProvidedInterface_Error_t final {
        public:
        eprosima_dds::ProvidedInterface_Error mEventData;
        eprosima_dds::ProvidedInterface_ErrorPubSubType mEventDataType;
        ProvidedInterface_Error_t(): mEventData{}, mEventDataType{} {
            mEventDataType.setName("double");
        }
        ~ ProvidedInterface_Error_t() = default;
        ProvidedInterface_Error_t(const ProvidedInterface_Error_t&) = default;
        ProvidedInterface_Error_t& operator =(const ProvidedInterface_Error_t&) & = default;
        ProvidedInterface_Error_t(ProvidedInterface_Error_t&&) = default;
        ProvidedInterface_Error_t& operator =(ProvidedInterface_Error_t&&) & = default;
        void eventData( const double implValue) {
            mEventData.m_double(implValue);
        }
        double eventData() {
            return mEventData.m_double();
        }
    }; /* class ProvidedInterface_Error_t */
} /* namespace skeleton_io */
namespace skeleton_io {
} /* namespace skeleton_io */
#endif //ProvidedInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
