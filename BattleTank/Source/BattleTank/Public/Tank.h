// Copyright Rafal Boguszewski 2017

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Tank.generated.h"

//forward declarations
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();


	UFUNCTION(BlueprintCallable)
		void Fire();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	//UPROPERTY(EditDefaultsOnly, Category = Firing)
	//	float LaunchSpeed = 6000.f;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInSeconds = 3.f;


	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

private:

	UTankBarrel *Barrel = nullptr; //TODO remove
	double LastFireTime = 0;

	float LaunchSpeed = 0;

};