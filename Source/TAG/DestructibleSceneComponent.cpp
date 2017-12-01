

#include "DestructibleSceneComponent.h"


// Sets default values for this component's properties
UDestructibleSceneComponent::UDestructibleSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bDestroyMesh = true;

	Health = 10;
	// ...
}

void UDestructibleSceneComponent::DestroyObject(float Damage)
{
	CurrentHealth -= Damage;

	if (ParticleEmitter) {
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleEmitter, GetComponentTransform(), true);
	}
	
	if (bDestroyMesh && CurrentHealth <= 0) {
		GetAttachmentRootActor()->Destroy();
	}
}

// Called when the game starts
void UDestructibleSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = Health;
	// ...
}


// Called every frame
void UDestructibleSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

