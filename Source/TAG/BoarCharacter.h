

#pragma once

#include "Engine.h"
#include "PigletCharacter.h"
#include "PigletAIController.h"

#include "GameFramework/Character.h"
#include "BoarCharacter.generated.h"

UCLASS()
class TAG_API ABoarCharacter : public ACharacter
{
	GENERATED_BODY()

	ABoarCharacter();

	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USphereComponent* SphereCollider;

public:
	
	//Health in each phase, index 0 = phase 1, 1 = 2, etc etc
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
	TArray<int> HealthInPhases;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawnables)
	TSubclassOf<APigletCharacter> PigletMob;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawnables)
	TSubclassOf<APigletAIController> PigletController;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Spawnables)
	TArray<APigletCharacter*> Piglets;

	UFUNCTION(BlueprintCallable, Category = Spawnables)
	APigletCharacter* SpawnPiglet(FVector Offset, FRotator Rotation);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
	bool bStunned;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
	bool bCharging;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
	int Health = 3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
	int CurrentPhase = 1;


};
