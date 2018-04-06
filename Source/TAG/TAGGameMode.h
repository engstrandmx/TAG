// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/GameMode.h"
#include "TAGGameState.h"
#include "TAGPlayerController.h"
#include "TrollCharacter.h"
#include "GnomeCharacter.h"
#include "TAGGameMode.generated.h"

using namespace EPlayerType;

UCLASS(minimalapi)
class ATAGGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATAGGameMode();

	//The type of character being controlled at the moment. Used to determine which character to switch to.
	PlayerType CurrentPlayerType = PlayerType::Troll;

	//References to the current spawned characters of each type.
	AGnomeCharacter* CurrentGnome;
	ATrollCharacter* CurrentTroll;

	//Which pawn to spawn when respawning and starting the game.
	UPROPERTY(EditAnywhere, Category = Characters)
	TSubclassOf<APawn> TrollCharacter;
	UPROPERTY(EditAnywhere, Category = Characters)
	TSubclassOf<APawn> GnomeCharacter;
	UPROPERTY(EditAnywhere, Category = Characters)
	TSubclassOf<APawn> SpectatorCharacter;

	//Legacy, used when gnome and troll had different spawns
	UPROPERTY(EditAnywhere, Category = Characters)
	FString TrollSpawnTag = "SpawnTroll";
	UPROPERTY(EditAnywhere, Category = Characters)
	FString GnomeSpawnTag = "SpawnGnome";

	//Initial spawnpoint, this is where player will spawn when first starting the game
	UPROPERTY(EditAnywhere, Category = Spawn)
	AActor* StartingSpawnPoint;

	//Amount of collectibles collected, this is reset between levels at the moment
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collectibles)
	int CollectibleCount;
	//The amount of collectibles in the loaded level, this is set at BeginPlay()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Collectibles)
	int CollectiblesInLevel;

	//Getters
	UFUNCTION(BlueprintCallable, Category = Player)
	FORCEINLINE	TEnumAsByte<EPlayerType::PlayerType> GetCurrentPlayerType() { return CurrentPlayerType; }

	UFUNCTION(BlueprintCallable, Category = "Gameplay Actors")
	FORCEINLINE ATrollCharacter* GetTrollCharacter() { return CurrentTroll; }
	UFUNCTION(BlueprintCallable, Category = "Gameplay Actors")
	FORCEINLINE AGnomeCharacter* GetGnomeCharacter() { return CurrentGnome; }

	FORCEINLINE void SetCurrentGnome(AGnomeCharacter* Gnome) { CurrentGnome = Gnome; }
	FORCEINLINE void SetCurrentTroll(ATrollCharacter* Troll) { CurrentTroll = Troll; }
	FORCEINLINE void SetCurrentPlayerType(PlayerType Type) { CurrentPlayerType = Type; }
	FORCEINLINE void SetCurrentCheckpoints(TArray<APlayerStart*> InArray) { CurrentPlayerStarts = InArray; }

	//This is called every time a character is respawned or during initial spawn
	void RestartPlayer(AController* NewPlayer);

	//Called by collectible blueprint when player picks up a collectible
	UFUNCTION(BlueprintCallable, Category = Collectibles)
	void PickupCollectible();

	//Blueprint events, some legacy
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
		void OnPreGameStart();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
		void OnPreGameEnd();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
		void OnScoreGold();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
		void OnRoundStart();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
		void OnRoundEnd();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
		void OnFadeIn();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
		void OnFadeOut();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
		void OnCollectiblePickup();

private:

	//Array of checkpoints the player can spawn at. These are set by the checkpointfield blueprint 
	TArray<APlayerStart*> CurrentPlayerStarts;

	AActor* FindPlayerStart_Implementation(AController* Player, const FString& IncomingName) override;

	ATAGGameState* TagGameState;
	
	UPROPERTY(EditAnywhere, Category = Collections)
	TArray<ATAGPlayerController*> PlayerControllers;

	UPROPERTY(EditAnywhere, Category = "Debug")
	bool bSpawnTypeFlipped = false;
	UPROPERTY(EditAnywhere, Category = "Debug")
	bool bSpawnSpectator = false;

	bool bInit = false;

protected:
	void PostLogin(APlayerController* NewPlayer) override;

	void BeginPlay() override;
};



