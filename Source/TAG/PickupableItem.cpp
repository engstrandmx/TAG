

#include "PickupableItem.h"
#include "TAGCharacter.h"


// Sets default values
APickupableItem::APickupableItem()
{
	BoxCollisionComp = CreateDefaultSubobject<UBoxComponent>(FName("Pickup Area"));
	SetRootComponent(BoxCollisionComp);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("Static Mesh"));
	StaticMeshComponent->AttachToComponent(BoxCollisionComp, FAttachmentTransformRules::KeepRelativeTransform);
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	IdleParticleComponent = CreateDefaultSubobject<UParticleSystemComponent>(FName("Idle Particles"));
	IdleParticleComponent->AttachToComponent(BoxCollisionComp, FAttachmentTransformRules::KeepRelativeTransform);

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	bEnableIdleRotation = true;

	BoxCollisionComp->OnComponentBeginOverlap.AddDynamic(this, &APickupableItem::BeginOverlap);


}

// Called when the game starts or when spawned
void APickupableItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void APickupableItem::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{

	UE_LOG(LogTemp, Warning, TEXT("Meme"))
	if (OtherActor->GetClass()->IsChildOf<ATAGCharacter>()) {
		OnPickup();
	}

	
}

// Called every frame
void APickupableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bEnableIdleRotation) {
		StaticMeshComponent->AddRelativeRotation(IdleRotation);
	}

}

