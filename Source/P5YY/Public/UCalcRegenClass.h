// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "UCalcRegenClass.generated.h"

/**
 * 
 */
UCLASS()
class P5YY_API UUCalcRegenClass : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

	UUCalcRegenClass();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

	FGameplayEffectAttributeCaptureDefinition HealthDef;
	FGameplayEffectAttributeCaptureDefinition MaxHealthDef;
	
};
