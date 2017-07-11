// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TAGPlayerController.generated.h"

UENUM(BlueprintType)
namespace EPlayerState
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
	FORCEINLINE void SetPlayerType(TEnumAsByte<EPlayerState::PlayerType> TypeToSet) { PlayerControllerType = TypeToSet; }
	FORCEINLINE TEnumAsByte<EPlayerState::PlayerType> GetPlayerType() { return PlayerControllerType; }

private:

	TEnumAsByte<EPlayerState::PlayerType> PlayerControllerType;
	
};
