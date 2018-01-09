// Copyright Rafal Boguszewski 2017

#include "TankBarrel.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void UTankBarrel::ElevateBarrel(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	//Given a max elevation speed and the frame time

	///auto Time = GetWorld()->GetTimeSeconds();
	///UE_LOG(LogTemp, Warning, TEXT("barrel elevating: %f"), Time);

	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);

	SetRelativeRotation(FRotator(Elevation, 0, 0));


}



