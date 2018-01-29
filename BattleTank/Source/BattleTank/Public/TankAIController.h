// Copyright Rafal Boguszewski 2017

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankAIController.generated.h"


class ATankAimingComponent;

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


private:

	//hopw close can the AI tank get
	float AcceptanceRadius = 5000.f;

	
};
