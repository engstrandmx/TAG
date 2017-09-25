// Fill out your copyright notice in the Description page of Project Settings.

#include "GnomeCharacter.h"
#include "TrollCharacter.h"
#include "GoldPile.h"
#include "DropOffZone.h"
#include "TAGGameState.h"
#include "TAGPlayerState.h"
#include "TAGPlayerController.h"

AGnomeCharacter::AGnomeCharacter() {
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AGnomeCharacter::BeginOverlap);
	GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &AGnomeCharacter::EndOverlap);

	GoldMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Gold Object"));
	GoldMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	bReplicates = true;
	CarryMovementSpeed = 150;
}


void AGnomeCharacter::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) {

	if (OtherActor->IsA(AGoldPile::StaticClass())) {
		if (!GetWorld()->GetTimerManager().IsTimerActive(GoldTimerHandle) && !HasGold) {
			UE_LOG(LogTemp, Warning, TEXT("Timer started"));

			GetWorld()->GetTimerManager().SetTimer(GoldTimerHandle, this, &AGnomeCharacter::PickupGold, PickupTime);
		}

		bIsInGoldArea = true;

//		PickupGold();
	}
	else if (OtherActor->IsA(ADropOffZone::StaticClass())) {
		DropGold(true);
		GetWorld()->GetTimerManager().ClearTimer(GoldTimerHandle);
		bIsInGoldArea = false;
	}
	else
	{
		bIsInGoldArea = false;
	}
}


void AGnomeCharacter::EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	if (OtherActor->IsA(AGoldPile::StaticClass())) {

		GetWorld()->GetTimerManager().ClearTimer(GoldTimerHandle);

		bIsInGoldArea = false;
	}
}


void AGnomeCharacter::BeginPlay() {
	Super::BeginPlay();

	BaseMovementSpeed = GetCharacterMovement()->MaxWalkSpeed;

	GoldMesh->SetVisibility(false);

	InitialLocation = GetActorLocation();
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

			OnHit();
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

	return Health;
}

void AGnomeCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void AGnomeCharacter::ResetPlayer()
{
	OnDeath();

	DropGold(false);

	if (Controller->IsA(ATAGPlayerController::StaticClass())) {
		ServerResetPlayer(Controller);
	}
	else {
		Health = MaxHealth;
		SetActorLocation(InitialLocation);	
	}	
} 

void AGnomeCharacter::MountTroll()
{
	if (TrollParentActor) {
		float distance = FVector::Dist(TrollParentActor->GetActorLocation(), GetActorLocation());

		if (distance < MountDistance) {
			Cast<ATrollCharacter>(TrollParentActor)->MountGnome(this, Controller);
		}
	}
}

void AGnomeCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("SwitchState", IE_Pressed, this, &AGnomeCharacter::MountTroll);

	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGnomeCharacter::SimulateDeathFX_Implementation(FVector ForceVector)
{
	if (DeathEmitter) {
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DeathEmitter, GetTransform());
	}

	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->AddImpulse(ForceVector * LaunchForce);

	GetCameraBoom()->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);

	GetCameraBoom()->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepWorldTransform);
	//GetCameraBoom()->ProbeSize = 1.f;
	GetCameraBoom()->bDoCollisionTest = false;

}	

void AGnomeCharacter::PickupGold()
{
	if (!HasGold) {
		GoldMesh->SetVisibility(true);

		OnGoldPickup();

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


