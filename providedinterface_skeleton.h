/* This file contains ARA Function Cluster ara::com stub implementation.
   This implementation can be used to compile the generated code
   in Simulink. When deploying the generated code outside of Simulink,
   replace this file with an appropriate ARA file.

   Code generated for Simulink Adaptive model: "last"
   AUTOSAR AP Release: "22-11"
   On: "Fri Apr 12 15:18:50 2024"  */

#ifndef PROVIDEDINTERFACE_SKELETON_H_
#define PROVIDEDINTERFACE_SKELETON_H_
#include <memory>
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
      StopOfferService();
    }

    ProvidedInterfaceSkeleton(const ProvidedInterfaceSkeleton&) = delete;
    ProvidedInterfaceSkeleton& operator = (const ProvidedInterfaceSkeleton&) =
      delete;
    ProvidedInterfaceSkeleton(ProvidedInterfaceSkeleton&& sklObj) = default;
    ProvidedInterfaceSkeleton& operator = (ProvidedInterfaceSkeleton&& sklObj) =
      default;
    inline ara::core::Result<void> OfferService()
    {
      ara::com::ServiceFactory::CreateService(mHndl);
      uint16_t mEventId, mEventGroupId;
      uint16_t mMethodId;
      mEventId = 46921;
      mEventGroupId = 46921;
      Out1.Init(ara::com::EventFactory::CreateSkeletonEvent<double, skeleton_io::
                ProvidedInterface_Out1_t>(mHndl, mEventId, mEventGroupId));
      return ara::core::Result<void>::FromValue();
    }

    inline void StopOfferService()
    {
      Out1.Deinit();
      ara::com::ServiceFactory::DestroyService(mHndl);
    }

    skeleton::events::Out1 Out1;
   private:
    ara::com::ServiceHandleType mHndl;
    ara::com::MethodCallProcessingMode mMethodProcMode;
    std::shared_ptr<ara::com::SkeletonMethodMiddlewareBase> mMethodMiddleware;
  };
}                                      /* namespace skeleton */

#endif                                 //#ifndef PROVIDEDINTERFACE_SKELETON_H_
