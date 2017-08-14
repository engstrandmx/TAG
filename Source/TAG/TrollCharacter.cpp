// Fill out your copyright notice in the Description page of Project Settings.

#include "TrollCharacter.h"

ATrollCharacter::ATrollCharacter() {

	//Create default shape
	InteractShape = CreateDefaultSubobject<USphereComponent>(FName("Interact Shape"));
	InteractShape->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform);

	bReplicates = true;
	AttackCount = 0;
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
	PlayerInputComponent->BindAction("Interact", IE_Released, this, &ATrollCharacter::StopInteract);

	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATrollCharacter::StopInteract() {

	if (Role < ROLE_Authority) {
		ServerStopInteract();
	}
	else {
		bIsPunching = false;
		//GetWorld()->GetTimerManager().ClearTimer(InteractHandle);
	}

}

void ATrollCharacter::ServerStopInteract_Implementation()
{
	StopInteract();
}

bool ATrollCharacter::ServerStopInteract_Validate()
{
	return true;
}

void ATrollCharacter::Interact()
{
	if (Role < ROLE_Authority) {
		ServerInteract();
	}
	else {
		bPunchTimerStarted = true;

		if (!bIsPunching) {
			OnAttack();
		}

		bIsPunching = true;


	}
}

void ATrollCharacter::DelayedInteract()
{
	SimulateInteractFX();

	TSubclassOf <class UDamageType> DamageTypeClass;
	const TArray<AActor*> IgnoreActors;

	UGameplayStatics::ApplyRadialDamage(GetWorld(), Damage, GetActorForwardVector() * 100.f + GetActorLocation(), DamageRadius, DamageTypeClass, IgnoreActors, this, GetController());

	bPunchTimerStarted = false;
}

void ATrollCharacter::ServerDealDamage_Implementation(){
	DealDamage();
}

bool ATrollCharacter::ServerDealDamage_Validate() {
	return true;
}

void ATrollCharacter::DealDamage() {
	if (Role < ROLE_Authority) {
		ServerDealDamage();
	}
	else {
		AttackCount++;

		SimulateInteractFX();

		TSubclassOf <class UDamageType> DamageTypeClass;
		const TArray<AActor*> IgnoreActors;

		UGameplayStatics::ApplyRadialDamage(GetWorld(), Damage, GetActorForwardVector() * 100.f + GetActorLocation(), DamageRadius, DamageTypeClass, IgnoreActors, this, GetController());

		if (AttackCount >= 2) {
			StopInteract();
		}
	}

}

void ATrollCharacter::ServerInteract_Implementation()
{
	Interact();
}

bool ATrollCharacter::ServerInteract_Validate()
{
	return true;
}

void ATrollCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATrollCharacter, bIsPunching);
}

void ATrollCharacter::OnRep_IsPunching()
{

}

void ATrollCharacter::SimulateInteractFX_Implementation()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DamageParticles, GetActorForwardVector() * 100.f + GetActorLocation(), GetActorRotation(), true);
}
