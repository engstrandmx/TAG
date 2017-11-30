// Fill out your copyright notice in the Description page of Project Settings.

#include "GnomeCharacter.h"
#include "TrollCharacter.h"
#include "TAGGameState.h"
#include "TAGPlayerState.h"
#include "TAGPlayerController.h"
#include "InteractSceneComponent.h"
#include "TAGGameMode.h"

AGnomeCharacter::AGnomeCharacter() {
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AGnomeCharacter::BeginOverlap);
	GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &AGnomeCharacter::EndOverlap);

	InteractShape = CreateDefaultSubobject<USphereComponent>(FName("Interact Shape"));
	InteractShape->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform);

	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;
	CarryMovementSpeed = 150;

	CameraResetAlpha = 0;
}

void AGnomeCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (bResetCamera) {
		FVector FromVector = GetFollowCamera()->RelativeLocation;
		FRotator FromRot = GetFollowCamera()->RelativeRotation;

		GetFollowCamera()->RelativeLocation = FMath::Lerp(FromVector, FVector::ZeroVector, CameraResetAlpha);
		GetFollowCamera()->RelativeRotation = FMath::Lerp(FromRot, FRotator::ZeroRotator, CameraResetAlpha);

		CameraResetAlpha += DeltaSeconds * CameraTransitionSpeed;

		if (CameraResetAlpha >= 1) {
			bResetCamera = false;
		}
	}
}

void AGnomeCharacter::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) {
}

void AGnomeCharacter::EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AGnomeCharacter::BeginPlay() {
	Super::BeginPlay();

	BaseMovementSpeed = GetCharacterMovement()->MaxWalkSpeed;

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

	if (Controller->IsA(ATAGPlayerController::StaticClass())) {
		ServerResetPlayer(Controller);
	}
	else {
		Health = MaxHealth;
		SetActorLocation(InitialLocation);	
	}	
} 

void AGnomeCharacter::ResetCamera()
{
	bResetCamera = true;
	CameraResetAlpha = 0;
}

void AGnomeCharacter::MountTroll()
{
	if (TrollParentActor) {
		ATrollCharacter* TrollActor = Cast<ATrollCharacter>(TrollParentActor);

		//Set the next camera to current camera location and start the camera reset function
		TrollActor->GetFollowCamera()->SetWorldLocationAndRotation(GetFollowCamera()->GetComponentLocation(), GetFollowCamera()->GetComponentRotation());
		CameraTransitionSpeed = 1.25f;
		TrollActor->ResetCamera();
		Controller->Possess(Cast<APawn>(TrollParentActor));

		float distance = FVector::Dist(TrollParentActor->GetActorLocation(), GetActorLocation());

		//If player is close enough the gnome will mount
		if (distance < MountDistance) {
			CameraTransitionSpeed = 0.33f;
			//This function destroys the gnome and tells the troll to perform "mount" actions
			Cast<ATrollCharacter>(TrollParentActor)->MountGnome();
		}

		//Sets which actor is "active" to ensure correct respawns on death. In this case triggering the function will always set current player to troll, might change.
		Cast<ATAGGameMode>(UGameplayStatics::GetGameMode(GetWorld()))->SetCurrentPlayerType(EPlayerType::Troll);
	}
}

void AGnomeCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("SwitchState", IE_Pressed, this, &AGnomeCharacter::MountTroll);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AGnomeCharacter::Interact);


	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGnomeCharacter::Interact()
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