

#include "BoarCharacter.h"


// Sets default values
ABoarCharacter::ABoarCharacter()
{
	SphereCollider = CreateDefaultSubobject<USphereComponent>(FName("Sphere Collider"));
	SphereCollider->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

