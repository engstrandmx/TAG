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

	bReplicates = true;
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

	//UE_LOG(LogTemp, Warning, TEXT("Damage from troll received"));

	if (Role < ROLE_Authority) {
		ServerTakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	}
	else {
		if (DamageCauser) {
			FVector ForceVector = (GetActorLocation() + FVector(0, 0, 100)) - DamageCauser->GetActorLocation();
			ForceVector.Normalize();

			LaunchCharacter(ForceVector * LaunchForce, true, false);
		}
		Health -= Damage;

		if (Health <= 0) {
			FVector ForceVector = (GetActorLocation() + FVector(0, 0, 100)) - DamageCauser->GetActorLocation();
			ForceVector.Normalize();

			SimulateDeathFX(ForceVector);
			ResetPlayer();
		}
	}

	//Null check, in case actor data is not sent when damage is dealt
	return Health;
}

void AGnomeCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void AGnomeCharacter::ResetPlayer()
{
	DropGold(false);

	ServerResetPlayer(Controller);
}

void AGnomeCharacter::SimulateDeathFX_Implementation(FVector ForceVector)
{
	if (DeathEmitter) {
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DeathEmitter, GetTransform());
	}

	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->AddImpulse(ForceVector * LaunchForce);

	GetCameraBoom()->DetachFromParent(true);

	GetCameraBoom()->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepWorldTransform);
	//GetCameraBoom()->ProbeSize = 1.f;
	GetCameraBoom()->bDoCollisionTest = false;

}	

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


