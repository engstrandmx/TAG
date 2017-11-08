

#include "CheckpointField.h"


// Sets default values
ACheckpointField::ACheckpointField()
{
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(FName("Trigger Box"));
	TriggerBox->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ACheckpointField::BeginOverlap);

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACheckpointField::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (GameMode) {
		GameMode->SetCurrentCheckpoints(SelectedCheckpoints);
	}
}

void ACheckpointField::EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

// Called when the game starts or when spawned
void ACheckpointField::BeginPlay()
{
	Super::BeginPlay();
	
	GameMode = Cast<ATAGGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

// Called every frame
void ACheckpointField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

