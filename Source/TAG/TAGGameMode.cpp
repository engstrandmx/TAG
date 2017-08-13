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

	if (bSpawnTypeFlipped) {
		PlayerControllers.Last()->SetPlayerType(PlayerType::Gnome);

	}
	else {
		PlayerControllers.Last()->SetPlayerType(PlayerType::Troll);
	}

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

	if (NewPlayer->StartSpot == StartPos) {
		StartPos = FindPlayerStart(NewPlayer, SpawnTag);
	}

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
	//UE_LOG(LogTemp, Warning, TEXT("Gnomes gathered %f gold!"), TagGameState->GetScore());

	RestartRound();

	//FTimerHandle GraceTimeHandle;
	//GetWorld()->GetTimerManager().SetTimer(GraceTimeHandle, this, &ATAGGameMode::RestartRound, 0.f, false, 5.f);

	//UGameplayStatics::SetGamePaused(GetWorld(), true);
}

void ATAGGameMode::RestartRound() {
	//UGameplayStatics::SetGamePaused(GetWorld(), false);

	TagGameState->bCurrentSideA = !TagGameState->bCurrentSideA;
	TagGameState->ResetTime();
	StartRoundTimer();
	SwitchSides();
}

AActor* ATAGGameMode::FindPlayerStart_Implementation(AController* Player, const FString& IncomingName)
{
	UWorld* World = GetWorld();

	// If incoming start is specified, then just use it
	if (!IncomingName.IsEmpty())
	{
		const FName IncomingPlayerStartTag = FName(*IncomingName);
		
		AActor* LastStart = nullptr;

		for (TActorIterator<APlayerStart> It(World); It; ++It)
		{
			APlayerStart* Start = *It;

			if (Start && Start->PlayerStartTag == IncomingPlayerStartTag)
			{
				LastStart = Start;

				if (FMath::FRandRange(0, 2) > 1) {
					return Start;
				}
			}
		}

		if (LastStart != nullptr) {
			return LastStart;
		}

	}

	// Always pick StartSpot at start of match
	if (ShouldSpawnAtStartSpot(Player))
	{
		if (AActor* PlayerStartSpot = Player->StartSpot.Get())
		{
			return PlayerStartSpot;
		}
		else
		{
			UE_LOG(LogGameMode, Error, TEXT("FindPlayerStart: ShouldSpawnAtStartSpot returned true but the Player StartSpot was null."));
		}
	}

	AActor* BestStart = ChoosePlayerStart(Player);
	if (BestStart == nullptr)
	{
		// No player start found
		UE_LOG(LogGameMode, Log, TEXT("FindPlayerStart: PATHS NOT DEFINED or NO PLAYERSTART with positive rating"));

		// This is a bit odd, but there was a complex chunk of code that in the end always resulted in this, so we may as well just 
		// short cut it down to this.  Basically we are saying spawn at 0,0,0 if we didn't find a proper player start
		BestStart = World->GetWorldSettings();
	}

	return BestStart;
}


void ATAGGameMode::StartRoundTimer()
{
	//Calls the EndRound function once time is up
	GetWorld()->GetTimerManager().SetTimer(RoundTimerHandle, this, &ATAGGameMode::EndRound, RoundTime, false);
}

