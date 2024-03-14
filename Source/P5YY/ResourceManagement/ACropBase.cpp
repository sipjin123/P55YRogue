// Fill out your copyright notice in the Description page of Project Settings.


#include "ACropBase.h"


// Sets default values
AACropBase::AACropBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SceneComponent;
	
	StaticMeshSource = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StatMeshComp"));
	StaticMeshSource->SetVisibility(true);
	StaticMeshSource->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AACropBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AACropBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

