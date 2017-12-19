

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "InteractSceneComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TAG_API UInteractSceneComponent : public USceneComponent
{
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractSignature, AActor*, TriggeringActor);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAttackSignature, AActor*, TriggeringActor, float, Damages);

	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractSceneComponent();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UFUNCTION(Category = "Interact")
	void Interact(AActor* TriggeringActor);

	UFUNCTION(Category = "Interact")
	void Attack(AActor* TriggeringActor, float Damage);
	
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FInteractSignature OnInteract;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FAttackSignature OnAttack;

};
