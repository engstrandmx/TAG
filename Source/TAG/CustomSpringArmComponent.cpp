

#include "CustomSpringArmComponent.h"



FVector UCustomSpringArmComponent::BlendLocations(const FVector& DesiredArmLocation, const FVector& TraceHitLocation, bool bHitSomething, float DeltaTime)
{
	FVector ReturnLocation = FVector::ZeroVector;

	if (bHitSomething) {
		Alpha += DeltaTime;
		HitAlpha += DeltaTime * 2;
		LastHitLocation = FMath::InterpExpoInOut(LastHitLocation, TraceHitLocation, HitAlpha);
	}
	else {
		HitAlpha -= DeltaTime * 2;
		Alpha -= DeltaTime * 2;
	}

	Alpha = FMath::Clamp(Alpha, 0.f, 1.f);
	HitAlpha = FMath::Clamp(HitAlpha, 0.f, 1.f);

	ReturnLocation = FMath::Lerp(DesiredArmLocation, LastHitLocation, Alpha);

	return ReturnLocation;
}


