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

	for (AActor* actor : FloatingActors)
	{
		if (actor) {
			FVector location = actor->GetActorLocation();

			float realtimeSeconds = UGameplayStatics::GetRealTimeSeconds(GetWorld());
			
			FVector offset = FVector(FMath::Cos(realtimeSeconds), FMath::Cos(realtimeSeconds), FMath::Sin(realtimeSeconds));
			FVector lastOffset = FVector(FMath::Cos(realtimeSeconds-DeltaTime), FMath::Cos(realtimeSeconds-DeltaTime), FMath::Sin(realtimeSeconds-DeltaTime));
			
			//UE_LOG(LogTemp, Warning, TEXT("Offset = %f"), FMath::Sin(realtimeSeconds));

			actor->SetActorLocation(location + (CurrentVector + (offset - lastOffset) * FloatSimulationMagnitude) * DeltaTime);


		}
	}
}

void AWaterField::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->ActorHasTag("Floating")) {
		FloatingActors.Add(OtherActor);

		Cast<UStaticMeshComponent>(OtherComp)->SetSimulatePhysics(false);
	}
}

