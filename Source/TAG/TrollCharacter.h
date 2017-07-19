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
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Animations")
		FORCEINLINE bool GetIsPunching() { return bIsPunching || bPunchTimerStarted; }

	UPROPERTY(EditAnywhere, Transient, ReplicatedUsing = OnRep_IsPunching)
	bool bIsPunching;

protected:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void StopInteract();
	void Interact();

	UFUNCTION()
	void DelayedInteract();

	UFUNCTION(Server, Reliable, WithValidation)
	virtual void ServerStopInteract();
	virtual void ServerStopInteract_Implementation();
	virtual bool ServerStopInteract_Validate();

	UFUNCTION(Server, Reliable, WithValidation)
	virtual void ServerInteract();
	virtual void ServerInteract_Implementation();
	virtual bool ServerInteract_Validate();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:

	bool bPunchTimerStarted;

	UFUNCTION()
	void OnRep_IsPunching();

	UFUNCTION(Reliable, NetMulticast)
	void SimulateInteractFX();
	void SimulateInteractFX_Implementation();

	UPROPERTY(EditAnywhere, Category = Components)
	USphereComponent* InteractShape;

	bool EnemyIsOverlapping = false;

	UPROPERTY(EditAnywhere, Category = Stats)
	float Damage = 10.f;

	UPROPERTY(EditAnywhere, Category = Stats)
	float DamageRadius = 100.f;

	UPROPERTY(EditAnywhere, Category = Components)
	UParticleSystem* DamageParticles;
};
