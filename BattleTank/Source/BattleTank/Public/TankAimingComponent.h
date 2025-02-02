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
class AProjectile;

//Holds barrel properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable)
		void Fire();

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInSeconds = 3.f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;


protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EAimingState AimingState = EAimingState::RELOADING;

		
private:

	// Sets default values for this component's properties
	UTankAimingComponent();
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 6000.f;

	

	double LastFireTime = 0;

	
	
};
