// Fill out your copyright notice in the Description page of Project Settings.

#include "TAGGameState.h"
#include "TAGGameMode.h"

ATAGGameState::ATAGGameState() {
	PrimaryActorTick.bCanEverTick = true;

	GoldGatheredA = 0;
	GoldGatheredB = 0;
	TimeElapsed = 0;
	RoundTime = 0;
}

void ATAGGameState::ScoreGold()
{
	if (bCurrentSideA) {
		GoldGatheredA += 1;
	}

	else {
		GoldGatheredB += 1;
	}

}

int32 ATAGGameState::GetScore(bool SideA) {
	if (SideA) {
		return GoldGatheredA;
	}
	else {
		return GoldGatheredB;
	}
}

float ATAGGameState::GetTimeElapsed() {
	//TimeElapsed = UGameplayStatics::GetTimeSeconds(GetWorld());
	
	return RoundTime - TimeElapsed;
}

void ATAGGameState::ResetTime()
{
	TimeElapsed = 0;
}

void ATAGGameState::SetTime(float Time) {
	RoundTime = Time;
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
	DOREPLIFETIME(ATAGGameState, GoldGatheredA);
	DOREPLIFETIME(ATAGGameState, GoldGatheredB);
	DOREPLIFETIME(ATAGGameState, RoundTime);
	DOREPLIFETIME(ATAGGameState, bCurrentSideA);
}

void ATAGGameState::ResetScore(bool SideA)
{
	if (SideA) {
		GoldGatheredA = 0;
	}
	else {
		GoldGatheredB = 0;
	}
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


