

#pragma once

#include "Engine.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
	bool bStunned;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
	bool bCharging;

};
