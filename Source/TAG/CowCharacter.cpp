// Fill out your copyright notice in the Description page of Project Settings.

#include "CowCharacter.h"


// Sets default values
ACowCharacter::ACowCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bInAir = false;
	bVectorRotated = false;
	LaunchVector = FVector::ZeroVector;

}

// Called when the game starts or when spawned
void ACowCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACowCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bInAir) {
		if (!bVectorRotated) {
			bVectorRotated = true;
			LaunchVector = FVector::CrossProduct(LaunchVector, FVector(0, 0, 1));
		}

		UE_LOG(LogTemp, Warning, TEXT("Vector %s"), *LaunchVector.ToString());

		SetActorRotation(GetActorRotation() + FQuat(LaunchVector, RotationSpeed).Rotator());
	}

	else {
		bVectorRotated = false;

		SetActorRotation(FMath::Lerp(GetActorRotation(), FRotator(0, GetActorRotation().Yaw, 0), 0.95f));
	}

}

// Called to bind functionality to input
void ACowCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

