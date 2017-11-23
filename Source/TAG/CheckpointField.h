

#pragma once

#include "Engine.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/Actor.h"
#include "TAGGameMode.h"
#include "CheckpointField.generated.h"


UCLASS()
class TAG_API ACheckpointField : public AActor
{
	GENERATED_BODY()
	
public:	
	ACheckpointField();

	ATAGGameMode* GameMode;
	//Checkpoints the player will spawn at if current field is active
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Checkpoint")
	TArray<APlayerStart*> SelectedCheckpoints;
	UPROPERTY(EditAnywhere, Category = "Checkpoint")
	UBoxComponent* TriggerBox;
	UPROPERTY(EditAnywhere, Category = "Checkpoint")
	bool bInitialSpawn;

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
	UFUNCTION()
	void EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
