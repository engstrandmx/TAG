// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/GameStateBase.h"
#include "TAGGameState.generated.h"

/**
 * 
 */
UCLASS()
class TAG_API ATAGGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ATAGGameState();

	void ScoreGold();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "GameState")
	int32 GetScore();
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "GameState")
	float GetTimeElapsed();


private:
	int32 GoldGathered;
	float TimeElapsed;

protected:

	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;
};
