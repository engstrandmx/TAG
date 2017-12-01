// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "TAGCharacter.h"
#include "Net/UnrealNetwork.h"
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

	virtual void Tick(float DeltaSeconds);

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
	UFUNCTION()
	void EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual void BeginPlay() override;
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	FORCEINLINE float GetMaxHealth() { return MaxHealth; }
	FORCEINLINE float GetHealth() { return Health; }
	FORCEINLINE float GetMountDistance() { return MountDistance; }
	void ResetPlayer();
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnDeath();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnHit();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnInteract();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnAttack();
	//DECLARE_EVENT(AGnomeCharacter, FChangedEvent)
	//FChangedEvent& OnGoldPickup();

	FORCEINLINE void SetTrollParent(AActor* Actor) { TrollParentActor = Actor; }
	void ResetCamera();
	void MountTroll();

	UFUNCTION(BlueprintCallable, Category = Functions)
	void FinishInteract();
	UFUNCTION(BlueprintCallable, Category = Functions)
	bool FinishAttack();

private:

	bool bResetCamera;

	AActor* TrollParentActor;

	UPROPERTY(EditAnywhere, Category = Stats)
	float LaunchForce = 1200.f;

	void Attack();

	void Interact();
	
	UFUNCTION(Reliable, NetMulticast )
	void SimulateDeathFX(FVector ForceVector);
	void SimulateDeathFX_Implementation(FVector ForceVector);

	UPROPERTY(EditAnywhere, Category = Components)
	UStaticMeshComponent* GoldMesh;
	UPROPERTY(EditAnywhere, Category = Components)
	UParticleSystem* DeathEmitter;

	UPROPERTY(EditAnywhere, Category = "Interact")
	USphereComponent* InteractShape;

	UPROPERTY(EditAnywhere, Category = Stats)
	float MountDistance = 130.f;

	UPROPERTY(EditAnyWhere, Category = Stats)
	float CarryMovementSpeed;
	float BaseMovementSpeed;

	UPROPERTY(EditAnyWhere, Category = Stats)
	float PickupTime = 1.f;

	FVector InitialLocation;

	float CameraResetAlpha = 0;

protected:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnyWhere, Category = Stats)
	float MaxHealth = 100.f;

	UPROPERTY(EditAnyWhere, Category = Damage)
	float Damage = 10.f;
};
