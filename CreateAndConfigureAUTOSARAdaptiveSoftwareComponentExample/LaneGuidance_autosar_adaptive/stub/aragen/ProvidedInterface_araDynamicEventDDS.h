#ifndef ProvidedInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#define ProvidedInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#include "AdaptiveAUTOSARDDSIdl.h"
#include "AdaptiveAUTOSARDDSIdlPubSubTypes.h"
namespace skeleton_io {
    class ProvidedInterface_LeftHazardIndicator_t final {
        public:
        eprosima_dds::ProvidedInterface_LeftHazardIndicator mEventData;
        eprosima_dds::ProvidedInterface_LeftHazardIndicatorPubSubType mEventDataType;
        ProvidedInterface_LeftHazardIndicator_t(): mEventData{}, mEventDataType{} {
            mEventDataType.setName("double");
        }
        ~ ProvidedInterface_LeftHazardIndicator_t() = default;
        ProvidedInterface_LeftHazardIndicator_t(const ProvidedInterface_LeftHazardIndicator_t&) = default;
        ProvidedInterface_LeftHazardIndicator_t& operator =(const ProvidedInterface_LeftHazardIndicator_t&) & = default;
        ProvidedInterface_LeftHazardIndicator_t(ProvidedInterface_LeftHazardIndicator_t&&) = default;
        ProvidedInterface_LeftHazardIndicator_t& operator =(ProvidedInterface_LeftHazardIndicator_t&&) & = default;
        void eventData( const double implValue) {
            mEventData.m_double(implValue);
        }
        double eventData() {
            return mEventData.m_double();
        }
    }; /* class ProvidedInterface_LeftHazardIndicator_t */
    class ProvidedInterface_RightHazardIndicator_t final {
        public:
        eprosima_dds::ProvidedInterface_RightHazardIndicator mEventData;
        eprosima_dds::ProvidedInterface_RightHazardIndicatorPubSubType mEventDataType;
        ProvidedInterface_RightHazardIndicator_t(): mEventData{}, mEventDataType{} {
            mEventDataType.setName("double");
        }
        ~ ProvidedInterface_RightHazardIndicator_t() = default;
        ProvidedInterface_RightHazardIndicator_t(const ProvidedInterface_RightHazardIndicator_t&) = default;
        ProvidedInterface_RightHazardIndicator_t& operator =(const ProvidedInterface_RightHazardIndicator_t&) & = default;
        ProvidedInterface_RightHazardIndicator_t(ProvidedInterface_RightHazardIndicator_t&&) = default;
        ProvidedInterface_RightHazardIndicator_t& operator =(ProvidedInterface_RightHazardIndicator_t&&) & = default;
        void eventData( const double implValue) {
            mEventData.m_double(implValue);
        }
        double eventData() {
            return mEventData.m_double();
        }
    }; /* class ProvidedInterface_RightHazardIndicator_t */
} /* namespace skeleton_io */
namespace skeleton_io {
} /* namespace skeleton_io */
#endif //RequiredInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
