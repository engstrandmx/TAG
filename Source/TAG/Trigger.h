// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "TriggerActorComponent.h"
#include "Trigger.generated.h"

USTRUCT(BlueprintType)
struct FTriggerSignal {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trigger Struct")
	bool bTriggerSequenceFinished;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trigger Struct")
	bool bIsTriggered;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trigger Struct")
	bool Testing;
};

UCLASS()
class TAG_API ATrigger : public AActor
{
	GENERATED_BODY()


public:	

	ATrigger();
	
	UPROPERTY(EditAnywhere)
	UBoxComponent* TriggerBox;

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
	UFUNCTION()
	void EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	//Objects to be affected when trigger fires
	UPROPERTY(EditAnywhere, Category = "Trigger Parameters")
	TArray<AActor*> TriggerObjects; 

	//Triggers with same tag all need to be activated to work
	UPROPERTY(EditAnywhere, Category = "Trigger Parameters")
	FString TriggerTag; 

	TArray<ATrigger*> ConnectedTriggers;

	//Whether the trigger has fired
	UPROPERTY(EditAnywhere, Category = "Trigger Parameters")
	bool bTriggered;

	//Whether the trigger should start disabled, if disabled it will need to be activated from another trigger
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Trigger Parameters")
	bool bDisabled;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Trigger Status")
	bool bTriggerFinished;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SendTriggerSignal(FTriggerSignal Signal);
	void ReceiveTriggerSignal(FTriggerSignal ReceivedSignal);
public:
	UFUNCTION()
	void TriggerEvent();

	UFUNCTION(BlueprintImplementableEvent, Category = "Trigger Events")
	void OnTrigger();

	UFUNCTION(BlueprintImplementableEvent, Category = "Trigger Events")
	void OnReceiveSignal(FTriggerSignal Signal);

	UFUNCTION(BlueprintImplementableEvent, Category = "Trigger Events")
	void OnLeave();

	UPROPERTY(BlueprintReadOnly, Category = "Trigger Status")
	int ActorsEntered;

protected:
	//If trigger fires it will not toggle off unless it is a stand on trigger
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Trigger Parameters")
	bool bTriggerOnce = true;

	//Fires once when actor is standing on trigger, not triggered when actor leaves
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Trigger Parameters")
	bool bIsStandOnTrigger;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Trigger Status")
	int NeighborTriggerCount;

	float TimeToTrigger;


};
