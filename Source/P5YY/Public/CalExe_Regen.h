// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "CalExe_Regen.generated.h"

/**
 * 
 */
UCLASS()
class P5YY_API UCalExe_Regen : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

	UCalExe_Regen();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
		FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;

	
};
