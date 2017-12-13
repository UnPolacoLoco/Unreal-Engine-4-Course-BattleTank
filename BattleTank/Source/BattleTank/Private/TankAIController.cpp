// Copyright Rafal Boguszewski 2017

#include "Public/TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	AITank = GetAITankController();

	if (!AITank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI Controller not attached (possessing) to %s"), *GetPawn()->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AI Controller attached to %s"), *GetPawn()->GetName())
	}


	auto PlayerPawn = GetPlayerTank();

	if (!PlayerPawn)
	{
		UE_LOG(LogTemp, Error, TEXT("Player Tank not found! nullptr at %s"), *AITank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player Tank found in %s at %s"), *PlayerPawn->GetName(), *PlayerPawn->GetActorLocation().ToString())
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

