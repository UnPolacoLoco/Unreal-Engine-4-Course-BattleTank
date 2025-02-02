// Copyright Rafal Boguszewski 2017

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	//-1 is max downward movement, +1 is max up movement
	void ElevateBarrel(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxDegreesPerSecond = 10; //Sensible default
	
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxElevation = 40.f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinElevation = 0.f;

	
	
	
};
