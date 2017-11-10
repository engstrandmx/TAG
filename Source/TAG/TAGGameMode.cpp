// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TAGGameMode.h"
#include "TAGCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "UObject/ConstructorHelpers.h"

ATAGGameMode::ATAGGameMode()
{
	// HARDCODED REFERENCES
}

void ATAGGameMode::BeginPlay() {
	Super::BeginPlay();

	TagGameState = GetGameState<ATAGGameState>();
}

void ATAGGameMode::PostLogin(APlayerController* NewPlayer) {
	UE_LOG(LogTemp, Warning, TEXT("Post Login Performed"));


	PlayerControllers.Add(Cast<ATAGPlayerController>(NewPlayer));

	PlayerControllers.Last()->SetPlayerType(PlayerType::Troll);

	Super::PostLogin(NewPlayer);
}

void ATAGGameMode::RestartPlayer(AController* NewPlayer)
{
	UE_LOG(LogTemp, Warning, TEXT("Restart Performed"));

	FVector PlayerLastPosition = FVector::ZeroVector;

	if (NewPlayer->GetPawn()) {
		APawn* OldPawn = NewPlayer->GetPawn();
		NewPlayer->UnPossess();
		PlayerLastPosition = OldPawn->GetActorLocation();
		
		OldPawn->Destroy();
	}

	FString SpawnTag;
	AActor* StartPos = FindPlayerStart(NewPlayer, SpawnTag);;

	//If no checkpoints have been assigned player spawns as usual
	if (CurrentPlayerStarts.Num() == 1) {
		StartPos = CurrentPlayerStarts[0];
	}

	//Else nearest current checkpoint is used
	if (CurrentPlayerStarts.Num() > 1) {
		int8 size = CurrentPlayerStarts.Num();
		int8 closestIndex = 0;

		for (int8 i = 0; i < size; i++)
		{
			if (FVector::Dist(PlayerLastPosition, CurrentPlayerStarts[closestIndex]->GetActorLocation()) > FVector::Dist(PlayerLastPosition, CurrentPlayerStarts[i]->GetActorLocation())) {
				closestIndex = i;
			}
		}

		StartPos = CurrentPlayerStarts[closestIndex];
	}

	if (NewPlayer->StartSpot == StartPos) {
		StartPos = FindPlayerStart(NewPlayer, SpawnTag);
	}

	APawn* SpawnedPawn = NULL;

	//Cast to child class and determine type
	switch (CurrentPlayerType) {
	case PlayerType::Gnome:
		DefaultPawnClass = GnomeCharacter;

		SpawnedPawn = SpawnDefaultPawnFor(NewPlayer, StartPos);

		if (CurrentTroll) {
			Cast<AGnomeCharacter>(SpawnedPawn)->SetTrollParent(CurrentTroll);
		}

		UE_LOG(LogTemp, Warning, TEXT("Gnome spawned"));
		break;
	case PlayerType::Troll:
		DefaultPawnClass = TrollCharacter;

		SpawnedPawn = SpawnDefaultPawnFor(NewPlayer, StartPos);
		CurrentTroll = Cast<ATrollCharacter>(SpawnedPawn);

		UE_LOG(LogTemp, Warning, TEXT("Troll spawned"));
		break;
	case PlayerType::Spectator:
		//TODO: Make spectator implementation
		SpawnTag = TrollSpawnTag;
		DefaultPawnClass = SpectatorCharacter;
		UE_LOG(LogTemp, Warning, TEXT("Spectator should be spawned"));
		break;
	}

	OnFadeIn();

	NewPlayer->Possess(SpawnedPawn);
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


