// Fill out your copyright notice in the Description page of Project Settings.

#include "Trigger.h"
#include "CowCharacter.h"
#include "CowAIController.h"

// Sets default values
ATrigger::ATrigger()
{
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(FName("Trigger Area"));
	TriggerBox->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ATrigger::BeginOverlap);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &ATrigger::EndOverlap);

	PrimaryActorTick.bCanEverTick = false;
	NeighborTriggerCount = 0;
	bIsStandOnTrigger = true;
}

void ATrigger::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(APawn::StaticClass())) {
		ActorsEntered++;
		TriggerEvent();

		FTriggerSignal Signal;
		Signal.bIsTriggered = true;
		Signal.bTriggerSequenceFinished = false;

		SendTriggerSignal(Signal);

		if (OtherActor->IsA(ACowCharacter::StaticClass())) {
			Cast<ACowAIController>(Cast<ACowCharacter>(OtherActor)->GetController())->GetBlackboardComponent()->SetValueAsBool(FName("StandingOnTrigger"), true);
		}
	}
}

void ATrigger::EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(APawn::StaticClass()) && bIsStandOnTrigger) {
		ActorsEntered--;

		if (ActorsEntered == 0) {
			bTriggered = false;
		}

		FTriggerSignal Signal;
		Signal.bIsTriggered = false;
		Signal.bTriggerSequenceFinished = false;
		SendTriggerSignal(Signal);

		OnLeave();

		if (OtherActor->IsA(ACowCharacter::StaticClass())) {
			Cast<ACowAIController>(Cast<ACowCharacter>(OtherActor)->GetController())->GetBlackboardComponent()->SetValueAsBool(FName("StandingOnTrigger"), false);
		}
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

void ATrigger::SendTriggerSignal(FTriggerSignal Signal) {
	int8 size = ConnectedTriggers.Num();

	//Send signal from trigger event to all connected triggers
	for (int8 i = 0; i < size; i++)
	{
		ConnectedTriggers[i]->ReceiveTriggerSignal(Signal);
	}
}

void ATrigger::ReceiveTriggerSignal(FTriggerSignal ReceivedSignal) {
	if (ReceivedSignal.bIsTriggered) {
		NeighborTriggerCount++;
	}
	else {
		NeighborTriggerCount--;
	}

	OnReceiveSignal(ReceivedSignal);
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

		FTriggerSignal Signal;
		Signal.bTriggerSequenceFinished = true;

		SendTriggerSignal(Signal);
		ReceiveTriggerSignal(Signal);

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

