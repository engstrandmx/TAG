// Fill out your copyright notice in the Description page of Project Settings.

#include "GnomeCharacter.h"
#include "TrollCharacter.h"
#include "GoldPile.h"
#include "DropOffZone.h"
#include "TAGGameState.h"
#include "TAGPlayerState.h"

AGnomeCharacter::AGnomeCharacter() {
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AGnomeCharacter::BeginOverlap);

	GoldMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Gold Object"));
	GoldMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	CarryMovementSpeed = 150;
}

void AGnomeCharacter::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) {


	if (OtherActor->IsA(AGoldPile::StaticClass())) {
		PickupGold();
	}
	else if (OtherActor->IsA(ADropOffZone::StaticClass())) {
		DropGold(true);
	}
};

void AGnomeCharacter::BeginPlay() {
	Super::BeginPlay();

	BaseMovementSpeed = GetCharacterMovement()->MaxWalkSpeed;

	GoldMesh->SetVisibility(false);
}

float AGnomeCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	//UE_LOG(LogTemp, Warning, TEXT("Damage received"));

	//if (DamageCauser->IsA(ATrollCharacter::StaticClass())) {
		//UE_LOG(LogTemp, Warning, TEXT("Damage from troll received"));

	//Null check, in case actor data is not sent when damage is dealt
	if (DamageCauser) {
		FVector ForceVector = (GetActorLocation() + FVector(0, 0, 40)) - DamageCauser->GetActorLocation();
		ForceVector.Normalize();

		LaunchCharacter(ForceVector * 1200.f, true, false);
	}
		Health -= Damage;

	if (Health <= 0) {
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DeathEmitter, GetTransform());

		ResetPlayer();
	}

	return Health;
}

void AGnomeCharacter::ResetPlayer()
{
	DropGold(false);

	ServerResetPlayer(Controller);
}
/*
void AGnomeCharacter::ServerResetPlayer(AController* InController) {
	GetWorld()->GetAuthGameMode()->RestartPlayer(InController);
}


bool AGnomeCharacter::ServerResetPlayer_Validate(AController* InController) {
	//TODO: Check if call is legit
	return true;
}

void AGnomeCharacter::ServerResetPlayer_Implementation(AController* InController)
{
}
*/

void AGnomeCharacter::PickupGold()
{
	if (!HasGold) {
		GoldMesh->SetVisibility(true);

		HasGold = true;
		GetCharacterMovement()->MaxWalkSpeed = CarryMovementSpeed;
	}
}

void AGnomeCharacter::DropGold(bool Score)
{
	if (HasGold) {
		if (Score) {
			GetWorld()->GetGameState<ATAGGameState>()->ScoreGold();
		}

		GetCharacterMovement()->MaxWalkSpeed = BaseMovementSpeed;
		GoldMesh->SetVisibility(false);
		HasGold = false;
	}

}


