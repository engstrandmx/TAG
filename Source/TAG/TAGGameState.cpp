// Fill out your copyright notice in the Description page of Project Settings.

#include "TAGGameState.h"




ATAGGameState::ATAGGameState() {
	GoldGathered = 0;
}

void ATAGGameState::ScoreGold()
{
	GoldGathered += 1;
}

int32 ATAGGameState::GetScore() {
	return GoldGathered; 
}
