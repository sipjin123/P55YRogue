// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantBase.h"

// Sets default values
APlantBase::APlantBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	PivotComponent = CreateDefaultSubobject<USceneComponent>(TEXT("PivotComponent"));
	StaticMeshSource = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StatMeshComp"));
	RootComponent = SceneComponent;
	PivotComponent->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);
	StaticMeshSource->AttachToComponent(PivotComponent, FAttachmentTransformRules::KeepRelativeTransform);
	StaticMeshSource->SetVisibility(true);
}

// Called when the game starts or when spawned
void APlantBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlantBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

