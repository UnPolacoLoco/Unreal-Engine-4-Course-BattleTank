// Copyright Rafal Boguszewski 2017

#include "Public/TankAIController.h"
#include "Public/Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	//(set in blueprint that all instances of TANK_BP are automatically possesed by AI)
	
}

//called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AIControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		//move towards the player 

		MoveToActor(PlayerTank, AcceptanceRadius, true, true, false, 0, true);
		
		//Aim towards the player
		AIControlledTank->AimAt(PlayerTank->GetActorLocation(), AIControlledTank->LaunchSpeed);

		//TODO fire if ready
		AIControlledTank->Fire(); 
	}

	

}




