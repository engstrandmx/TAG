// Fill out your copyright notice in the Description page of Project Settings.

#include "TAGPlayerState.h"




void ATAGPlayerState::ReceiveDamage(float Damage)
{
	Health -= Damage;
}

void ATAGPlayerState::InitStats(AGnomeCharacter* Character)
{
	Health = Character->GetHealth();
	MaxHealth = Character->GetMaxHealth();

}

void ATAGPlayerState::InitStats(ATrollCharacter* Character)
{

}

void ATAGPlayerState::BeginPlay()
{
	Super::BeginPlay();

	

}

void ATAGPlayerState::ResetPlayer()
{
	//Destroys pawn and tells server to spawn a new pawn

}
