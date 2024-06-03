/* This file contains ARA Function Cluster ara::com stub implementation.
   This implementation can be used to compile the generated code
   in Simulink. When deploying the generated code outside of Simulink,
   replace this file with an appropriate ARA file.

   Code generated for Simulink Adaptive model: "control"
   AUTOSAR AP Release: "21-11"
   On: "Mon Jun 03 22:36:11 2024"  */

#ifndef REQUIREDINTERFACE_PROXY_H_
#define REQUIREDINTERFACE_PROXY_H_
#include <memory>
#include <utility>
#include "requiredinterface_common.h"

namespace proxy
{
  namespace events
  {
    using AEB = ara::com::ProxyEvent<double>;
    using LKAS = ara::com::ProxyEvent<double>;
  }                                    /* namespace events */

  namespace fields
  {
  }                                    /* namespace fields */

  namespace methods
  {
  }                                    /* namespace methods */

  class RequiredInterfaceProxy {
   private:
    ara::com::ServiceHandleType mHandle;
   public:
    using HandleType = ara::com::ServiceHandleType;
    explicit RequiredInterfaceProxy(const HandleType& handle): mHandle(handle)
    {
      uint16_t mEventId, mEventGroupId;
      uint32_t queueLength{ 1 };

      mEventId = 61864;
      mEventGroupId = 62419;
      AEB.Init(ara::com::EventFactory::CreateProxyEvent<double, proxy_io::
               RequiredInterface_AEB_t>(handle, mEventId, mEventGroupId));
      mEventId = 14859;
      mEventGroupId = 62419;
      LKAS.Init(ara::com::EventFactory::CreateProxyEvent<double, proxy_io::
                RequiredInterface_LKAS_t>(handle, mEventId, mEventGroupId));
    }

    virtual ~RequiredInterfaceProxy()
    {
      AEB.Deinit();
      LKAS.Deinit();
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
      const ara::core::Result<ara::com::InstanceIdentifierContainer> vecInstance
      { ara::com::runtime::ResolveInstanceIDs(instanceSpec) };

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
      const ara::core::Result<ara::com::InstanceIdentifierContainer> vecInstance
      { ara::com::runtime::ResolveInstanceIDs(instanceSpec) };

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

    proxy::events::AEB AEB;
    proxy::events::LKAS LKAS;
  };
}                                      /* namespace proxy */

#endif                                 // #ifndef REQUIREDINTERFACE_PROXY_H_
