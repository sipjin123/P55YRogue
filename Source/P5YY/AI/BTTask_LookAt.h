// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlueprintBase.h"
#include "BTTask_LookAt.generated.h"

/**
 * 
 */
UCLASS()
class P5YY_API UBTTask_LookAt : public UBTTask_BlueprintBase
{
	GENERATED_BODY()
	UBTTask_LookAt();
private:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	// Will not work on private, but will work for Blackboard base
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	float CompletionValue = 1.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	float Magnitude = 1.0f;

	virtual FString GetStaticDescription() const override;

	// Mandatory Behavior Tree Task functions, otherwise will cause crash
	void OnGameplayTaskActivated(UGameplayTask& Task) override;
	void OnGameplayTaskDeactivated(UGameplayTask& Task) override;
	void OnGameplayTaskInitialized(UGameplayTask& Task) override;
	
	UPROPERTY(EditAnywhere, Category = Blackboard)
	FBlackboardKeySelector MyBlackboardKey;
};