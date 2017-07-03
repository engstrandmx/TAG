// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TAGGameMode.h"
#include "TAGCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "UObject/ConstructorHelpers.h"

ATAGGameMode::ATAGGameMode()
{
	// HARDCODED REFERENCES

	/*
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClassGnome(TEXT("/Game/Characters/GnomeCharacter"));
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClassTroll(TEXT("/Game/Characters/TrollCharacter"));

	//GnomeCharacter = PlayerPawnBPClassGnome.Class;
	//TrollCharacter = PlayerPawnBPClassTroll.Class;

	/*
	if (PlayerPawnBPClassGnome.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClassGnome.Class;
	}
	*/
}

void ATAGGameMode::RestartPlayer(AController* NewPlayer)
{
	//Get player start position and set default pawn to troll
	AActor* StartPos = FindPlayerStart(NewPlayer, TrollSpawnTag);
	DefaultPawnClass = TrollCharacter;

	//If player count is an odd number, then said player is to be spawned as a gnome
	if (GameState->PlayerArray.Num() % 2 == 0) {
		StartPos = FindPlayerStart(NewPlayer, GnomeSpawnTag);
		DefaultPawnClass = GnomeCharacter;
	}

	//Spawn pawn and possess
	APawn* SpawnedPawn = SpawnDefaultPawnFor(NewPlayer, StartPos);
	NewPlayer->Possess(SpawnedPawn);
}


