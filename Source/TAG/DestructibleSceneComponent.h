

#pragma once

#include "Engine.h"
#include "Components/SceneComponent.h"
#include "DestructibleSceneComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TAG_API UDestructibleSceneComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UPROPERTY(EditAnywhere)
	float Health;

	UPROPERTY(EditAnywhere)
	bool bDestroyMesh;

	UPROPERTY(EditAnywhere)
	UParticleSystem* DeathParticleEmitter;

	UPROPERTY(EditAnywhere)
	UParticleSystem* HitParticleEmitter;
	// Sets default values for this component's properties
	UDestructibleSceneComponent();

	//Adds damage, if objects health drops below 0 it is destroyed. Returns true if destroyed, false if not
	UFUNCTION(BlueprintCallable)
	bool DestroyObject(float Damage);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	float CurrentHealth;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
	
};
