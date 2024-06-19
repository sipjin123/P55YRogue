// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "P5YY/Interfaces/IInteractable.h"
#include "PickupItem.generated.h"

UCLASS()
class P5YY_API APickupItem : public AActor, public IIInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnInteract_Implementation() override;
	virtual void ProcessInteractPure() override;
	virtual void OnInteractByActor_Implementation(const AActor* ActorRef) override;
	virtual void ProcessInteractByActorPure(const AActor* ActorRef) override;
};
