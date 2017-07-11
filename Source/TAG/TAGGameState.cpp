// Fill out your copyright notice in the Description page of Project Settings.

#include "TAGGameState.h"

ATAGGameState::ATAGGameState() {
	GoldGathered = 0;
	TimeElapsed = 0;
}

void ATAGGameState::ScoreGold()
{
	GoldGathered += 1;
}

int32 ATAGGameState::GetScore() {
	return GoldGathered; 
}

float ATAGGameState::GetTimeElapsed() {
	TimeElapsed = UGameplayStatics::GetTimeSeconds(GetWorld());
	
	return TimeElapsed;
}

void ATAGGameState::BeginPlay()
{
	Super::BeginPlay();

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.SetTickFunctionEnable(true);
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void ATAGGameState::Tick(float DeltaSeconds)
{
	//Super::Tick(DeltaSeconds);

	//TimeElapsed += DeltaSeconds;
		//UGameplayStatics::GetTimeSeconds(GetWorld());
}

