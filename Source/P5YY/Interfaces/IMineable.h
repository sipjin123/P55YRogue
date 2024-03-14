// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IMineable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIMineable : public UInterface
{
	GENERATED_BODY()
};

class P5YY_API IIMineable
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Harvesting")
	bool IsMineable();
};
