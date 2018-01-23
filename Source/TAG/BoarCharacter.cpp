

#include "BoarCharacter.h"

// Sets default values
ABoarCharacter::ABoarCharacter()
{
	SphereCollider = CreateDefaultSubobject<USphereComponent>(FName("Sphere Collider"));
	SphereCollider->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

APigletCharacter* ABoarCharacter::SpawnPiglet(FVector Offset, FRotator Rotation)
{
	FTransform SpawnTransform;
	SpawnTransform.SetRotation(Rotation.Quaternion());
	SpawnTransform.SetLocation(GetActorLocation() + Offset);

	FActorSpawnParameters SpawnParams;

	SpawnParams.bNoFail = true;

	if (PigletMob != nullptr) {
		APigletCharacter* a = GetWorld()->SpawnActor<APigletCharacter>(PigletMob, SpawnTransform.GetLocation(), Rotation, SpawnParams);
		APigletAIController* Controller = GetWorld()->SpawnActor<APigletAIController>(PigletController, SpawnParams);

		if (Controller != nullptr) {
			Controller->Possess(a);
		}

		if (a != nullptr) {
			Piglets.Add(a);
		}

		return a;
	}
	
	return nullptr;
}

