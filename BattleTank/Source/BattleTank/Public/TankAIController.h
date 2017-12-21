// Copyright Rafal Boguszewski 2017

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
//#include "Public/Tank.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:

	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ATank* AITank = nullptr;

	ATank* GetAITankController() const;

private:
	ATank* GetPlayerTank() const;

	
	
};
