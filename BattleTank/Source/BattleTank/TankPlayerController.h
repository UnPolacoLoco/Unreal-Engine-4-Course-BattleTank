// Copyright Rafal Boguszewski 2017

#pragma once

#include "CoreMinimal.h"
//#include "Public/Tank.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankPlayerController.generated.h"

class ATank;
class UTankAimingComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimingCompRef);

public:


	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:

	//Start the tank moving the barrel towards the crosshair location on screen
	void AimTowardsCrosshair();

	bool GetSightRayHigLocation(OUT FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& out_LookDirection) const;

	bool GetLookVectorHitLocation(FVector& out_HitLocation, FVector LookDirection) const;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3;

	UPROPERTY(EditDefaultsOnly)
	int LineTraceRange = 1000000;

	


	
	
	
	
};
