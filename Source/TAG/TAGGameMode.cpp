// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TAGGameMode.h"
#include "TAGCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "UObject/ConstructorHelpers.h"

using namespace EPlayerState;

ATAGGameMode::ATAGGameMode()
{
	RoundTime = 300;

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

void ATAGGameMode::BeginPlay() {
	Super::BeginPlay();

	GetGameState<ATAGGameState>()->SetRoundTime(RoundTime);
	TagGameState = GetGameState<ATAGGameState>();

	StartRoundTimer();
}

void ATAGGameMode::PostLogin(APlayerController* NewPlayer) {
	UE_LOG(LogTemp, Warning, TEXT("Post Login Performed"));

	PlayerControllers.Add(Cast<ATAGPlayerController>(NewPlayer));

	PlayerControllers.Last()->SetPlayerType(PlayerType::Troll);

	if (PlayerControllers.Num() != 1) {
		if (PlayerControllers.Last(1)->GetPlayerType() == PlayerType::Troll) {
			PlayerControllers.Last()->SetPlayerType(PlayerType::Gnome);

			UE_LOG(LogTemp, Warning, TEXT("Troll made"));
		}
	}

	Super::PostLogin(NewPlayer);
	
}

void ATAGGameMode::RestartPlayer(AController* NewPlayer)
{
	UE_LOG(LogTemp, Warning, TEXT("Restart Performed"));


	if (NewPlayer->GetPawn()) {
		APawn* OldPawn = NewPlayer->GetPawn();
		NewPlayer->UnPossess();
		OldPawn->Destroy();
	}

	FString SpawnTag;

	//Cast to child class and determine type
	switch (Cast<ATAGPlayerController>(NewPlayer)->GetPlayerType()) {
	case Gnome:
		SpawnTag = GnomeSpawnTag;
		DefaultPawnClass = GnomeCharacter;
		UE_LOG(LogTemp, Warning, TEXT("Gnome spawned"));

		break;
	case Troll:
		SpawnTag = TrollSpawnTag;
		DefaultPawnClass = TrollCharacter;
		UE_LOG(LogTemp, Warning, TEXT("Troll spawned"));
		break;
	case Spectator:
		//TODO: Make spectator implementation
		UE_LOG(LogTemp, Warning, TEXT("Spectator should be spawned"));
		break;
	}
	
	AActor* StartPos = FindPlayerStart(NewPlayer, SpawnTag);

	//Spawn pawn and possess
	APawn* SpawnedPawn = SpawnDefaultPawnFor(NewPlayer, StartPos);
	NewPlayer->Possess(SpawnedPawn);
}

void ATAGGameMode::SwitchSides()
{
	for (ATAGPlayerController* player : PlayerControllers)
	{
		if (player->GetPlayerType() == Gnome) {
			player->SetPlayerType(Troll);
		}
		else {
			player->SetPlayerType(Gnome);
		}

		RestartPlayer(player);
	}
}

void ATAGGameMode::EndRound()
{
	UE_LOG(LogTemp, Warning, TEXT("Gnomes gathered %f gold!"), TagGameState->GetScore());

	RestartRound();

	//FTimerHandle GraceTimeHandle;
	//GetWorld()->GetTimerManager().SetTimer(GraceTimeHandle, this, &ATAGGameMode::RestartRound, 0.f, false, 5.f);

	//UGameplayStatics::SetGamePaused(GetWorld(), true);
}

void ATAGGameMode::RestartRound() {
	//UGameplayStatics::SetGamePaused(GetWorld(), false);

	TagGameState->ResetTime();
	StartRoundTimer();
	SwitchSides();
}

void ATAGGameMode::StartRoundTimer()
{
	//Calls the EndRound function once time is up
	GetWorld()->GetTimerManager().SetTimer(RoundTimerHandle, this, &ATAGGameMode::EndRound, RoundTime, false);
}

