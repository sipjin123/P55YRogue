// Fill out your copyright notice in the Description page of Project Settings.


#include "AMineMaster.h"


// Sets default values
AAMineMaster::AAMineMaster()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAMineMaster::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAMineMaster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

