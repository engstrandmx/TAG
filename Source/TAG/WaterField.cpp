// Fill out your copyright notice in the Description page of Project Settings.

#include "WaterField.h"

// Sets default values
AWaterField::AWaterField()
{
	PrimaryActorTick.bCanEverTick = true;

	WaterFieldBox = CreateDefaultSubobject<UBoxComponent>("Water Bounding Box", false);
	WaterFieldBox->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	WaterFieldBox->OnComponentBeginOverlap.AddDynamic(this, &AWaterField::BeginOverlap);
}
// Called when the game starts or when spawned
void AWaterField::BeginPlay()
{
	Super::BeginPlay();
	
}
// Called every frame
void AWaterField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	uint8 Len = FloatingActors.Num();
	for (uint8 i = 0; i < Len; i++)
	{
		if (FloatingActors[i] != NULL) {
			UE_LOG(LogTemp, Warning, TEXT("OffsetX = %f"), 1.f);

			AActor* actor = FloatingActors[i];

			FVector location = actor->GetActorLocation();

			if (actor->GetRootComponent()) {
				location = GetRootComponent()->GetComponentLocation();
			}

			//float realtimeSeconds = UGameplayStatics::GetRealTimeSeconds(GetWorld());

			FVector offset = FVector(WaveSimMult, -WaveSimMult, WaveSimMult) * FloatSimulationMagnitude;
			
			actor->SetActorLocation(location + CurrentVector * DeltaTime);
			actor->SetActorLocation(actor->GetActorLocation() + offset - FloatingLocations[i]);

			FloatingLocations[i] = offset;
		}

	}

	if (!bPositiveWave) {
		DeltaTime = -DeltaTime;
	}

	WaveSimMult += DeltaTime;

	if (WaveSimMult > WaveMagnitude || WaveSimMult < -WaveMagnitude) {
		bPositiveWave = !bPositiveWave;
	}
}

void AWaterField::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->ActorHasTag("Floating")) {
		FloatingActors.Add(OtherActor);
		FloatingLocations.Add(FVector(0, 0, 0));

		Cast<UStaticMeshComponent>(OtherComp)->SetSimulatePhysics(false);
	}
}

