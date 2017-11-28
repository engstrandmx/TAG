// Fill out your copyright notice in the Description page of Project Settings.

#include "WaterField.h"
#include "CowCharacter.h"

// Sets default values
AWaterField::AWaterField()
{
	PrimaryActorTick.bCanEverTick = true;

	WaterFieldBox = CreateDefaultSubobject<UBoxComponent>("Water Bounding Box", false);
	WaterFieldBox->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	SplineComponent = CreateDefaultSubobject<USplineComponent>("Water Spline", false);

	WaterFieldBox->OnComponentBeginOverlap.AddDynamic(this, &AWaterField::BeginOverlap);
}

void AWaterField::BeginPlay()
{
	Super::BeginPlay();
}

void AWaterField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	uint8 Len = FloatingActors.Num();

	if (Len != 0) {
		alpha += DeltaTime * 0.01f;
	}

	for (uint8 i = 0; i < Len; i++)
	{
		AActor* actor = FloatingActors[i];

		//FHitResult* HitResult = nullptr;

		FVector origin = actor->GetActorLocation();
		FVector tan = SplineComponent->FindTangentClosestToWorldLocation(actor->GetActorLocation(), ESplineCoordinateSpace::World);
		FVector toStream = FVector::ZeroVector;
		
		if (FVector::Distance(SplineComponent->FindLocationClosestToWorldLocation(origin, ESplineCoordinateSpace::World), origin) > WaterWidth) {
			toStream = SplineComponent->FindLocationClosestToWorldLocation(origin, ESplineCoordinateSpace::World) - origin;
			toStream.Normalize();
			tan += toStream;
		}

		tan.Normalize();

		FVector dir = (tan  * WaveMagnitude * DeltaTime);

		FHitResult hit(ForceInit);

		if (Trace(GetWorld(), actor, origin, origin + dir * 25, hit, ECC_WorldStatic)) {

			FVector right = hit.ImpactNormal.RotateAngleAxis(90, FVector::UpVector);
			FVector left = hit.ImpactNormal.RotateAngleAxis(-90, FVector::UpVector);
			FVector closest = SplineComponent->FindLocationClosestToWorldLocation(origin, ESplineCoordinateSpace::World);
			
			FVector normal = left;

			if (FVector::Distance(origin + right, closest) < FVector::Distance(origin + left, closest)) {
				normal = right;
			}

			actor->SetActorLocation(FMath::Lerp(origin, origin + normal * WaveMagnitude * DeltaTime, 0.5f));
		
// 			DrawDebugLine(
// 				GetWorld(),
// 				actor->GetActorLocation(),
// 				(actor->GetActorLocation() + (FVector)hit.ImpactNormal * 100 * 100),
// 				FColor(255, 0, 0),
// 				true, -1, 0,
// 				12.333
// 			);
		}
		else {
			actor->SetActorLocation(FMath::Lerp(origin, origin + dir, 0.5f));

		}

		actor->SetActorRotation(actor->GetActorRotation() + FRotator(0, 5 * DeltaTime, 0));
		//Cast<ACowCharacter>(actor)->LaunchCharacter(tan  * WaveMagnitude * DeltaTime, false, false);



		//actor->SetActorLocation((actor->GetActorLocation() + (tan  * WaveMagnitude * DeltaTime)), true, HitResult);

		//FloatingLocations[i] = actor->GetActorLocation();
// 
// 		if (HitResult != nullptr) {
// 			FVector right = FVector::CrossProduct(HitResult->ImpactNormal, FVector::UpVector);
// 			UE_LOG(LogTemp, Warning, TEXT("BLOCKED"));
// 

// 
// 			actor->SetActorLocation((actor->GetActorLocation() + (right * WaveMagnitude * DeltaTime)), true);
// 		}
	}
// 	uint8 Len = FloatingActors.Num();
// 	for (uint8 i = 0; i < Len; i++)
// 	{
// 		if (FloatingActors[i] != NULL) {
// 
// 			AActor* actor = FloatingActors[i];
// 
// 			FVector location = actor->GetActorLocation();
// 
// 			FVector multi = FloatSimulationMagnitude;
// 			FVector offset = FVector(WaveSimScalar * multi.X, -WaveSimScalar * multi.Y, WaveSimScalar * multi.Z);
// 
// 			actor->SetActorLocation(location + CurrentVector * DeltaTime, true);
// 			actor->SetActorLocation(actor->GetActorLocation() + offset - FloatingLocations[i]);
// 
// 			//UE_LOG(LogTemp, Warning, TEXT("Z offset = %f"), (offset).Z);
// 
// 			FloatingLocations[i] = offset;
// 		}
// 	}

	//UE_LOG(LogTemp, Warning, TEXT("WaveSim = %f"), WaveSimScalar);

// 	float toLerp = WaveMagnitude;
// 
// 	if (!bPositiveWave) {
// 		toLerp = -toLerp;
// 	}
// 
// 	WaveSimAlpha += DeltaTime * WaveSimMult;
// 
// 	WaveSimScalar = FMath::InterpCircularInOut(WaveSimScalar, toLerp, WaveSimAlpha);
// 
// 	if (WaveSimAlpha > 1) {
// 		WaveSimAlpha = 0;
// 		bPositiveWave = !bPositiveWave;
// 	}
}

void AWaterField::RemoveFromWaterActors(AActor* ActorToRemove) {
	FString Name =  ActorToRemove->GetName();

	uint8 Len = FloatingActors.Num();
	for (uint8 i = 0; i < Len; i++) {
		if (FloatingActors[i]->GetName() == ActorToRemove->GetName())
		{
			FloatingActors.RemoveAt(i);
		}
	}

}

void AWaterField::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	//On actor enter check for floating tag, add to array and disable physics
	if (OtherActor->ActorHasTag("Floating")) {

		UE_LOG(LogTemp, Warning, TEXT("Floating actor entered"));

		uint8 Len = FloatingActors.Num();
		for (uint8 i = 0; i < Len; i++) {
			if (FloatingActors[i]->GetName() == OtherActor->GetName()) {
				UE_LOG(LogTemp, Warning, TEXT("Actor already in water"));

				return;
			}
		}

		UE_LOG(LogTemp, Warning, TEXT("Actor has been added to water"));

		FloatingActors.Add(OtherActor);
		FloatingLocations.Add(FVector(0, 0, 0));

		//Physics disabling and the like handled in blueprint
		//Event called here
		OnActorEnter(OtherActor);
	}
}

