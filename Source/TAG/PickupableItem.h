

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "PickupableItem.generated.h"

UCLASS()
class TAG_API APickupableItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupableItem();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components)
	UBoxComponent* BoxCollisionComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Components)
	UParticleSystemComponent* IdleParticleComponent;

	UPROPERTY(EditAnywhere,	BlueprintReadWrite, Category = Effects)
	UParticleSystem* PickupParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	bool bEnableIdleRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	FRotator IdleRotation;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, Category = Pickup)
	void OnPickup();
	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
