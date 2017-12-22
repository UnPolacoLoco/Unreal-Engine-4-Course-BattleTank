// Copyright Rafal Boguszewski 2017

#include "Public/TankAimingComponent.h"
#include "../Public/TankAimingComponent.h"
#include "../Public/TankBarrel.h"
#include "../Public/TankTurret.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false; 

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret * TurretToSet)
{
	Turret = TurretToSet;
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	auto BarrelLocation = Barrel->GetComponentLocation();


	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace);
	
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s with speed of %f"), *GetOwner()->GetName(), *AimDirection.ToString(), *BarrelLocation.ToString(), LaunchSpeed);

		MoveBarrelTowards(AimDirection);
	
	}
	else
	{
		auto time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: no aim solution found"), time);
	}
	
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//Get the AimDirection vector and set the rotation of the barrel basedd on that vecotr. Work out the difference between current barrel rotation, and AimDirection
	
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();

	auto DeltaRotator = AimAsRotator - BarrelRotator;

	//UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"), *AimAsRotator.ToString());

	Barrel->ElevateBarrel(DeltaRotator.Pitch);
	Turret->RotateTurret(DeltaRotator.Yaw);
	
}

