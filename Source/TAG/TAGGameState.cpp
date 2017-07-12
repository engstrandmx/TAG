// Fill out your copyright notice in the Description page of Project Settings.

#include "TAGGameState.h"
#include "TAGGameMode.h"

ATAGGameState::ATAGGameState() {
	PrimaryActorTick.bCanEverTick = true;

	GoldGathered = 0;
	TimeElapsed = 0;
	RoundTime = 0;
}

void ATAGGameState::ScoreGold()
{
	GoldGathered += 1;
}

int32 ATAGGameState::GetScore() {
	return GoldGathered; 
}

float ATAGGameState::GetTimeElapsed() {
	//TimeElapsed = UGameplayStatics::GetTimeSeconds(GetWorld());
	
	return RoundTime - TimeElapsed;
}

void ATAGGameState::ResetTime()
{
	TimeElapsed = 0;
}

void ATAGGameState::ServerResetTime_Implementation()
{
	TimeElapsed = 0;
}

bool ATAGGameState::ServerResetTime_Validate()
{
	return true;
}

void ATAGGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATAGGameState, TimeElapsed);
	DOREPLIFETIME(ATAGGameState, GoldGathered);
	DOREPLIFETIME(ATAGGameState, RoundTime);

}

void ATAGGameState::ResetScore()
{
	GoldGathered = 0;
}

void ATAGGameState::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	TimeElapsed += DeltaSeconds;
}

void ATAGGameState::BeginPlay() {
	Super::BeginPlay();

	if (ROLE_Authority) {

	}
}


