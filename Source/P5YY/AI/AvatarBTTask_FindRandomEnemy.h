// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "AvatarBTTask_FindRandomEnemy.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class P5YY_API UAvatarBTTask_FindRandomEnemy : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UAvatarBTTask_FindRandomEnemy();

	UFUNCTION(BlueprintCallable, Category = "Group1")
		void TriggerTestFunc();

	// No c++ version
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "DmgSystem")
		void TakeDmg_Implementation(int32 Damage);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "DmgSystem")
		void TakeDmg_ImplementationVer2(int32 Damage);

private:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
protected:
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
	virtual FString GetStaticDescription() const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Search", meta = (AllowPrivateAccess = true))
		float SearchRadius = 500.0f;

	// Mandatory Behavior Tree Task functions, otherwise will cause crash
	void OnGameplayTaskActivated(UGameplayTask& Task) override;
	void OnGameplayTaskDeactivated(UGameplayTask& Task) override;
	void OnGameplayTaskInitialized(UGameplayTask& Task) override;
};
