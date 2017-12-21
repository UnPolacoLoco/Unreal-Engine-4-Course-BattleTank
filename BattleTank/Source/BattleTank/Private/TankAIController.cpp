// Copyright Rafal Boguszewski 2017

#include "Public/TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	AITank = GetAITankController();

	///Log out potential lack of AI Tank Controllers (set in blueprint that all instances of TANK_BP are automatically possesed by AI)
	if (!AITank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI Controller not attached (possessing) to %s"), *GetPawn()->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AI Controller attached to %s"), *GetPawn()->GetName())
	}


	auto PlayerPawn = GetPlayerTank();

	///Log out potential lack of PlayerPawn Tank Controller
	if (!PlayerPawn)
	{
		UE_LOG(LogTemp, Error, TEXT("Player Tank not found! nullptr at %s"), *AITank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player Tank found in %s at %s"), *PlayerPawn->GetName(), *PlayerPawn->GetActorLocation().ToString())
	}
}

//called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		GetAITankController()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankAIController::GetAITankController() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	return Cast<ATank>(PlayerPawn);
	 
}

