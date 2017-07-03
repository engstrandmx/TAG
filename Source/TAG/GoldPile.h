// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "GoldPile.generated.h"

UCLASS()
class TAG_API AGoldPile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGoldPile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = Components)
	UBoxComponent* CollectArea;
	UPROPERTY(EditAnywhere, Category = Components)
	UStaticMeshComponent* MeshComponent;


};
