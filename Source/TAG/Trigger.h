// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "TriggerActorComponent.h"
#include "Trigger.generated.h"

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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION()
	void TriggerEvent();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTrigger();

	UPROPERTY(BlueprintReadOnly, Category = "Trigger Info")
	int ActorsEntered;

protected:
	//If trigger fires it will not toggle off unless it is a stand on trigger
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Trigger Type")
	bool bTriggerOnce = true;

	//Only fires when actor is standing on trigger, not triggered when actor leaves
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Trigger Type")
	bool bIsStandOnTrigger;

	float TimeToTrigger;


};
