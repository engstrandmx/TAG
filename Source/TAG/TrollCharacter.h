// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GnomeCharacter.h"
#include "TAGCharacter.h"
#include "TAGPlayerController.h"
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

using namespace EPlayerType;

UCLASS()
class TAG_API ATrollCharacter : public ATAGCharacter
{
	GENERATED_BODY()

	ATrollCharacter();

	virtual void Tick(float DeltaSeconds);
	void CameraTick(float DeltaSeconds);

	//UFUNCTION()
	//void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Animations")
	FORCEINLINE bool GetIsPunching() { return bIsPunching; }

	UPROPERTY(EditAnywhere, Category = "Characters")
	TSubclassOf<APawn> GnomePawn; //Pawn to spawn when mounting

	void MountGnome(); //Called by gnome when mounting
	UFUNCTION(BlueprintCallable, Category = Mounting)
	void FinishMountGnome();

	PlayerType CurrentState; //If actor is mounted/dismounted

	UPROPERTY(EditAnywhere)
	bool bIsPunching; //When attack button is held down

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	FORCEINLINE void SetSpawnedPawn(AActor* ActorToSet) { SpawnedPawn = ActorToSet; }

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnHideMesh(bool Hidden); //Called to hide/unhide gnome mesh, BP EVENT

protected:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void HoldAttack();
	UFUNCTION(BlueprintCallable, Category = "Attack")
	void StopHoldAttack();
	void StopAttack(); //Stops attack, input function
	void Attack(); //Starts attack, input function

	UPROPERTY(BlueprintReadOnly, Category = "Attack")
	bool bHoldingAttack;

	UFUNCTION()
	void DelayedAttack();

	void Interact();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Components)
	USphereComponent* InteractShape;

	UFUNCTION(BlueprintCallable)
	void DealDamage(); //Function called the instant damage is to be dealt

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnAttack(); //Called when damage is dealt occurs, BP EVENT

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnMount(); //Called gnome returns to troll, BP EVENT

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnDismount(); //Called when gnome dismounts from troll, BP EVENT


	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnDeath();  //Called when troll dies

	UPROPERTY(BlueprintReadOnly)
	AActor* SpawnedPawn; //The reference to the gnome spawned when dismounting

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	FVector DismountOffset; //How offset away the dismounted gnome will appear

	UFUNCTION(BlueprintCallable)
	void FinishDismount(FVector Location);

private:

	int AttackCount; //How many attacks have occurred in montage

	bool bPunchTimerStarted;

	void ChangeState(PlayerType toState);
	void ToggleState();

	bool EnemyIsOverlapping = false;

	UPROPERTY(EditAnywhere, Category = Stats)
	float Damage = 10.f; //Damage dealt during attack

	UPROPERTY(EditAnywhere, Category = Stats)
	float DamageRadius = 100.f; //Radius of normal attack, used in conjuction with ApplyRadialDamage

	UPROPERTY(EditAnywhere, Category = Stats)
	float CurrentHealth = 100;

	UPROPERTY(EditAnywhere, Category = Stats)
	float MaxHealth = 100;

	UPROPERTY(EditAnywhere, Category = Components)
	UParticleSystem* DamageParticles;

	bool bIsMounting;
};
