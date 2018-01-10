// Copyright Rafal Boguszewski 2017

#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	//clamp actual throttle value so player cant overdrive

	Throttle = FMath::Clamp(Throttle, -1.f, 1.f);

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}

