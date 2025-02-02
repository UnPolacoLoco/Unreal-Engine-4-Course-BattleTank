// Copyright Rafal Boguszewski 2017

#include "TankMovementComponent.h"
#include "TankTrack.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!ensure(LeftTrackToSet || RightTrackToSet)) { return; }

	LeftTankTrack = LeftTrackToSet;
	RightTankTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!ensure(LeftTankTrack || RightTankTrack)) { return; }
	LeftTankTrack->SetThrottle(Throw);
	RightTankTrack->SetThrottle(Throw);

}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	LeftTankTrack->SetThrottle(Throw);
	RightTankTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//No need to call super, as we're replacing the functionality (super is called if we want to extend the overriden function)

	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto TankForwardDirection = GetOwner()->GetActorForwardVector();

	auto ForwardThrow = FVector::DotProduct(AIForwardIntention, TankForwardDirection);
	auto RightThrow = FVector::CrossProduct(TankForwardDirection, AIForwardIntention).Z;

	IntendMoveForward(ForwardThrow);
	IntendTurnRight(RightThrow);

}


