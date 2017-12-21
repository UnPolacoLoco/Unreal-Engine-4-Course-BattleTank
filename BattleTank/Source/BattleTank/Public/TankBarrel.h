// Copyright Rafal Boguszewski 2017

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void ElevateBarrel(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20; //Sensible default
	
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevation = 30.f;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevation = 0.f;

	
	
	
};
