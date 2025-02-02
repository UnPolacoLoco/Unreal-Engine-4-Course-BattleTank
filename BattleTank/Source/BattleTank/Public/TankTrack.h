// Copyright Rafal Boguszewski 2017

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force and to apply forces to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);

	// Max Force per track in Newtons
	UPROPERTY(EditDefaultsOnly, Category = Movement)
		float TrackMaxDrivingForce = 2500000.f; //Assume 40 ton tank and 1g acceleration
	
};
