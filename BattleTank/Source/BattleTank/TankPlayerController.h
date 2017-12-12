// Copyright Rafal Boguszewski 2017

#pragma once

#include "CoreMinimal.h"
#include "Public/Tank.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;

	void BeginPlay() override;


	
	
	
	
};
