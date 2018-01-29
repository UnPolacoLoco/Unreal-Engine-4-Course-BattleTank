// Copyright Rafal Boguszewski 2017

#include "TankPlayerController.h"
#include "Public/Tank.h"
#include "BattleTank.h"
#include "TankAimingComponent.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto AimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();

	if (AimingComponent)
	{
		FoundAimingComponent(AimingComponent);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller can't find aiming component"));
	}
	
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AimTowardsCrosshair();

}


ATank* ATankPlayerController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}



void ATankPlayerController::AimTowardsCrosshair()
{
	if (!ensure(GetControlledTank())) { return; }


	FVector HitLocation; // Out parameter

	if (GetSightRayHigLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation, GetControlledTank()->LaunchSpeed);

		//RayCast through the aiming reticule
		// if hit landscape return true and modify vector
		// if not hit handscape, return false and keep vector
	}
}

bool ATankPlayerController::GetSightRayHigLocation(OUT FVector& OutHitLocation) const
{
	// find the crosshair position in pixel coordinates

	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	FVector LookDirection;

	// deproject screen position of the crosshair to a world direction

	if (GetLookDirection(ScreenLocation, LookDirection))

	{
		// Line-trace along that LookDirection and see what we hit (up to max range)


		if (GetLookVectorHitLocation(OutHitLocation, LookDirection))

		{
			//UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *OutHitLocation.ToString());
			return true;
		}

	}


	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & out_LookDirection) const
{
	FVector CameraWorldLocation; // discarding this

	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, out_LookDirection);

	
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& out_HitLocation, FVector LookDirection) const
{
	auto StartLocation = PlayerCameraManager->GetCameraLocation();

	FHitResult HitResult;

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, StartLocation + (LookDirection*LineTraceRange), ECC_Visibility))
	{
		out_HitLocation = HitResult.Location;
		return true;
	}

	return false;
}
