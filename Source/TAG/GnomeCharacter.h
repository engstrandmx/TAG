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

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
	UFUNCTION()
	void EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


	virtual void BeginPlay() override;
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	FORCEINLINE float GetMaxHealth() { return MaxHealth; }
	FORCEINLINE float GetHealth() { return Health; }

	void ResetPlayer();
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE bool GetInGoldArea() { return bIsInGoldArea; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetGoldTimeLeft() { return GetWorld()->GetTimerManager().GetTimerRemaining(GoldTimerHandle); }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetGoldTimeMax() { return PickupTime; }

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnGoldPickup();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnDeath();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnHit();
	//DECLARE_EVENT(AGnomeCharacter, FChangedEvent)
	//FChangedEvent& OnGoldPickup();

private:

	FTimerHandle GoldTimerHandle;
	bool bIsInGoldArea;

	UPROPERTY(EditAnywhere, Category = Stats)
	float LaunchForce = 1200.f;

	UFUNCTION(Reliable, NetMulticast )
	void SimulateDeathFX(FVector ForceVector);
	void SimulateDeathFX_Implementation(FVector ForceVector);


	UPROPERTY(EditAnywhere, Category = Components)
	UStaticMeshComponent* GoldMesh;
	UPROPERTY(EditAnywhere, Category = Components)
	UParticleSystem* DeathEmitter;

	bool HasGold = false;
	UPROPERTY(EditAnyWhere, Category = Stats)
	float CarryMovementSpeed;
	float BaseMovementSpeed;

	UPROPERTY(EditAnyWhere, Category = Stats)
	float PickupTime = 1.f;

	void PickupGold();
	void DropGold(bool Score);

	FVector InitialLocation;

protected:
	UPROPERTY(EditAnyWhere, Category = Stats)
	float MaxHealth = 100.f;

};
