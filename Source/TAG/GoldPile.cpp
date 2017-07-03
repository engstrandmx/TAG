// Fill out your copyright notice in the Description page of Project Settings.

#include "GoldPile.h"

// Sets default values
AGoldPile::AGoldPile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Setup default subobjects
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("Gold Pile"));
	CollectArea = CreateDefaultSubobject<UBoxComponent>(FName("Collect Area"));
	
	//Setup root component and hierarchy
	SetRootComponent(MeshComponent);
	CollectArea->AttachToComponent(MeshComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AGoldPile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGoldPile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

