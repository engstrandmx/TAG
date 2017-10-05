// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "WaterField.generated.h"

UCLASS()
class TAG_API AWaterField : public AActor
{
	GENERATED_BODY()
	


public:	
	// Sets default values for this actor's properties
	AWaterField();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	TArray<AActor*> FloatingActors;
	TArray<FVector> FloatingLocations;


	UPROPERTY(EditAnywhere)
	UBoxComponent* WaterFieldBox;

	UFUNCTION(BlueprintImplementableEvent)
	void OnActorEnter(AActor* EnteringActor);

	UPROPERTY(EditAnywhere, Category = "Configuration")
	FVector CurrentVector;
	UPROPERTY(EditAnywhere, Category = "Configuration")
	FVector FloatSimulationMagnitude;

private:

	//Used to simulate a wave pattern on objects
	bool bPositiveWave = true;
	UPROPERTY(EditAnywhere)
	float WaveSimMult = 1;
	float WaveSimScalar = 0;
	float WaveSimAlpha = 0;
	UPROPERTY(EditAnywhere)
	float WaveMagnitude = 1;
};
