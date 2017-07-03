// Fill out your copyright notice in the Description page of Project Settings.

#include "GnomeCharacter.h"
#include "TrollCharacter.h"
#include "GoldPile.h"
#include "DropOffZone.h"
#include "TAGPlayerState.h"

AGnomeCharacter::AGnomeCharacter() {
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AGnomeCharacter::BeginOverlap);

	GoldMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Gold Object"));
	GoldMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void AGnomeCharacter::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) {

	if (OtherActor->IsA(AGoldPile::StaticClass())) {
		PickupGold();
	}
	else if (OtherActor->IsA(ADropOffZone::StaticClass())) {
		DropGold();
	}
};

void AGnomeCharacter::BeginPlay() {
	Super::BeginPlay();
	ATAGPlayerState* State = Cast<ATAGPlayerState>(PlayerState);

	State->InitStats(this);

	GoldMesh->SetVisibility(false);
}

void AGnomeCharacter::ReceiveAnyDamage(float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	if (DamageCauser->IsA(ATrollCharacter::StaticClass())) {
		ATAGPlayerState* State = Cast<ATAGPlayerState>(PlayerState);
		
		State->ReceiveDamage(Damage);

		if (Health < 0) {
			ResetPlayer();
		}
	}

}

void AGnomeCharacter::PickupGold()
{
	if (!HasGold) {
		GoldMesh->SetVisibility(true);

		HasGold = true;
	}
}

void AGnomeCharacter::DropGold()
{
	GoldMesh->SetVisibility(false);
	HasGold = false;
}

void AGnomeCharacter::ResetPlayer()
{
}

