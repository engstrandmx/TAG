// Fill out your copyright notice in the Description page of Project Settings.

#include "DropOffZone.h"


// Sets default values
ADropOffZone::ADropOffZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DropOffArea = CreateDefaultSubobject<UBoxComponent>(FName("Drop Off Area"));
	SetRootComponent(DropOffArea);

}

// Called when the game starts or when spawned
void ADropOffZone::BeginPlay()
{
	Super::BeginPlay();
	
}


