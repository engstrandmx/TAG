// Fill out your copyright notice in the Description page of Project Settings.

#include "GnomeCharacter.h"
#include "TrollCharacter.h"
#include "TAGGameState.h"
#include "TAGPlayerState.h"
#include "TAGPlayerController.h"
#include "InteractSceneComponent.h"
#include "TAGGameMode.h"
#include "DestructibleSceneComponent.h"

AGnomeCharacter::AGnomeCharacter() {
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AGnomeCharacter::BeginOverlap);
	GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &AGnomeCharacter::EndOverlap);

	InteractShape = CreateDefaultSubobject<USphereComponent>(FName("Interact Shape"));
	InteractShape->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform);

	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;
	CarryMovementSpeed = 150;

	//CameraResetAlpha = 0;
}

void AGnomeCharacter::Tick(float DeltaSeconds) {

	Super::Tick(DeltaSeconds);

	CameraTick(DeltaSeconds);

}

void AGnomeCharacter::CameraTick(float DeltaSeconds) {
	
	if (ActorToLookAt != nullptr) {
		FTransform T = GetFollowCamera()->GetComponentTransform();
		
		FVector Loc = FMath::VInterpTo(T.GetLocation(), ActorToLookAt->GetActorLocation(), 0.5f * DeltaSeconds, CameraLookAtSpeed);
		FRotator Rot = FMath::RInterpTo(T.Rotator(), ActorToLookAt->GetActorRotation(), 0.5f * DeltaSeconds, CameraLookAtSpeed);

		GetFollowCamera()->SetWorldLocationAndRotation(Loc, Rot);
		//GetFollowCamera()->SetWorldLocationAndRotation(ActorToLookAt->GetActorLocation(), ActorToLookAt->GetActorRotation());
	}
	else if	(bResetCameraSlow) {
		
		//GetCameraBoom()->TargetArmLength = 

		FVector FromVector = GetFollowCamera()->RelativeLocation;
		FRotator FromRot = GetFollowCamera()->RelativeRotation;

		GetFollowCamera()->RelativeLocation = FMath::Lerp(FromVector, FVector::ZeroVector, CameraResetAlpha);
		GetFollowCamera()->RelativeRotation = FMath::Lerp(FromRot, FRotator::ZeroRotator, CameraResetAlpha);
		
		//GetFollowCamera()->RelativeRotation.Pitch = 0;
		//GetFollowCamera()->RelativeRotation.Yaw = FromRot.Yaw;
		//GetFollowCamera()->RelativeRotation.Roll = 0;

		//GetFollowCamera()->RelativeLocation.X = 0;
		//GetFollowCamera()->RelativeLocation.Y = 0;
		//GetFollowCamera()->RelativeLocation.Z = 0;
		
		CameraResetAlpha += DeltaSeconds * CameraTransitionSpeed;

		if (CameraResetAlpha >= 1) {
			//if (GEngine)
			//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Gnome Reset Slow"));
			CameraResetAlpha = 0;
			bResetCameraSlow = false;
		}
		
	}
	else if (bToogleMountCamera) {

		//if (GEngine)
		//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("toggle"));

		//GetFollowCamera()->control = false;

		FVector FromVector = GetFollowCamera()->RelativeLocation;
		FRotator FromRot = GetFollowCamera()->RelativeRotation;

		GetFollowCamera()->RelativeLocation = FMath::Lerp(FromVector, FVector::ZeroVector, CameraResetAlpha);
		GetFollowCamera()->RelativeRotation = FMath::Lerp(FromRot, FRotator::ZeroRotator, CameraResetAlpha);

		CameraResetAlpha += (DeltaSeconds * CameraTransitionSpeed) / 5;

		if (CameraResetAlpha >= 0.2f) {
			//if (GEngine)
			//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Gnome Toggle"));
			CameraResetAlpha = 0;
			bToogleMountCamera = false;
			//GetFollowCamera()->bUsePawnControlRotation = true;
		}
	}
	else if (bResetCamera)
	{
		FVector FromVector = GetFollowCamera()->RelativeLocation;
		FRotator FromRot = GetFollowCamera()->RelativeRotation;

		//GetFollowCamera()->RelativeLocation = FMath::Lerp(FromVector, FVector::ZeroVector, CameraResetAlpha);
		//GetFollowCamera()->RelativeRotation = FMath::Lerp(FromRot, FRotator::ZeroRotator, CameraResetAlpha);

		GetFollowCamera()->RelativeLocation = FVector::ZeroVector;
		GetFollowCamera()->RelativeRotation = FRotator::ZeroRotator;

		//CameraResetAlpha += DeltaSeconds * CameraTransitionSpeed;
		CameraResetAlpha = 1;

		if (CameraResetAlpha >= 1) {
			//if (GEngine)
			//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Gnome Reset"));
			CameraResetAlpha = 0;
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
// 			FVector ForceVector = (GetActorLocation() + FVector(0, 0, 100)) - DamageCauser->GetActorLocation();
// 			ForceVector.Normalize();

			OnHit();
			//LaunchCharacter(ForceVector * LaunchForce, true, false);
		}
		Health -= Damage;

		if (Health <= 0) {
// 			FVector ForceVector = (GetActorLocation() + FVector(0, 0, 100)) - DamageCauser->GetActorLocation();
// 			ForceVector.Normalize();

			//SimulateDeathFX(ForceVector);
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

	
	//if (Controller->IsA(ATAGPlayerController::StaticClass())) {
		//ServerResetPlayer(Controller);
		//SetActorLocation(InitialLocation);
	
	//else {
		//Health = MaxHealth;
		//SetActorLocation(InitialLocation);	
	//}
	
	
} 

void AGnomeCharacter::MountTroll()
{
	if (TrollParentActor) {
		ATrollCharacter* TrollActor = Cast<ATrollCharacter>(TrollParentActor);

		//Set the next camera to current camera location and start the camera reset function




		//TrollActor->GetFollowCamera()->SetWorldLocationAndRotation(GetFollowCamera()->GetComponentLocation(), GetFollowCamera()->GetComponentRotation());






		CameraTransitionSpeed = 1.25f; //1.25
		//TrollActor->ResetCamera();
		TrollActor->ResetCameraSlow();
		Controller->Possess(Cast<APawn>(TrollParentActor));

		/*
		float distance = FVector::Dist(TrollParentActor->GetActorLocation(), GetActorLocation());

		//If player is close enough the gnome will mount
		if (distance < MountDistance || bOverrideDistCheckOnMount) {
			CameraTransitionSpeed = 0.33f; //0.33
			//This function destroys the gnome and tells the troll to perform "mount" actions
			Cast<ATrollCharacter>(TrollParentActor)->MountGnome();
		}
		*/

		//Sets which actor is "active" to ensure correct respawns on death. In this case triggering the function will always set current player to troll, might change.
		Cast<ATAGGameMode>(UGameplayStatics::GetGameMode(GetWorld()))->SetCurrentPlayerType(EPlayerType::Troll);
		bOverrideDistCheckOnMount = false;
	}
}

void AGnomeCharacter::ActualMount()
{
	if (TrollParentActor) {

		float distance = FVector::Dist(TrollParentActor->GetActorLocation(), GetActorLocation());

		if (distance < MountDistance || bOverrideDistCheckOnMount) {

			ATrollCharacter* TrollActor = Cast<ATrollCharacter>(TrollParentActor);

			//Set the next camera to current camera location and start the camera reset function
			TrollActor->GetFollowCamera()->SetWorldLocationAndRotation(GetFollowCamera()->GetComponentLocation(), GetFollowCamera()->GetComponentRotation());
			CameraTransitionSpeed = 1.25f; //1.25
			TrollActor->ResetCameraSlow();
			//TrollActor->ToggleMountCamera();
			Controller->Possess(Cast<APawn>(TrollParentActor));

			CameraTransitionSpeed = 0.33f; //0.33
										   //This function destroys the gnome and tells the troll to perform "mount" actions
			Cast<ATrollCharacter>(TrollParentActor)->MountGnome();

			Cast<ATAGGameMode>(UGameplayStatics::GetGameMode(GetWorld()))->SetCurrentPlayerType(EPlayerType::Troll);
			bOverrideDistCheckOnMount = false;
		}
	}

}

void AGnomeCharacter::InstantMount()
{
	bOverrideDistCheckOnMount = true;
	MountTroll();
}

void AGnomeCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("SwitchState", IE_Pressed, this, &AGnomeCharacter::MountTroll);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AGnomeCharacter::Interact);

	PlayerInputComponent->BindAction("Headbutt", IE_Pressed, this, &AGnomeCharacter::Attack);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AGnomeCharacter::JumpPressed);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AGnomeCharacter::JumpReleased);

	PlayerInputComponent->BindAction("Mount", IE_Pressed, this, &AGnomeCharacter::ActualMount);

	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AGnomeCharacter::JumpPressed()
{
	/*
	if (bCanGlide) {
		bGlide = true;
	}
	*/

}

