// Copyright Rafal Boguszewski 2017

#include "TankTurret.h"
#include "Runtime/Engine/Classes/Engine/World.h"


void UTankTurret::RotateTurret(float RelativeSpeed)
{
	auto time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("turret rotating: %f"), time);

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;



	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}

