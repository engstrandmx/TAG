// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CowCharacter.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EAiState : uint8
{
	VE_Wandering 	UMETA(DisplayName = "Wandering"),
	VE_Fleeing 		UMETA(DisplayName = "Fleeing"),
	VE_Flying		UMETA(DisplayName = "Flying"),
	VE_Floating		UMETA(DisplayName = "Floating")
};

UCLASS()
class TAG_API ACowCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACowCharacter();

	UPROPERTY(EditAnywhere)
	float RotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector LaunchVector;

	UPROPERTY(BlueprintReadWrite)
	float RotationHitForce;

	UPROPERTY(BlueprintReadWrite)
	bool bInAir;

	bool bVectorRotated;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool bOlleIsCute = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
