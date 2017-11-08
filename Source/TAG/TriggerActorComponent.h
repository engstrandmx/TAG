

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TriggerActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TAG_API UTriggerActorComponent : public UActorComponent
{

	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTriggerSignature);


public:	
	// Sets default values for this component's properties
	UTriggerActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnTriggerSignature OnTrigger;
};