void AGnomeCharacter::JumpReleased()
{
	bGlide = false;
}

void AGnomeCharacter::Attack() {
	//Rest of logic is handled in BP, FinishAttack is called through montage notify
	OnAttack();
}

bool AGnomeCharacter::FinishAttack() {
	TArray<AActor*> OutActors;

	InteractShape->GetOverlappingActors(OutActors);

	int8 size = OutActors.Num();

	int8 actorsHit = 0;

	for (int8 i = 0; i < size; i++)
	{
		if (OutActors[i]->GetComponentByClass(UInteractSceneComponent::StaticClass())) {
			Cast<UInteractSceneComponent>(OutActors[i]->GetComponentByClass(UInteractSceneComponent::StaticClass()))->Attack(this, Damage);
			actorsHit++;
		}
		if (OutActors[i]->GetComponentByClass(UDestructibleSceneComponent::StaticClass())) {
			Cast<UDestructibleSceneComponent>(OutActors[i]->GetComponentByClass(UDestructibleSceneComponent::StaticClass()))->DestroyObject(Damage);
			actorsHit++;
		}
	}

	if (actorsHit != 0) {
		return true;
	}
	return false;
}

void AGnomeCharacter::Interact()
{
	OnInteract();

}

void AGnomeCharacter::FinishInteract() {
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