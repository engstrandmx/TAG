// Fill out your copyright notice in the Description page of Project Settings.

#include "TrollCharacter.h"
#include "GnomeCharacter.h"
#include "InteractSceneComponent.h"
#include "TAGGameMode.h"

ATrollCharacter::ATrollCharacter() {

	//Create default shape
	InteractShape = CreateDefaultSubobject<USphereComponent>(FName("Interact Shape"));
	InteractShape->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform);

	bReplicates = true;
	AttackCount = 0;
}

void ATrollCharacter::MountGnome(AActor* MountingActor, AController* Controller)
{
	if (Controller) {
		Controller->Possess(this);
	}

	if (MountingActor){
		MountingActor->Destroy();
	}
	ChangeState(EPlayerType::Troll);
}

float ATrollCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	CurrentHealth -= Damage;

	if (CurrentHealth <= 0) {
		OnDeath();
		ServerResetPlayer(Controller);
	}

	return CurrentHealth;
}

void ATrollCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ATrollCharacter::Attack);
	PlayerInputComponent->BindAction("Attack", IE_Released, this, &ATrollCharacter::StopAttack);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ATrollCharacter::Interact);

	PlayerInputComponent->BindAction("SwitchState", IE_Pressed, this, &ATrollCharacter::ToggleState);

	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATrollCharacter::StopAttack() {

	if (Role < ROLE_Authority) {
		ServerStopAttack();
	}
	else {
		bIsPunching = false;
		//GetWorld()->GetTimerManager().ClearTimer(InteractHandle);
	}
}

void ATrollCharacter::ServerStopAttack_Implementation()
{
	StopAttack();
}

bool ATrollCharacter::ServerStopAttack_Validate()
{
	return true;
}

void ATrollCharacter::Attack()
{
	if (Role < ROLE_Authority) {
		ServerAttack();
	}
	else {
		bPunchTimerStarted = true;

		if (!bIsPunching) {
			OnAttack();
		}
		bIsPunching = true;
	}
}

void ATrollCharacter::DelayedAttack()
{
	SimulateAttackFX();

// 	TSubclassOf <class UDamageType> DamageTypeClass;
// 	const TArray<AActor*> IgnoreActors;
// 
// 	UGameplayStatics::ApplyRadialDamage(GetWorld(), Damage, GetActorForwardVector() * 100.f + GetActorLocation(), DamageRadius, DamageTypeClass, IgnoreActors, this, GetController());

	bPunchTimerStarted = false;
}

void ATrollCharacter::ServerDealDamage_Implementation(){
	DealDamage();
}

bool ATrollCharacter::ServerDealDamage_Validate() {
	return true;
}

void ATrollCharacter::Interact()
{
	TArray<AActor*> OutActors;

	InteractShape->GetOverlappingActors(OutActors);

	int8 size = OutActors.Num();

	for (int8 i = 0; i < size; i++)
	{
		if (OutActors[i]->GetComponentByClass(UInteractSceneComponent::StaticClass())) {
			Cast<UInteractSceneComponent>(OutActors[i]->GetComponentByClass(UInteractSceneComponent::StaticClass()))->Interact(this);
		}
	}
}

void ATrollCharacter::DealDamage() {
	if (Role < ROLE_Authority) {
		ServerDealDamage();
	}
	else {
		AttackCount++;

		SimulateAttackFX();

// 		TSubclassOf <class UDamageType> DamageTypeClass;
// 		const TArray<AActor*> IgnoreActors;
//
//		UGameplayStatics::ApplyRadialDamage(GetWorld(), Damage, GetActorForwardVector() * 100.f + GetActorLocation(), DamageRadius, DamageTypeClass, IgnoreActors, this, GetController());

		if (AttackCount >= 2) {
			StopAttack();
		}
	}
}

void ATrollCharacter::ServerAttack_Implementation()
{
	Attack();
}

bool ATrollCharacter::ServerAttack_Validate()
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

void ATrollCharacter::SimulateAttackFX_Implementation()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DamageParticles, GetActorForwardVector() * 100.f + GetActorLocation(), GetActorRotation(), true);
}

void ATrollCharacter::ChangeState(PlayerType toState) 
{
	CurrentState = toState;

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Instigator = this;
	SpawnParameters.Owner = GetController();

	FQuat rotation = GetActorRotation().Quaternion();
	FVector offset = rotation * DismountOffset;

	switch (toState)
	{
	case EPlayerType::Troll:
		OnMount();

		break;
	case EPlayerType::Gnome:
		SpawnedPawn = GetWorld()->SpawnActor<AGnomeCharacter>(GnomePawn, GetActorLocation() + offset, GetActorRotation(), SpawnParameters);

		Cast<AGnomeCharacter>(SpawnedPawn)->SetTrollParent(this);
		Controller->Possess(Cast<APawn>(SpawnedPawn));

		Cast<ATAGGameMode>(UGameplayStatics::GetGameMode(GetWorld()))->SetCurrentGnome(Cast<AGnomeCharacter>(SpawnedPawn));

		OnDismount();
		break;
	default:
		break;
	}

	Cast<ATAGGameMode>(UGameplayStatics::GetGameMode(GetWorld()))->SetCurrentPlayerType(toState);

}

void ATrollCharacter::ToggleState() {
	switch (CurrentState)
	{
	case EPlayerType::Troll:
		ChangeState(EPlayerType::Gnome);
		break;
	case EPlayerType::Gnome:
		ChangeState(EPlayerType::Troll);

		break;
	default:
		break;
	}
}
