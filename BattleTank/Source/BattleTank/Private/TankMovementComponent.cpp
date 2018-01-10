// Copyright Rafal Boguszewski 2017

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{

	if (!LeftTrackToSet || !RightTrackToSet) { return; }

	LeftTankTrack = LeftTrackToSet;
	RightTankTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{

	LeftTankTrack->SetThrottle(Throw);
	RightTankTrack->SetThrottle(Throw);
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward, throw: %f"), Throw);

	//TODO prevent doubling
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	LeftTankTrack->SetThrottle(Throw);
	RightTankTrack->SetThrottle(-Throw);
}


