// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IPoolable.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI)
class UIPoolable : public UInterface
{
	GENERATED_BODY()
};

class P5YY_API IIPoolable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Pooling")
	bool IsPoolable();
};