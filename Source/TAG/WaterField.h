// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/SplineComponent.h"
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

	UFUNCTION(BlueprintCallable)
	void RemoveFromWaterActors(AActor* ActorToRemove);
	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	TArray<AActor*> FloatingActors;
	TArray<FVector> FloatingLocations;


	UPROPERTY(EditAnywhere)
	UBoxComponent* WaterFieldBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USplineComponent* SplineComponent;

	UFUNCTION(BlueprintImplementableEvent)
	void OnActorEnter(AActor* EnteringActor);

	UPROPERTY(EditAnywhere, Category = "Configuration")
	FVector CurrentVector;
	UPROPERTY(EditAnywhere, Category = "Configuration")
	FVector FloatSimulationMagnitude;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float WaterWidth = 300.f;

private:

	float alpha = 0;

	//Used to simulate a wave pattern on objects
	bool bPositiveWave = true;
	UPROPERTY(EditAnywhere)
	float WaveSimMult = 1;
	float WaveSimScalar = 0;
	float WaveSimAlpha = 0;
	UPROPERTY(EditAnywhere)
	float WaveMagnitude = 1;


	static FORCEINLINE bool Trace(
		UWorld* World,
		AActor* ActorToIgnore,
		const FVector& Start,
		const FVector& End,
		FHitResult& HitOut,
		ECollisionChannel CollisionChannel = ECC_Pawn,
		bool ReturnPhysMat = false
	) {
		if (!World)
		{
			return false;
		}

		FCollisionQueryParams TraceParams(FName(TEXT("VictoreCore Trace")), true, ActorToIgnore);
		TraceParams.bTraceComplex = true;
		//TraceParams.bTraceAsyncScene = true;
		TraceParams.bReturnPhysicalMaterial = ReturnPhysMat;

		//Ignore Actors
		TraceParams.AddIgnoredActor(ActorToIgnore);

		//Re-initialize hit info
		HitOut = FHitResult(ForceInit);

		//Trace!
		World->LineTraceSingleByChannel(
			HitOut,		//result
			Start,	//start
			End, //end
			CollisionChannel, //collision channel
			TraceParams
		);

		//Hit any Actor?
		return (HitOut.GetActor() != NULL);
	}
};
