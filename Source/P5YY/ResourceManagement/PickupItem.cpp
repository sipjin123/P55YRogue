// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupItem.h"
#include "P5YY/Interfaces/IInteractable.h"

// Sets default values
APickupItem::APickupItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickupItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickupItem::OnInteract_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Item must be interacted BP"));
	ProcessInteractPure();
	IIInteractable::OnInteract_Implementation();
}

void APickupItem::ProcessInteractPure()
{
	IIInteractable::ProcessInteractPure();
	UE_LOG(LogTemp, Warning, TEXT("Item must be interacted C++"));

	K2_DestroyActor();
}

