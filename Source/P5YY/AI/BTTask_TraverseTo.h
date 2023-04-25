// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlueprintBase.h"
#include "BTTask_TraverseTo.generated.h"

/**
 * 
 */
UCLASS()
class P5YY_API UBTTask_TraverseTo : public UBTTask_BlueprintBase
{
	GENERATED_BODY()

private:
	// Mandatory Behavior Tree Task functions, otherwise will cause crash
	void OnGameplayTaskActivated(UGameplayTask& Task) override;
	void OnGameplayTaskDeactivated(UGameplayTask& Task) override;
	void OnGameplayTaskInitialized(UGameplayTask& Task) override;
};
