// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/Character.h"
#include "CustomSpringArmComponent.h"
#include "TAGCharacter.generated.h"

UCLASS(config=Game)
class ATAGCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCustomSpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	ATAGCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UFUNCTION(BlueprintCallable, Category = Camera)
	virtual	void ResetCamera();

protected:

	float CameraTransitionSpeed = 1.25f; // 1.25
	float CameraLookAtSpeed = 0.75f; // 0.75

	void Tick(float DeltaTime);

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable, Category = "Camera Functions")
	void LookAtActor(AActor* Actor, float Speed, float Time, bool FuckYou);
	UFUNCTION()
	void StopLookAt();
	void ZoomIn();
	void ZoomOut();
	void Zoom(float Value);

	void ZoomInHeld();
	void ZoomInReleased();
	void ZoomOutHeld();
	void ZoomOutReleased();

	AActor* ActorToLookAt;
	float ActorLookAtTime = 1.f;

	bool bZoomIn;
	bool bZoomOut;
	float InitialHeightZ;
	float ZoomInZ;

	float CameraResetAlpha;
	bool bResetCamera;

	// End of APawn interface
	virtual void Attack();

	UFUNCTION(Server, Reliable, WithValidation)
	virtual void ServerAttack();
	virtual void ServerAttack_Implementation();
	virtual bool ServerAttack_Validate();

public:
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


	/** Returns CameraBoom subobject **/
	FORCEINLINE class UCustomSpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnRespawn();

protected:
	UPROPERTY(Transient, Replicated)
	bool bCanMove;

	UPROPERTY(VisibleAnywhere, Transient, ReplicatedUsing = OnRep_Health, Category = Stats)
	float Health = 100.f;

	UFUNCTION(Server, Reliable, WithValidation)
	virtual void ServerTakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);

	/** Contains the actual implementation of the ServerTakeDamage function */
	virtual void ServerTakeDamage_Implementation(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);

	/** Validates the client. If the result is false the client will be disconnected */
	virtual bool ServerTakeDamage_Validate(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);

	UFUNCTION()
	void OnRep_Health();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerResetPlayer(AController* InController);
	void ServerResetPlayer_Implementation(AController* InController);
	bool ServerResetPlayer_Validate(AController* InController);

	UFUNCTION()
	void DelayedRestart();
	
	UFUNCTION(Reliable, NetMulticast)
	void SetMeshVisible(bool isTrue);
	FORCEINLINE void SetMeshVisible_Implementation(bool isTrue) { GetMesh()->SetVisibility(isTrue); }


};

