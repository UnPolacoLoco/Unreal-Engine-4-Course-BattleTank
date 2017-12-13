// Copyright Rafal Boguszewski 2017

#include "TankPlayerController.h"
#include "Public/Tank.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player controlle - no Controller Tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player controller possesing: %s "), *ControlledTank->GetName());
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
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out parameter

	if (GetSightRayHigLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
	}


		//RayCast through the aiming reticule
		// if hit landscape return true and modify vector
		// if not hit handscape, return false and keep vector
}

bool ATankPlayerController::GetSightRayHigLocation(OUT FVector& OutHitLocation) const
{

	// find the crosshair position

	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	

	// deproject screen position of the crosshair to a world direction
	// Line-trace along that look direction and see what we hit (up to max range)




	OutHitLocation = FVector(1.0f, 1.0f, 1.0f);

	return false;
}
