// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GnomeCharacter.h"
#include "TrollCharacter.h"
#include "GameFramework/PlayerState.h"
#include "TAGPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class TAG_API ATAGPlayerState : public APlayerState
{
	GENERATED_BODY()

public :
	ACharacter* LinkedCharacter;
	AController* LinkedController;

	float MaxHealth;
	float Health;
	
	void ReceiveDamage(float Damage);
	void InitStats(AGnomeCharacter* Character);
	void InitStats(ATrollCharacter* Character);
	void BeginPlay();
	void ResetPlayer();

};
