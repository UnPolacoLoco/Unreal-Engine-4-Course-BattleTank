// Copyright Rafal Boguszewski 2017

#include "TankBarrel.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void UTankBarrel::ElevateBarrel(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	//Given a max elevation speed and the frame time

	auto Time = GetWorld()->GetTimeSeconds();

	UE_LOG(LogTemp, Warning, TEXT("barrel elevating: %f"), Time);
}



