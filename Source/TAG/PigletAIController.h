

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PigletAIController.generated.h"

/**
 * 
 */
UCLASS()
class TAG_API APigletAIController : public AAIController
{
	GENERATED_BODY()

	APigletAIController();

private:
	/** BlackboardComponent - used to initialize blackboard values and set/get values from a blackboard asset */
	UBlackboardComponent* BlackboardComp;

	/** BehaviorTreeComponent - used to start a behavior tree */
	UBehaviorTreeComponent* BehaviorTreeComp;

protected:

	UPROPERTY(EditAnywhere)
	UBehaviorTree* BehaviorTree;
	
public:

	virtual void Possess(APawn* InPawn) override;

	FORCEINLINE UBlackboardComponent* GetBlackboardComponent() { return BlackboardComp; }

	
	
};
