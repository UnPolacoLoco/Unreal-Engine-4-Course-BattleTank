// Copyright Rafal Boguszewski 2017

#include "Public/TankAIController.h"
#include "Public/Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	//AITank = Cast<ATank>(GetPawn());

	/////Log out potential lack of AI Tank Controllers (set in blueprint that all instances of TANK_BP are automatically possesed by AI)
	//if (!AITank)
	//{
	//	UE_LOG(LogTemp, Error, TEXT("AI Controller not attached (possessing) to %s"), *GetPawn()->GetName())
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Error, TEXT("AI Controller attached to %s"), *GetPawn()->GetName())
	//}


	//APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	//Cast<ATank>(PlayerPawn);

	/////Log out potential lack of PlayerPawn Tank Controller
	//if (!PlayerPawn)
	//{
	//	UE_LOG(LogTemp, Error, TEXT("Player Tank not found! nullptr at %s"), *AITank->GetName())
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Error, TEXT("Player Tank found in %s at %s"), *PlayerPawn->GetName(), *PlayerPawn->GetActorLocation().ToString())
	//}
}

//called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AIControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		//TODO move towards the player 

		//Aim towards the player
		AIControlledTank->AimAt(PlayerTank->GetActorLocation(), AIControlledTank->LaunchSpeed);

		//TODO fire if ready
		AIControlledTank->Fire(); 
	}

}




