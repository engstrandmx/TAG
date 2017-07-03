// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "TAGCharacter.h"
#include "GnomeCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TAG_API AGnomeCharacter : public ATAGCharacter
{
	GENERATED_BODY()

public:
	AGnomeCharacter();

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	virtual void BeginPlay() override;
	virtual void ReceiveAnyDamage(float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	FORCEINLINE float GetMaxHealth() { return MaxHealth; }
	FORCEINLINE float GetHealth() { return Health; }

private:
	UPROPERTY(EditAnywhere, Category = Components)
	UStaticMeshComponent* GoldMesh;

	UPROPERTY(EditAnyWhere, Category = Stats)
	float MaxHealth = 100.f;
	UPROPERTY(EditAnyWhere, Category = Stats)
	float Health = 100.f;

	bool HasGold = false;

	void PickupGold();
	void DropGold();
	void ResetPlayer();

};
