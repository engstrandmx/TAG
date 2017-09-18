// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TAGPlayerController.generated.h"

UENUM(BlueprintType)
namespace EPlayerType
{
	enum PlayerType
	{
		Troll			UMETA(DisplayName = "Troll"),
		Gnome			UMETA(DisplayName = "Gnome"),
		Spectator		UMETA(DisplayName = "Spectator"),
	};
}


/**
 * 
 */
UCLASS()
class TAG_API ATAGPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	FORCEINLINE void SetPlayerType(TEnumAsByte<EPlayerType::PlayerType> TypeToSet) { PlayerControllerType = TypeToSet; }
	FORCEINLINE TEnumAsByte<EPlayerType::PlayerType> GetPlayerType() { return PlayerControllerType; }

private:

	TEnumAsByte<EPlayerType::PlayerType> PlayerControllerType;
	
};
