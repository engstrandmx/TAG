// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GnomeCharacter.h"
#include "TAGCharacter.h"
#include "TrollCharacter.generated.h"

UENUM(BlueprintType)
namespace EPlayerState
{
	enum State
	{
		Mounted			UMETA(DisplayName = "Mounted"),
		Gnome			UMETA(DisplayName = "Gnome"),
	};
}

using namespace EPlayerState;

UCLASS()
class TAG_API ATrollCharacter : public ATAGCharacter
{
	GENERATED_BODY()

	ATrollCharacter();

	//UFUNCTION()
	//void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Animations")
	FORCEINLINE bool GetIsPunching() { return bIsPunching; }

	UPROPERTY(EditAnywhere, Category = "Characters")
	TSubclassOf<APawn> GnomePawn; //Pawn to spawn when mounting

	void MountGnome(AActor* MountingActor, AController* Controller); //Called by gnome when mounting

	State CurrentState; //If actor is mounted/dismounted

	UPROPERTY(EditAnywhere, Transient, ReplicatedUsing = OnRep_IsPunching)
	bool bIsPunching; //When attack button is held down

protected:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void StopInteract(); //Stops attack, input function
	void Interact(); //Starts attack, input function

	UFUNCTION()
	void DelayedInteract();

	//TODO: remove
	UFUNCTION(Server, Reliable, WithValidation)
	virtual void ServerStopInteract();
	virtual void ServerStopInteract_Implementation();
	virtual bool ServerStopInteract_Validate();

	//TODO: remove
	UFUNCTION(Server, Reliable, WithValidation)
	virtual void ServerInteract();
	virtual void ServerInteract_Implementation();
	virtual bool ServerInteract_Validate();


	//TODO: remove
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerDealDamage();
	void ServerDealDamage_Implementation();
	bool ServerDealDamage_Validate();

	UFUNCTION(BlueprintCallable)
	void DealDamage(); //Function called the instant damage is to be dealt

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnAttack(); //Called when damage is dealt occurs, BP EVENT

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnMount(); //Called gnome returns to troll, BP EVENT

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnDismount(); //Called when gnome dismounts from troll, BP EVENT

private:

	AActor* SpawnedPawn; //The reference to the gnome spawned when dismounting
	int AttackCount; //How many attacks have occurred in montage
	FTimerHandle InteractHandle;

	bool bPunchTimerStarted;

	UFUNCTION()
	void OnRep_IsPunching();

	UFUNCTION(Reliable, NetMulticast)
	void SimulateInteractFX();
	void SimulateInteractFX_Implementation();

	void ChangeState(State toState);
	void ToggleState();
	UPROPERTY(EditAnywhere, Category = Components)
	USphereComponent* InteractShape;

	bool EnemyIsOverlapping = false;

	UPROPERTY(EditAnywhere, Category = Stats)
	float DismountDistance = 200.f; //How far away the dismounted gnome will appear

	UPROPERTY(EditAnywhere, Category = Stats)
	float Damage = 10.f; //Damage dealt during attack

	UPROPERTY(EditAnywhere, Category = Stats)
	float DamageRadius = 100.f; //Radius of normal attack, used in conjuction with ApplyRadialDamage

	UPROPERTY(EditAnywhere, Category = Components)
	UParticleSystem* DamageParticles;
};
