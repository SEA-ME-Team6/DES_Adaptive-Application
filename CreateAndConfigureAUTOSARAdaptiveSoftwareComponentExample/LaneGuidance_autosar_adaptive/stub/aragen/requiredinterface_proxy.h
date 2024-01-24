/* This file contains ARA Function Cluster ara::com stub implementation.
   This implementation can be used to compile the generated code
   in Simulink. When deploying the generated code outside of Simulink,
   replace this file with an appropriate ARA file.

   Code generated for Simulink Adaptive model: "LaneGuidance"
   AUTOSAR AP Release: "21-11"
   On: "24-Jan-2024 16:40:57"  */

#ifndef REQUIREDINTERFACE_PROXY_H_
#define REQUIREDINTERFACE_PROXY_H_
#include <memory>
#include <utility>
#include "requiredinterface_common.h"

namespace proxy
{
  namespace events
  {
    using LeftCarInBlindSpot = ara::com::ProxyEvent<double>;
    using LeftLaneDistance = ara::com::ProxyEvent<double>;
    using LeftTurnIndicator = ara::com::ProxyEvent<double>;
    using RightCarInBlindSpot = ara::com::ProxyEvent<double>;
    using RightLaneDistance = ara::com::ProxyEvent<double>;
    using RightTurnIndicator = ara::com::ProxyEvent<double>;
  }                                    /* namespace events */

  namespace methods
  {
  }                                    /* namespace methods */

  namespace fields
  {
  }                                    /* namespace fields */

  class RequiredInterfaceProxy {
   private:
    ara::com::ServiceHandleType mHandle;
   public:
    using HandleType = ara::com::ServiceHandleType;
    explicit RequiredInterfaceProxy(const HandleType& handle): mHandle(handle)
    {
      std::string sTopicName;
      sTopicName = "LeftCarInBlindSpot";
      LeftCarInBlindSpot.Init(ara::com::EventFactory::CreateProxyEvent<double,
        proxy_io::RequiredInterface_LeftCarInBlindSpot_t>(handle, sTopicName));
      sTopicName = "LeftLaneDistance";
      LeftLaneDistance.Init(ara::com::EventFactory::CreateProxyEvent<double,
                            proxy_io::RequiredInterface_LeftLaneDistance_t>
                            (handle, sTopicName));
      sTopicName = "LeftTurnIndicator";
      LeftTurnIndicator.Init(ara::com::EventFactory::CreateProxyEvent<double,
        proxy_io::RequiredInterface_LeftTurnIndicator_t>(handle, sTopicName));
      sTopicName = "RightCarInBlindSpot";
      RightCarInBlindSpot.Init(ara::com::EventFactory::CreateProxyEvent<double,
        proxy_io::RequiredInterface_RightCarInBlindSpot_t>(handle, sTopicName));
      sTopicName = "RightLaneDistance";
      RightLaneDistance.Init(ara::com::EventFactory::CreateProxyEvent<double,
        proxy_io::RequiredInterface_RightLaneDistance_t>(handle, sTopicName));
      sTopicName = "RightTurnIndicator";
      RightTurnIndicator.Init(ara::com::EventFactory::CreateProxyEvent<double,
        proxy_io::RequiredInterface_RightTurnIndicator_t>(handle, sTopicName));
    }

    virtual ~RequiredInterfaceProxy()
    {
      LeftCarInBlindSpot.Deinit();
      LeftLaneDistance.Deinit();
      LeftTurnIndicator.Deinit();
      RightCarInBlindSpot.Deinit();
      RightLaneDistance.Deinit();
      RightTurnIndicator.Deinit();
    }

    RequiredInterfaceProxy(const RequiredInterfaceProxy&) = delete;
    RequiredInterfaceProxy& operator = (const RequiredInterfaceProxy&) = delete;
    RequiredInterfaceProxy(RequiredInterfaceProxy&&) = default;
    RequiredInterfaceProxy& operator = (RequiredInterfaceProxy&&) = default;
    static inline ara::core::Result<ara::com::ServiceHandleContainer<
      RequiredInterfaceProxy::HandleType>> FindService(ara::com::
      InstanceIdentifier instance = ara::com::InstanceIdentifier::Any)
    {
      ara::com::ServiceHandleContainer<RequiredInterfaceProxy::HandleType>
        retResult;
      retResult.push_back(ara::com::ServiceFactory::FindService(instance));
      return ara::core::Result<ara::com::ServiceHandleContainer<
        RequiredInterfaceProxy::HandleType>>{ retResult };
    }

    static inline ara::core::Result<ara::com::ServiceHandleContainer<
      RequiredInterfaceProxy::HandleType>> FindService(ara::core::
      InstanceSpecifier instanceSpec)
    {
      ara::com::ServiceHandleContainer<RequiredInterfaceProxy::HandleType>
        retResult;
      ara::core::Result<ara::com::InstanceIdentifierContainer> vecInstance (ara::
        com::runtime::ResolveInstanceIDs(instanceSpec));
      if (!vecInstance->empty()) {
        retResult = FindService(vecInstance->front()).Value();
      } else {
        retResult = FindService(ara::com::InstanceIdentifier::Any).Value();
      }                                /* if */

      return ara::core::Result<ara::com::ServiceHandleContainer<
        RequiredInterfaceProxy::HandleType>>{ retResult };
    }

    static inline ara::core::Result<ara::com::FindServiceHandle>
      StartFindService(ara::com::FindServiceHandler<RequiredInterfaceProxy::
                       HandleType> handler, ara::com::InstanceIdentifier
                       instance = ara::com::InstanceIdentifier::Any)
    {
      return ara::core::Result<ara::com::FindServiceHandle>{ ara::com::
        ServiceFactory::StartFindService(handler, instance) };
    }

    static inline ara::core::Result<ara::com::FindServiceHandle>
      StartFindService(ara::com::FindServiceHandler<RequiredInterfaceProxy::
                       HandleType> handler, ara::core::InstanceSpecifier
                       instanceSpec)
    {
      ara::com::FindServiceHandle retHandle;
      ara::core::Result<ara::com::InstanceIdentifierContainer> vecInstance (ara::
        com::runtime::ResolveInstanceIDs(instanceSpec));
      if (!vecInstance->empty()) {
        retHandle = StartFindService(handler, vecInstance->front()).Value();
      } else {
        retHandle = StartFindService(handler, ara::com::InstanceIdentifier::Any)
          .Value();
      }                                /* if */

      return ara::core::Result<ara::com::FindServiceHandle>{ retHandle };
    }

    static inline void StopFindService(ara::com::FindServiceHandle handle)
    {
      ara::com::ServiceFactory::StopFindService(handle);
    }

    RequiredInterfaceProxy::HandleType GetHandle() const
    {
      return mHandle;
    }

    proxy::events::LeftCarInBlindSpot LeftCarInBlindSpot;
    proxy::events::LeftLaneDistance LeftLaneDistance;
    proxy::events::LeftTurnIndicator LeftTurnIndicator;
    proxy::events::RightCarInBlindSpot RightCarInBlindSpot;
    proxy::events::RightLaneDistance RightLaneDistance;
    proxy::events::RightTurnIndicator RightTurnIndicator;
  };
}                                      /* namespace proxy */

#endif                                 // #ifndef REQUIREDINTERFACE_PROXY_H_
