

#include "CustomSpringArmComponent.h"



FVector UCustomSpringArmComponent::BlendLocations(const FVector& DesiredArmLocation, const FVector& TraceHitLocation, bool bHitSomething, float DeltaTime)
{
	if (!bInit) {
		LastLocation = DesiredArmLocation;

		bInit = true;
	}

	FVector ReturnLocation = FVector::ZeroVector;

	if (bHitSomething) {
		Alpha += DeltaTime * 2;
		HitAlpha += DeltaTime * 2;
		//LastHitLocation = FMath::InterpExpoInOut(LastHitLocation, TraceHitLocation, HitAlpha);
		LastHitLocation = TraceHitLocation;
	}
	else {
		LastHitLocation = LastLocation;
		HitAlpha -= DeltaTime * 2;
		Alpha -= DeltaTime * 3;
	}

	Alpha = FMath::Clamp(Alpha, 0.f, 1.f);
	HitAlpha = FMath::Clamp(HitAlpha, 0.f, 1.f);

	ReturnLocation = FMath::Lerp(DesiredArmLocation, LastHitLocation, Alpha);
		
	ReturnLocation = FMath::VInterpConstantTo(LastLocation, ReturnLocation, 1, 500.f * DeltaTime * FMath::Clamp(Alpha,0.5f, 1.f) * 20);

	LastLocation = ReturnLocation;

	return ReturnLocation;
}


