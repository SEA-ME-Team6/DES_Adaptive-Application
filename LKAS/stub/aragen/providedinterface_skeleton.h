/* This file contains ARA Function Cluster ara::com stub implementation.
   This implementation can be used to compile the generated code
   in Simulink. When deploying the generated code outside of Simulink,
   replace this file with an appropriate ARA file.

   Code generated for Simulink Adaptive model: "Rpi_cam"
   AUTOSAR AP Release: "21-11"
   On: "31-May-2024 12:10:05"  */

#ifndef PROVIDEDINTERFACE_SKELETON_H_
#define PROVIDEDINTERFACE_SKELETON_H_
#include <memory>
#include "providedinterface_common.h"

namespace skeleton
{
  namespace events
  {
    using Error = ara::com::SkeletonEvent<double>;
  }                                    /* namespace events */

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
      ara::core::Result<ara::com::InstanceIdentifierContainer> vecInstance(ara::
        com::runtime::ResolveInstanceIDs(instanceSpec));
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
      mMethodMiddleware.reset(ara::com::MethodFactory::CreateSkeletonMethod<
        ProvidedInterfaceSkeleton, skeleton_io::
        ProvidedInterfaceSkeleton_mthd_dispatcher_t>(mMethodProcMode, this,
        mHndl));
      std::string sTopicName;
      sTopicName = "Error";
      Error.Init(ara::com::EventFactory::CreateSkeletonEvent<double, skeleton_io::
                 ProvidedInterface_Error_t>(mHndl, sTopicName));
      return ara::core::Result<void>::FromValue();
    }

    inline void StopOfferService()
    {
      Error.Deinit();
      ara::com::ServiceFactory::DestroyService(mHndl);
    }

    skeleton::events::Error Error;
   private:
    ara::com::ServiceHandleType mHndl;
    ara::com::MethodCallProcessingMode mMethodProcMode;
    std::shared_ptr<ara::com::SkeletonMethodMiddlewareBase> mMethodMiddleware;
  };
}                                      /* namespace skeleton */

#endif                                 //#ifndef PROVIDEDINTERFACE_SKELETON_H_
