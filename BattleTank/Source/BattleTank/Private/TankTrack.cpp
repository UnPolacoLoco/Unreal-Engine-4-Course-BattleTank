// Copyright Rafal Boguszewski 2017

#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle at %f"), *Name, Throttle);

	//TODO clamp actual throttle value so player cant overdrive
}

