// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TAGCharacter.h"
#include "Kismet/HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "TAGGameMode.h"

//////////////////////////////////////////////////////////////////////////
// ATAGCharacter

ATAGCharacter::ATAGCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f; //45
	BaseLookUpRate = 45.f; //45

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate	540
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<UCustomSpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	InitialHeightZ = CameraBoom->RelativeLocation.Z;
	ZoomInZ = InitialHeightZ - 140; //140

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, UCustomSpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = true; // Camera does not rotate relative to arm

	PrimaryActorTick.bCanEverTick = true;

	bCanMove = true;
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void ATAGCharacter::ResetCamera()
{
	bResetCameraSlow = true;
	CameraResetAlpha = 0;
}

void ATAGCharacter::ResetCameraSlow()
{
	bResetCameraSlow = true;
	CameraResetAlpha = 0;
}

void ATAGCharacter::ToggleMountCamera()
{
	bToogleMountCamera = true;
	CameraResetAlpha = 0;
}

//////////////////////////////////////////////////////////////////////////
// Input

void ATAGCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);


	PlayerInputComponent->BindAxis("MoveForward", this, &ATAGCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATAGCharacter::MoveRight);

	PlayerInputComponent->BindAction("ScrollUp", IE_Pressed, this, &ATAGCharacter::ZoomIn);
	PlayerInputComponent->BindAction("ScrollDown", IE_Pressed, this, &ATAGCharacter::ZoomOut);

	PlayerInputComponent->BindAction("ZoomIn", IE_Pressed, this, &ATAGCharacter::ZoomInHeld);
	PlayerInputComponent->BindAction("ZoomIn", IE_Released, this, &ATAGCharacter::ZoomInReleased);

	PlayerInputComponent->BindAction("ZoomOut", IE_Pressed, this, &ATAGCharacter::ZoomOutHeld);
	PlayerInputComponent->BindAction("ZoomOut", IE_Released, this, &ATAGCharacter::ZoomOutReleased);


	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ATAGCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::	AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ATAGCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ATAGCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ATAGCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ATAGCharacter::OnResetVR);

}

void ATAGCharacter::LookAtActor(AActor* Actor, float Time, float Speed, bool FuckYou) {
	ActorToLookAt = Actor;
	CameraLookAtSpeed = Speed;

	FTimerHandle LookAtTimeHandle;
	FTimerDelegate TimerDel;

	UE_LOG(LogTemp, Warning, TEXT("Time is %f"), Time)

	TimerDel.BindLambda([&]()
	{
		StopLookAt();
	});

	GetWorldTimerManager().SetTimer(LookAtTimeHandle, TimerDel, Time, false);
}

void ATAGCharacter::StopLookAt() {
	ActorToLookAt = nullptr;
}

void ATAGCharacter::ZoomIn() {
	Zoom(-15);
}
void ATAGCharacter::ZoomOut() {
	Zoom(15);
}
void ATAGCharacter::ZoomInHeld(){
	bZoomIn = true;
}
void ATAGCharacter::ZoomInReleased(){
	bZoomIn = false;

}
void ATAGCharacter::ZoomOutHeld(){
	bZoomOut = true;

}
void ATAGCharacter::ZoomOutReleased(){
	bZoomOut = false;
}
void ATAGCharacter::Zoom(float Value)
{
	float val = CameraBoom->TargetArmLength;
	val += Value * 2.5f;


	val = FMath::Clamp(val, 200.f, 500.f); //100, 700
	CameraBoom->TargetArmLength = val;
}

void ATAGCharacter::Attack()
{
	//Virtual implementation
}

void ATAGCharacter::ServerAttack_Implementation()
{
	//Virtual
}

bool ATAGCharacter::ServerAttack_Validate()
{
	//Virtual

	return true;
}

void ATAGCharacter::ServerTakeDamage_Implementation(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
}

bool ATAGCharacter::ServerTakeDamage_Validate(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	//Assume that everything is ok without any further checks and return true
	return true;
}

void ATAGCharacter::OnRep_Health()
{
	//Do a thing
};

void ATAGCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//Tell the engine to call the OnRep_Health each time a variable changes
	DOREPLIFETIME(ATAGCharacter, Health);
}

float ATAGCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	return Health;
}


void ATAGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bZoomIn) {
		Zoom(-100.f * DeltaTime);
	}
	if (bZoomOut) {
		Zoom(100.f * DeltaTime);
	}
}

void ATAGCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ATAGCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	if (bCanMove) {
		Jump();
	}
}

void ATAGCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void ATAGCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ATAGCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ATAGCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f) && bCanMove)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ATAGCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) && bCanMove)
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void ATAGCharacter::ServerResetPlayer_Implementation(AController* InController) {	
	//SetMeshVisible(false);
	bCanMove = false;

	Cast<ATAGGameMode>(GetWorld()->GetAuthGameMode())->OnFadeOut();

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATAGCharacter::DelayedRestart, 0.2f, false, 1.f);
}


bool ATAGCharacter::ServerResetPlayer_Validate(AController* InController) {
	//TODO: Check if call is legit
	return true;
}

void ATAGCharacter::DelayedRestart() {
	OnRespawn();
	GetWorld()->GetAuthGameMode()->RestartPlayer(Controller);
}

