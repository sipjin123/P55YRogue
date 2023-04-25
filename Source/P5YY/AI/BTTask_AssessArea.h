// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_AssessArea.generated.h"

/**
 * 
 */
UCLASS()
class P5YY_API UBTTask_AssessArea : public UBTTaskNode
{
	GENERATED_BODY()
public:

private:
	// Mandatory Behavior Tree Task functions, otherwise will cause crash
	void OnGameplayTaskActivated(UGameplayTask& Task) override;
	void OnGameplayTaskDeactivated(UGameplayTask& Task) override;
	void OnGameplayTaskInitialized(UGameplayTask& Task) override;
};
