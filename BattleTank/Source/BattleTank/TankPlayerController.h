// Copyright Rafal Boguszewski 2017

#pragma once

#include "CoreMinimal.h"
#include "Public/Tank.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:

	//Start the tank moving the barrel towards the crosshair location on screen
	void AimTowardsCrosshair();

	bool GetSightRayHigLocation(OUT FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& out_LookDirection) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.33333f;


	
	
	
	
};
