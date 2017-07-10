// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GnomeCharacter.h"
#include "TAGCharacter.h"
#include "TrollCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TAG_API ATrollCharacter : public ATAGCharacter
{
	GENERATED_BODY()

	ATrollCharacter();

	//UFUNCTION()
	//void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

protected:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void Interact();

private:
	UPROPERTY(EditAnywhere, Category = Components)
	USphereComponent* InteractShape;

	bool EnemyIsOverlapping = false;

	UPROPERTY(EditAnywhere, Category = Stats)
	float Damage = 10.f;

	UPROPERTY(EditAnywhere, Category = Stats)
	float DamageRadius = 100.f;
};
