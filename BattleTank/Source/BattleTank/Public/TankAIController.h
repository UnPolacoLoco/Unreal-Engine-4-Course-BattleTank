// Copyright Rafal Boguszewski 2017

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Public/Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;

	ATank* AITank = nullptr;

	ATank* GetAITankController() const;
	
	
};
