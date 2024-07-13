// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InventoryTrackerDA.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class P5YY_API UInventoryTrackerDA : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
	int TestInt = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int TestFloat = 0;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ACharacter> ActorClassToSpawn = nullptr;
};
