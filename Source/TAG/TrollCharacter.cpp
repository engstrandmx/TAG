// Fill out your copyright notice in the Description page of Project Settings.

#include "TrollCharacter.h"

ATrollCharacter::ATrollCharacter() {

	//Create default shape
	InteractShape = CreateDefaultSubobject<USphereComponent>(FName("Interact Shape"));
	InteractShape->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform);
}

/*
ATrollCharacter::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{

}
*/

void ATrollCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ATrollCharacter::Interact);

	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATrollCharacter::Interact()
{
	UE_LOG(LogTemp, Warning, TEXT("Troll Interacting"));

	TSubclassOf <class UDamageType> DamageTypeClass;
	const TArray<AActor*> IgnoreActors;

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DamageParticles, GetActorForwardVector() * 100.f + GetActorLocation(), GetActorRotation(), true);

	UGameplayStatics::ApplyRadialDamage(GetWorld(), Damage, GetActorForwardVector() * 100.f + GetActorLocation(), DamageRadius, DamageTypeClass, IgnoreActors, this, GetController());
}
