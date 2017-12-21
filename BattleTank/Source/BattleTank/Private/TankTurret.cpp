// Copyright Rafal Boguszewski 2017

#include "TankTurret.h"
#include "Runtime/Engine/Classes/Engine/World.h"


void UTankTurret::RotateTurret(float RelativeSpeed)
{
	auto time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("turret rotating: %f"), time);
}

