

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "TriggerSceneComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TAG_API UTriggerSceneComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTriggerSceneComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void TriggerEvent();
	
};
