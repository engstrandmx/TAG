

#pragma once

#include "Engine.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "CowAIController.generated.h"

/**
 * 
 */
UCLASS()
class TAG_API ACowAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	/** BlackboardComponent - used to initialize blackboard values and set/get values from a blackboard asset */
	UBlackboardComponent* BlackboardComp;
 
	/** BehaviorTreeComponent - used to start a behavior tree */
	UBehaviorTreeComponent* BehaviorTreeComp;


	/** Blackboard Key Value Name */
	const FName BlackboardEnemyKey = FName("Enemy");
 
	/** The function that fires when the perception of our AI gets updated */
	UFUNCTION()
	void OnPerceptionUpdated(TArray<AActor*> UpdatedActors);
 
	/** A Sight Sense config for our AI */
	UAISenseConfig_Sight* Sight;

protected:

	UPROPERTY(EditAnywhere)
	UBehaviorTree* BehaviorTree;

	UPROPERTY(EditAnywhere)
	UAIPerceptionComponent* AIPerceptionComponent;

public:
	
	ACowAIController();

	virtual void Possess(APawn* InPawn) override;
	UFUNCTION(BlueprintCallable)
	AActor* GetSeeingPawn();
	
	
};
