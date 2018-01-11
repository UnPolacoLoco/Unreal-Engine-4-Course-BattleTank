// Copyright Rafal Boguszewski 2017

#include "TankMovementComponent.h"
#include "TankTrack.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{

	if (!LeftTrackToSet || !RightTrackToSet) { return; }

	LeftTankTrack = LeftTrackToSet;
	RightTankTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{

	if (!LeftTankTrack || !RightTankTrack) { return; }
	LeftTankTrack->SetThrottle(Throw);
	RightTankTrack->SetThrottle(Throw);

	//TODO prevent doubling
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	LeftTankTrack->SetThrottle(Throw);
	RightTankTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//No need to call super, as we're replacing the functionality
	auto TankName = GetOwner()->GetName();
	
	

	UE_LOG(LogTemp, Warning, TEXT("%s vectoring to: %s"), *TankName, *MoveVelocity.GetSafeNormal().ToString())
}


