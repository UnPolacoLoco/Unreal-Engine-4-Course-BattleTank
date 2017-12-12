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

}


ATank* ATankAIController::GetAITankController() const
{
	return Cast<ATank>(GetPawn());
}

