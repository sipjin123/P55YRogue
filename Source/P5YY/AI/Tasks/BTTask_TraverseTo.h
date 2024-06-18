// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlueprintBase.h"
#include "BTTask_TraverseTo.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class P5YY_API UBTTask_TraverseTo : public UBTTask_BlueprintBase
{
	GENERATED_BODY()
public:

	UBTTask_TraverseTo();

private:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	// Will not work on private, but will work for Blackboard base
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
private:
	virtual FString GetStaticDescription() const override;
	virtual uint16 GetInstanceMemorySize() const override;

	// Mandatory Behavior Tree Task functions, otherwise will cause crash
	void OnGameplayTaskActivated(UGameplayTask& Task) override;
	void OnGameplayTaskDeactivated(UGameplayTask& Task) override;
	void OnGameplayTaskInitialized(UGameplayTask& Task) override;
	
	UPROPERTY(EditAnywhere, Category = Blackboard)
		FBlackboardKeySelector MyBlackboardKey;
};

struct FBTMonsterFireWeaponMemory
{
	float TimeToPauseFireFor = 0.f;
	float TimeToFireFor = 0.f;

	float TimeStartedFire = 0.f;
	float TimePausedFire = 0.f;

	bool bFiring = false;
	bool bPausedFiring = false;
	bool bHasStartedFire = false;

	float HalfAngle = 30.f;
};