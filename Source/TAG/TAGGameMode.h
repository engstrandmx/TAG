// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/GameMode.h"
#include "TAGGameState.h"
#include "TAGPlayerController.h"
#include "TAGGameMode.generated.h"

UCLASS(minimalapi)
class ATAGGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATAGGameMode();

	UPROPERTY(EditAnywhere, Category = Characters)
	TSubclassOf<APawn> TrollCharacter;
	UPROPERTY(EditAnywhere, Category = Characters)
	TSubclassOf<APawn> GnomeCharacter;

	UPROPERTY(EditAnywhere, Category = Characters)
	FString TrollSpawnTag = "SpawnTroll";
	UPROPERTY(EditAnywhere, Category = Characters)
	FString GnomeSpawnTag = "SpawnGnome";

	void RestartPlayer(AController* NewPlayer);
	FORCEINLINE float GetRoundTime() { return RoundTime; }

private:

	AActor* FindPlayerStart_Implementation(AController* Player, const FString& IncomingName) override;

	void SwitchSides();
	UFUNCTION()
	void EndRound();
	UFUNCTION()
	void RestartRound();
	void StartRoundTimer();

	UPROPERTY(EditAnywhere, Category = GameRules)
	float RoundTime;
	
	FTimerHandle RoundTimerHandle;

	ATAGGameState* TagGameState;
	TArray<ATAGPlayerController*> PlayerControllers;

	UPROPERTY(EditAnywhere, Category = "Debug")
	bool bSpawnTypeFlipped = false;

protected:
	void PostLogin(APlayerController* NewPlayer) override;

	void BeginPlay() override;

};



