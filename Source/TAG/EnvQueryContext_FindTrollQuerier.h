

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "EnvQueryContext_FindTrollQuerier.generated.h"

/**
 * 
 */
UCLASS()
class TAG_API UEnvQueryContext_FindTrollQuerier : public UEnvQueryContext
{
	GENERATED_BODY()
	
	virtual void ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const;
	
	
};
