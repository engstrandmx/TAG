

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"
#include "CustomSpringArmComponent.generated.h"

/**
 * 
 */
UCLASS()
class TAG_API UCustomSpringArmComponent : public USpringArmComponent
{
	GENERATED_BODY()
	
	FVector BlendLocations(const FVector& DesiredArmLocation, const FVector& TraceHitLocation, bool bHitSomething, float DeltaTime) override;

	FVector LastHitLocation;
	FVector LastLocation;
	float Alpha = 0;
	float HitAlpha = 0;
	bool bInit = false;
};
