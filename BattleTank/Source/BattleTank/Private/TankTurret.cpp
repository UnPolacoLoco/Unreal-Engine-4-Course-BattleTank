// Copyright Rafal Boguszewski 2017

#include "TankTurret.h"
#include "Runtime/Engine/Classes/Engine/World.h"


void UTankTurret::RotateTurret(float RelativeSpeed)
{
	auto time = GetWorld()->GetTimeSeconds();
	///UE_LOG(LogTemp, Warning, TEXT("turret rotating: %f"), time);

	//move the turret the right amount this frame 

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;

	//UE_LOG(LogTemp, Warning, TEXT("%f: rotation %f"), time, NewRotation);

	SetRelativeRotation(FRotator(0, NewRotation, 0));


}

