// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/GameMode.h"
#include "TAGGameState.h"
#include "TAGPlayerController.h"
#include "TrollCharacter.h"
#include "GnomeCharacter.h"
#include "TAGGameMode.generated.h"

using namespace EPlayerType;

UCLASS(minimalapi)
class ATAGGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATAGGameMode();

	PlayerType CurrentPlayerType = PlayerType::Troll;

	AGnomeCharacter* CurrentGnome;
	ATrollCharacter* CurrentTroll;

	UPROPERTY(EditAnywhere, Category = Characters)
	TSubclassOf<APawn> TrollCharacter;
	UPROPERTY(EditAnywhere, Category = Characters)
	TSubclassOf<APawn> GnomeCharacter;
	UPROPERTY(EditAnywhere, Category = Characters)
	TSubclassOf<APawn> SpectatorCharacter;

	UPROPERTY(EditAnywhere, Category = Characters)
	FString TrollSpawnTag = "SpawnTroll";
	UPROPERTY(EditAnywhere, Category = Characters)
	FString GnomeSpawnTag = "SpawnGnome";

	void RestartPlayer(AController* NewPlayer);

	FORCEINLINE void SetCurrentGnome(AGnomeCharacter* Gnome) { CurrentGnome = Gnome; }
	FORCEINLINE void SetCurrentTroll(ATrollCharacter* Troll) { CurrentTroll = Troll; }
	FORCEINLINE void SetCurrentPlayerType(PlayerType Type) { CurrentPlayerType = Type; }


	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
		void OnPreGameStart();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
		void OnPreGameEnd();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
		void OnScoreGold();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
		void OnRoundStart();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
		void OnRoundEnd();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
		void OnGameEnd();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
		void OnSwitchSides();

private:

	AActor* FindPlayerStart_Implementation(AController* Player, const FString& IncomingName) override;

	ATAGGameState* TagGameState;
	
	UPROPERTY(EditAnywhere, Category = Collections)
	TArray<ATAGPlayerController*> PlayerControllers;

	UPROPERTY(EditAnywhere, Category = "Debug")
	bool bSpawnTypeFlipped = false;
	UPROPERTY(EditAnywhere, Category = "Debug")
	bool bSpawnSpectator = false;

protected:
	void PostLogin(APlayerController* NewPlayer) override;

	void BeginPlay() override;
};



