// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "P5YY/ResourceManagement/AResourceBase.h"
#include "IHandlesResources.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIHandlesResources : public UInterface
{
	GENERATED_BODY()
};

class P5YY_API IIHandlesResources
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Harvesting")
	float GetCargoCapacity();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Harvesting")
	float GetResourcePerHit();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Harvesting")
	AAResourceBase* GetTargetResource();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Harvesting")
	void SetTargetResource(AAResourceBase* NewResource);
};
