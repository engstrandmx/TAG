// Fill out your copyright notice in the Description page of Project Settings.

#include "CowCharacter.h"
#include <DrawDebugHelpers.h>


// Sets default values
ACowCharacter::ACowCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bInAir = false;
	bVectorRotated = false;
	LaunchVector = FVector::ZeroVector;
	RotationHitForce = 0.5f;
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
			LaunchVector.Normalize();
			LaunchVector = FVector::CrossProduct(LaunchVector, FVector(0, 0, 1));
		}
// 			DrawDebugLine(
// 				GetWorld(),
// 				GetActorLocation(),
// 				GetActorLocation() + LaunchVector * 500,
// 				FColor(255, 0, 0),
// 				true, -1, 0,
// 				12.333
// 			);
		

		SetActorRotation(FMath::Lerp(GetActorRotation().Quaternion(), GetActorRotation().Quaternion() * FQuat(LaunchVector, -RotationSpeed), 0.2f * RotationHitForce));
	}

	else {
		bVectorRotated = false;

		SetActorRotation(FMath::Lerp(GetActorRotation(), FRotator(0, GetActorRotation().Yaw, 0), 0.2f));
	}

}

// Called to bind functionality to input
void ACowCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

