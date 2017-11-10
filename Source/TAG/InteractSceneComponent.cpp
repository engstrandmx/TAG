

#include "InteractSceneComponent.h"


// Sets default values for this component's properties
UInteractSceneComponent::UInteractSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UInteractSceneComponent::Interact(AActor* TriggeringActor)
{
	OnInteract.Broadcast(TriggeringActor);
}


