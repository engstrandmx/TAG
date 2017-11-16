

#include "EnvQueryContext_FindTrollQuerier.h"
#include "CowAIController.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"
#include "EnvironmentQuery/EnvQueryTypes.h"


void UEnvQueryContext_FindTrollQuerier::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const {

	Super::ProvideContext(QueryInstance, ContextData);

	ACowAIController* Controller = Cast<ACowAIController>((Cast<AActor>((QueryInstance.Owner).Get())->GetInstigatorController()));
	
	if (Controller && Controller->GetSeeingPawn())
	{
		//Set the context SeeingPawn to the provided context data
		UEnvQueryItemType_Actor::SetContextHelper(ContextData, Controller->GetSeeingPawn());
	}
};


