

#pragma once

#include "CoreMinimal.h"
#include "DestructibleActor.h"
#include "CustomDestructibleActor.generated.h"

/**
 * 
 */
UCLASS()
class TAG_API ACustomDestructibleActor : public ADestructibleActor
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintReadOnly, Category = Destructible)
	bool bDestroyed;

	UFUNCTION(BlueprintCallable, Category = Destructible)
	void MarkDestroyed(bool isDestroyed);
	
};
