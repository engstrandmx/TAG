// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "DropOffZone.generated.h"

UCLASS()
class TAG_API ADropOffZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADropOffZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame

	UPROPERTY(EditAnywhere, Category = Components)
	UBoxComponent* DropOffArea;
	
	
};
