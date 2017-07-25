// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Net/UnrealNetwork.h"
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

	void ResetTime();
	void ResetScore();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	FORCEINLINE void SetRoundTime(float Time) { RoundTime = Time; }

private:
	UPROPERTY(Transient, Replicated)
	float TimeElapsed;
	UPROPERTY(Transient, Replicated)
	float RoundTime;

	UPROPERTY(Transient, Replicated)
	int32 GoldGathered;

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerResetTime();
	void ServerResetTime_Implementation();
	bool ServerResetTime_Validate();

protected:
	void Tick(float DeltaSeconds) override;
	void BeginPlay() override;
};
