// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

private:
	int32 GoldGathered;
	
};
