/* This file contains ARA Function Cluster ara::com stub implementation.
   This implementation can be used to compile the generated code
   in Simulink. When deploying the generated code outside of Simulink,
   replace this file with an appropriate ARA file.

   Code generated for Simulink Adaptive model: "server"
   AUTOSAR AP Release: "22-11"
   On: "Tue May 28 15:29:48 2024"  */

#ifndef PROVIDEDINTERFACE_SKELETON_H_
#define PROVIDEDINTERFACE_SKELETON_H_
#include <memory>
#include "ara/com/skeleton_event.h"
#include "ara/com/method_call_proccessing_mode.h"
#include "ara/com/instance_identifier.h"
#include "ara/com/instance_identifier_container.h"
#include "ara/com/resolve_instance.h"
#include "ara/com/handle_type.h"
// #include "providedinterface_common.h"

namespace skeleton
{
  namespace events
  {
    using Out1 = ara::com::SkeletonEvent<double>;
  }                                    /* namespace events */

  namespace methods
  {
  }                                    /* namespace methods */

  namespace fields
  {
  }                                    /* namespace fields */

  class ProvidedInterfaceSkeleton {
   public:
    ProvidedInterfaceSkeleton(ara::com::InstanceIdentifier instance, ara::com::
      MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent):
      mHndl(instance), mMethodProcMode(mode)
    {
    }

    ProvidedInterfaceSkeleton(ara::core::InstanceSpecifier instanceSpec, ara::
      com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::
      kEvent): mMethodProcMode(mode)
    {
      const ara::core::Result<ara::com::InstanceIdentifierContainer> vecInstance
        { ara::com::runtime::ResolveInstanceIDs(instanceSpec) };

      if (!vecInstance->empty()) {
        mHndl.mInstanceID = vecInstance->front();
      }                                /* if */
    }

    virtual ~ProvidedInterfaceSkeleton()
    {
      // StopOfferService();
    }

    ProvidedInterfaceSkeleton(const ProvidedInterfaceSkeleton&) = delete;
    ProvidedInterfaceSkeleton& operator = (const ProvidedInterfaceSkeleton&) =
      delete;
    ProvidedInterfaceSkeleton(ProvidedInterfaceSkeleton&& sklObj) = default;
    ProvidedInterfaceSkeleton& operator = (ProvidedInterfaceSkeleton&& sklObj) =
      default;
    inline ara::core::Result<void> OfferService()
    {
      // ara::com::ServiceFactory::CreateService(mHndl);
      uint16_t mEventId, mEventGroupId;
      uint16_t mMethodId;
      mEventId = 46921;
      mEventGroupId = 46921;
      Out1.Init(mHndl, mEventId, mEventGroupId);
      return ara::core::Result<void>::FromValue();
    }

    inline void StopOfferService()
    {
      Out1.Deinit();
      // ara::com::ServiceFactory::DestroyService(mHndl);
    }

    skeleton::events::Out1 Out1;
   private:
    ara::com::ServiceHandleType mHndl;
    ara::com::MethodCallProcessingMode mMethodProcMode;
    // std::shared_ptr<ara::com::SkeletonMethodMiddlewareBase> mMethodMiddleware;
  };
}                                      /* namespace skeleton */

#endif                                 //#ifndef PROVIDEDINTERFACE_SKELETON_H_
