// Fill out your copyright notice in the Description page of Project Settings.

#include "Trigger.h"

// Sets default values
ATrigger::ATrigger()
{
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(FName("Trigger Area"));
	TriggerBox->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ATrigger::BeginOverlap);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &ATrigger::EndOverlap);

	PrimaryActorTick.bCanEverTick = false;

}

void ATrigger::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(APawn::StaticClass())) {
		TriggerEvent();
	}
}

void ATrigger::EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(APawn::StaticClass()) && bIsStandOnTrigger) {
		bTriggered = false;
	}
}

void ATrigger::BeginPlay()
{
	Super::BeginPlay();

	//Find all triggers in level, sorted by trigger group below
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATrigger::StaticClass(), FoundActors);

	int8 size = FoundActors.Num();

	//Checks for triggers with same tag and adds to array
	for (int8 i = 0; i < size; i++)
	{
		ATrigger* trigger;
		if (Cast<ATrigger>(FoundActors[i])) {
			trigger = Cast<ATrigger>(FoundActors[i]);

			//Checks if trigger is of same trigger group as self
			if (trigger->TriggerTag == TriggerTag) {
				ConnectedTriggers.Add(trigger);
			}
		}
	}
}

void ATrigger::TriggerEvent() {

	if (!bTriggered || !bTriggerOnce ) {
	
		OnTrigger();
		bTriggered = true;

		int8 size = ConnectedTriggers.Num();
	
		//Check if all connected triggers have fired, if not, function is stopped
		for (int8 i = 0; i < size; i++)
		{
			if (!ConnectedTriggers[i]->bTriggered) {
			
				return;
			}
		}

		//Goes through all connected triggers and checks for TriggerObjects, 
		//if found it will execute all triggers if any are found in said actors
		for (int8 i = 0; i < size; i++)
		{
			if (ConnectedTriggers[i]->TriggerObjects.Num() != 0) {

				int8 triggerObjectsSize = ConnectedTriggers[i]->TriggerObjects.Num();

				for (int8 t = 0; t < triggerObjectsSize; t++)
				{
					//Check for null reference in array, in case someone adds a bunch of empty array elements
					if (ConnectedTriggers[i]->TriggerObjects[t]) {

						if (ConnectedTriggers[i]->TriggerObjects[t]->GetComponentByClass(UTriggerActorComponent::StaticClass())) {
							Cast<UTriggerActorComponent>(ConnectedTriggers[i]->TriggerObjects[t]->GetComponentByClass(UTriggerActorComponent::StaticClass()))->OnTrigger.Broadcast();
						}
					}

				}

			}
		}

	}

}

