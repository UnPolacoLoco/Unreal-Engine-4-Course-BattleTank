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

	// find the crosshair position in pixel coordinates



	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	FVector LookDirection;

	// deproject screen position of the crosshair to a world direction

	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString());
	}
	

	// Line-trace along that LookDirection and see what we hit (up to max range)

	FHitResult HitResult;

	FCollisionObjectQueryParams LandscapeCollisionParam = FCollisionObjectQueryParams(ECC_WorldStatic);

	GetWorld()->LineTraceSingleByObjectType(HitResult, GetWorld()->GetFirstPlayerController()->GetActorTransform().GetLocation(), LookDirection * 100000, LandscapeCollisionParam);

	UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *HitResult.ToString());


	OutHitLocation = FVector(1.0f, 1.0f, 1.0f);

	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & out_LookDirection) const
{
	FVector CameraWorldLocation;

	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, out_LookDirection);

	
}
