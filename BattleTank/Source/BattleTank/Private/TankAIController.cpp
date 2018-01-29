// Copyright Rafal Boguszewski 2017

#include "Public/TankAIController.h"
#include "TankAimingComponent.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	//(set in blueprint that all instances of TANK_BP are automatically possesed by AI)
	
}

//called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AITank = GetPawn();

	if (PlayerTank)
	{
		//move towards the player 

		MoveToActor(PlayerTank, AcceptanceRadius, true, true, false, 0, true);
		
		//Aim towards the player
		auto AimingComponent = AITank->FindComponentByClass<UTankAimingComponent>();

		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		//TODO fire if ready
		AimingComponent->Fire(); //TODO fix firing
	}

}




