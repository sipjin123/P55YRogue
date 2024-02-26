// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlueprintBase.h"
#include "BTTask_FindPatrolNode.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class P5YY_API UBTTask_FindPatrolNode : public UBTTask_BlueprintBase
{
	GENERATED_BODY()
	UBTTask_FindPatrolNode();
private:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	// Will not work on private, but will work for Blackboard base
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Search", meta = (AllowPrivateAccess = true))
	float MaxSearchRadius = 500.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Search", meta = (AllowPrivateAccess = true))
	float MinimumSearchRadius = 500.0f;
	
	// Mandatory Behavior Tree Task functions, otherwise will cause crash
	void OnGameplayTaskActivated(UGameplayTask& Task) override;
	void OnGameplayTaskDeactivated(UGameplayTask& Task) override;
	void OnGameplayTaskInitialized(UGameplayTask& Task) override;
	
	UPROPERTY(EditAnywhere, Category = Blackboard)
	FBlackboardKeySelector MyBlackboardKey;
};