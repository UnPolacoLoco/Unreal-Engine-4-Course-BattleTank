// Copyright Rafal Boguszewski 2017

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankAimingComponent.generated.h"


//ENUM for aiming state
UENUM()
enum class EAimingState :uint8
{
	RELOADING,
	AIMING,
	LOCKED
};

//Forward Declaration
class UTankBarrel;
class UTankTurret;

//Holds barrel properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurretReference(UTankTurret* TurretToSet);
	void AimAt(FVector HitLocation, float LaunchSpeed);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EAimingState AimingState = EAimingState::AIMING;

		
private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);

	
	
};
