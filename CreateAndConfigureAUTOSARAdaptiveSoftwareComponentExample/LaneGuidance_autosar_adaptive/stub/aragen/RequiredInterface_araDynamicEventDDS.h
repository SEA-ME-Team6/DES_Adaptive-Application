#ifndef RequiredInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#define RequiredInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
#include "AdaptiveAUTOSARDDSIdl.h"
#include "AdaptiveAUTOSARDDSIdlPubSubTypes.h"
namespace proxy_io {
    class RequiredInterface_LeftCarInBlindSpot_t final {
        public:
        eprosima_dds::RequiredInterface_LeftCarInBlindSpot mEventData;
        eprosima_dds::RequiredInterface_LeftCarInBlindSpotPubSubType mEventDataType;
        RequiredInterface_LeftCarInBlindSpot_t(): mEventData{}, mEventDataType{} {
            mEventDataType.setName("double");
        }
        ~ RequiredInterface_LeftCarInBlindSpot_t() = default;
        RequiredInterface_LeftCarInBlindSpot_t(const RequiredInterface_LeftCarInBlindSpot_t&) = default;
        RequiredInterface_LeftCarInBlindSpot_t& operator =(const RequiredInterface_LeftCarInBlindSpot_t&) & = default;
        RequiredInterface_LeftCarInBlindSpot_t(RequiredInterface_LeftCarInBlindSpot_t&&) = default;
        RequiredInterface_LeftCarInBlindSpot_t& operator =(RequiredInterface_LeftCarInBlindSpot_t&&) & = default;
        void eventData( const double implValue) {
            mEventData.m_double(implValue);
        }
        double eventData() {
            return mEventData.m_double();
        }
    }; /* class RequiredInterface_LeftCarInBlindSpot_t */
    class RequiredInterface_LeftLaneDistance_t final {
        public:
        eprosima_dds::RequiredInterface_LeftLaneDistance mEventData;
        eprosima_dds::RequiredInterface_LeftLaneDistancePubSubType mEventDataType;
        RequiredInterface_LeftLaneDistance_t(): mEventData{}, mEventDataType{} {
            mEventDataType.setName("double");
        }
        ~ RequiredInterface_LeftLaneDistance_t() = default;
        RequiredInterface_LeftLaneDistance_t(const RequiredInterface_LeftLaneDistance_t&) = default;
        RequiredInterface_LeftLaneDistance_t& operator =(const RequiredInterface_LeftLaneDistance_t&) & = default;
        RequiredInterface_LeftLaneDistance_t(RequiredInterface_LeftLaneDistance_t&&) = default;
        RequiredInterface_LeftLaneDistance_t& operator =(RequiredInterface_LeftLaneDistance_t&&) & = default;
        void eventData( const double implValue) {
            mEventData.m_double(implValue);
        }
        double eventData() {
            return mEventData.m_double();
        }
    }; /* class RequiredInterface_LeftLaneDistance_t */
    class RequiredInterface_LeftTurnIndicator_t final {
        public:
        eprosima_dds::RequiredInterface_LeftTurnIndicator mEventData;
        eprosima_dds::RequiredInterface_LeftTurnIndicatorPubSubType mEventDataType;
        RequiredInterface_LeftTurnIndicator_t(): mEventData{}, mEventDataType{} {
            mEventDataType.setName("double");
        }
        ~ RequiredInterface_LeftTurnIndicator_t() = default;
        RequiredInterface_LeftTurnIndicator_t(const RequiredInterface_LeftTurnIndicator_t&) = default;
        RequiredInterface_LeftTurnIndicator_t& operator =(const RequiredInterface_LeftTurnIndicator_t&) & = default;
        RequiredInterface_LeftTurnIndicator_t(RequiredInterface_LeftTurnIndicator_t&&) = default;
        RequiredInterface_LeftTurnIndicator_t& operator =(RequiredInterface_LeftTurnIndicator_t&&) & = default;
        void eventData( const double implValue) {
            mEventData.m_double(implValue);
        }
        double eventData() {
            return mEventData.m_double();
        }
    }; /* class RequiredInterface_LeftTurnIndicator_t */
    class RequiredInterface_RightCarInBlindSpot_t final {
        public:
        eprosima_dds::RequiredInterface_RightCarInBlindSpot mEventData;
        eprosima_dds::RequiredInterface_RightCarInBlindSpotPubSubType mEventDataType;
        RequiredInterface_RightCarInBlindSpot_t(): mEventData{}, mEventDataType{} {
            mEventDataType.setName("double");
        }
        ~ RequiredInterface_RightCarInBlindSpot_t() = default;
        RequiredInterface_RightCarInBlindSpot_t(const RequiredInterface_RightCarInBlindSpot_t&) = default;
        RequiredInterface_RightCarInBlindSpot_t& operator =(const RequiredInterface_RightCarInBlindSpot_t&) & = default;
        RequiredInterface_RightCarInBlindSpot_t(RequiredInterface_RightCarInBlindSpot_t&&) = default;
        RequiredInterface_RightCarInBlindSpot_t& operator =(RequiredInterface_RightCarInBlindSpot_t&&) & = default;
        void eventData( const double implValue) {
            mEventData.m_double(implValue);
        }
        double eventData() {
            return mEventData.m_double();
        }
    }; /* class RequiredInterface_RightCarInBlindSpot_t */
    class RequiredInterface_RightLaneDistance_t final {
        public:
        eprosima_dds::RequiredInterface_RightLaneDistance mEventData;
        eprosima_dds::RequiredInterface_RightLaneDistancePubSubType mEventDataType;
        RequiredInterface_RightLaneDistance_t(): mEventData{}, mEventDataType{} {
            mEventDataType.setName("double");
        }
        ~ RequiredInterface_RightLaneDistance_t() = default;
        RequiredInterface_RightLaneDistance_t(const RequiredInterface_RightLaneDistance_t&) = default;
        RequiredInterface_RightLaneDistance_t& operator =(const RequiredInterface_RightLaneDistance_t&) & = default;
        RequiredInterface_RightLaneDistance_t(RequiredInterface_RightLaneDistance_t&&) = default;
        RequiredInterface_RightLaneDistance_t& operator =(RequiredInterface_RightLaneDistance_t&&) & = default;
        void eventData( const double implValue) {
            mEventData.m_double(implValue);
        }
        double eventData() {
            return mEventData.m_double();
        }
    }; /* class RequiredInterface_RightLaneDistance_t */
    class RequiredInterface_RightTurnIndicator_t final {
        public:
        eprosima_dds::RequiredInterface_RightTurnIndicator mEventData;
        eprosima_dds::RequiredInterface_RightTurnIndicatorPubSubType mEventDataType;
        RequiredInterface_RightTurnIndicator_t(): mEventData{}, mEventDataType{} {
            mEventDataType.setName("double");
        }
        ~ RequiredInterface_RightTurnIndicator_t() = default;
        RequiredInterface_RightTurnIndicator_t(const RequiredInterface_RightTurnIndicator_t&) = default;
        RequiredInterface_RightTurnIndicator_t& operator =(const RequiredInterface_RightTurnIndicator_t&) & = default;
        RequiredInterface_RightTurnIndicator_t(RequiredInterface_RightTurnIndicator_t&&) = default;
        RequiredInterface_RightTurnIndicator_t& operator =(RequiredInterface_RightTurnIndicator_t&&) & = default;
        void eventData( const double implValue) {
            mEventData.m_double(implValue);
        }
        double eventData() {
            return mEventData.m_double();
        }
    }; /* class RequiredInterface_RightTurnIndicator_t */
} /* namespace proxy_io */
namespace proxy_io {
} /* namespace proxy_io */
#endif //RequiredInterface_ARA_COM_DDS_DYNAMIC_EVENT_WRAPPER_H
