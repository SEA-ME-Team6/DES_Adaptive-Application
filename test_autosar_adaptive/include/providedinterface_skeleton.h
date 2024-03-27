/* This file contains ARA Function Cluster ara::com stub implementation.
   This implementation can be used to compile the generated code
   in Simulink. When deploying the generated code outside of Simulink,
   replace this file with an appropriate ARA file.

   Code generated for Simulink Adaptive model: "test"
   AUTOSAR AP Release: "20-11"
   On: "13-Feb-2024 13:02:25"  */

#ifndef PROVIDEDINTERFACE_SKELETON_H_
#define PROVIDEDINTERFACE_SKELETON_H_
#include <memory>
#include "../com/method_call_proccessing_mode.h"
#include "../com/skeleton_event.h"
#include "../com/instance_identifier_container.h"
#include "../core/instance_specifier.h"

namespace skeleton
{
	namespace events
	{
		using Out1 = ara::com::SkeletonEvent<double>;
	}                                    /* namespace events */

	namespace fields
	{
	}                                    /* namespace fields */

	class ProvidedInterfaceSkeleton {
		private:
		ara::com::HandleType mHandle;
		ara::com::MethodCallProcessingMode mMethodProcMode;

		public:
		skeleton::events::Out1 Out1;
    
		ProvidedInterfaceSkeleton(ara::com::InstanceIdentifier instance, ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent) : mHandle(instance), mMethodProcMode(mode) {};
		// static ara::core::Result<ProvidedInterfaceSkeleton> Create(const ara::core::InstanceIdentifier &instance, ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent) noexcept {};


		// ProvidedInterfaceSkeleton(ara::com::InstanceIdentifierContainer instance, ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent) : mHandle(instance), mMethodProcMode(mode) {};
		// static ara::core::Result<ProvidedInterfaceSkeleton> Create(const ara::core::InstanceIdentifierContainer &instance, ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent) noexcept {};

		ProvidedInterfaceSkeleton(ara::core::InstanceSpecifier instanceSpec, ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent): mMethodProcMode(mode)
		{
			ara::core::Result<ara::com::InstanceIdentifierContainer> vecInstance(ara::com::runtime::ResolveInstanceIDs(instanceSpec));
			if (!vecInstance->empty()) {
			mHandle.instanceId = vecInstance->front();
			}                                /* if */
		}
		// static ara::core::Result<ProvidedInterfaceSkeleton> Create(const ara::core::InstanceSpecifier &instance, ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent) noexcept {};


		virtual ~ProvidedInterfaceSkeleton()
		{
		  StopOfferService();
		}

		ProvidedInterfaceSkeleton(const ProvidedInterfaceSkeleton&) = delete;
		ProvidedInterfaceSkeleton& operator = (const ProvidedInterfaceSkeleton&) = delete;
		ProvidedInterfaceSkeleton(ProvidedInterfaceSkeleton&& sklObj) = default;
		ProvidedInterfaceSkeleton& operator = (ProvidedInterfaceSkeleton&& sklObj) = default;

		inline ara::core::Result<void> OfferService()
		{
			uint16_t mEventId, mEventGroupId;
			mEventId = 46921;
			mEventGroupId = 60307;
			Out1.Init(mHandle, mEventId, mEventGroupId);
			// Have to Register service
		}

    inline void StopOfferService()
    {
		Out1.Deinit();

    }

  	};
}                                      /* namespace skeleton */

#endif                                 //#ifndef PROVIDEDINTERFACE_SKELETON_H_
