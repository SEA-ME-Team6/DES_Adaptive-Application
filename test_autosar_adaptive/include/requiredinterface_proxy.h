/* This file contains ARA Function Cluster ara::com stub implementation.
   This implementation can be used to compile the generated code
   in Simulink. When deploying the generated code outside of Simulink,
   replace this file with an appropriate ARA file.

   Code generated for Simulink Adaptive model: "test"
   AUTOSAR AP Release: "20-11"
   On: "13-Feb-2024 13:02:26"  */

#ifndef REQUIREDINTERFACE_PROXY_H_
#define REQUIREDINTERFACE_PROXY_H_
#include <memory>
#include <utility>
#include "../ara/com/proxy_event.h"
#include "../ara/com/handle_type.h"
#include "../ara/com/instance_identifier.h"
#include "../ara/com/instance_identifier_container.h"
#include "../ara/com/service_handle_container.h"
#include "../ara/com/resolve_instance.h"

// #include "requiredinterface_common.h"

namespace proxy
{
  namespace events
  {
    using In1 = ara::com::ProxyEvent<double>;
  }                                    /* namespace events */

  namespace methods
  {
  }                                    /* namespace methods */

  namespace fields
  {
  }                                    /* namespace fields */

  class RequiredInterfaceProxy {
   private:
    ara::com::HandleType mHandle;

   public:
    using HandleType = ara::com::HandleType;
	  proxy::events::In1 In1;

    explicit RequiredInterfaceProxy(const HandleType& handle): mHandle(handle)
    {
      std::string sTopicName;
      sTopicName = "In1";
      In1.Init(handle, sTopicName);
    }
	
    RequiredInterfaceProxy(const RequiredInterfaceProxy&) = delete;
    RequiredInterfaceProxy& operator = (const RequiredInterfaceProxy&) = delete;
    RequiredInterfaceProxy(RequiredInterfaceProxy&&) = default;
    RequiredInterfaceProxy& operator = (RequiredInterfaceProxy&&) = default;

    virtual ~RequiredInterfaceProxy()
    {
    //   In1.Deinit();
    }

    
    static inline ara::core::Result<ara::com::ServiceHandleContainer<RequiredInterfaceProxy::HandleType>> 
    FindService(ara::com::InstanceIdentifier instance)
    {
      ara::com::ServiceHandleContainer<RequiredInterfaceProxy::HandleType>
        retResult;
      // Hane to replace FindService to register_availability_handler
      // retResult.push_back(ara::com::ServiceFactory::FindService(instance));
      return ara::core::Result<ara::com::ServiceHandleContainer<RequiredInterfaceProxy::HandleType>>{ retResult };
    }

    static inline ara::core::Result<ara::com::ServiceHandleContainer<
      RequiredInterfaceProxy::HandleType>> FindService(ara::core::
      InstanceSpecifier instanceSpec)
    {
      ara::com::ServiceHandleContainer<RequiredInterfaceProxy::HandleType>
        retResult;
      ara::core::Result<ara::com::InstanceIdentifierContainer> vecInstance (ara::com::runtime::ResolveInstanceIDs(instanceSpec));
      if (!vecInstance->empty()) {
        // *Replace FindService to register_availability_handler
        // retResult = FindService(vecInstance->front()).Value();
      } else {
        // retResult = FindService(ara::com::InstanceIdentifier::Any).Value();
      }                                /* if */

      return ara::core::Result<ara::com::ServiceHandleContainer<
        RequiredInterfaceProxy::HandleType>>{ retResult };
    }

    // static inline ara::core::Result<ara::com::FindServiceHandle>
    //   StartFindService(ara::com::FindServiceHandler<RequiredInterfaceProxy::
    //                    HandleType> handler, ara::com::InstanceIdentifier
    //                    instance = ara::com::InstanceIdentifier::Any)
    // {
    //   return ara::core::Result<ara::com::FindServiceHandle>{ ara::com::
    //     ServiceFactory::StartFindService(handler, instance) };
    // }

    // static inline ara::core::Result<ara::com::FindServiceHandle>
    //   StartFindService(ara::com::FindServiceHandler<RequiredInterfaceProxy::
    //                    HandleType> handler, ara::core::InstanceSpecifier
    //                    instanceSpec)
    // {
    //   ara::com::FindServiceHandle retHandle;
    //   ara::core::Result<ara::com::InstanceIdentifierContainer> vecInstance (ara::
    //     com::runtime::ResolveInstanceIDs(instanceSpec));
    //   if (!vecInstance->empty()) {
    //     retHandle = StartFindService(handler, vecInstance->front()).Value();
    //   } else {
    //     retHandle = StartFindService(handler, ara::com::InstanceIdentifier::Any)
    //       .Value();
    //   }                                /* if */

    //   return ara::core::Result<ara::com::FindServiceHandle>{ retHandle };
    // }

    // static inline void StopFindService(ara::com::FindServiceHandle handle)
    // {
    //   ara::com::ServiceFactory::StopFindService(handle);
    // }

    // RequiredInterfaceProxy::HandleType GetHandle() const
    // {
    //   return mHandle;
    // }

  };
}                                      /* namespace proxy */

#endif                                 // #ifndef REQUIREDINTERFACE_PROXY_H_
