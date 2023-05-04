// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_TraverseTo.h"
#include "AIController.h"
#include "NavigationSystem.h"

UBTTask_TraverseTo::UBTTask_TraverseTo() {
	bNotifyTick = true;
	bNotifyTaskFinished = true;
	//bCreateNodeInstance = false;
	NodeName = "My Special Task";
	UE_LOG(LogTemp, Warning, TEXT("Constructed"));
}

void UBTTask_TraverseTo::OnGameplayTaskInitialized(UGameplayTask& Task) {

}

void UBTTask_TraverseTo::OnGameplayTaskActivated(UGameplayTask& Task) {

}

void UBTTask_TraverseTo::OnGameplayTaskDeactivated(UGameplayTask& Task) {

}

EBTNodeResult::Type UBTTask_TraverseTo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	const APawn* AIPawn = AIController->GetPawn();

	UE_LOG(LogTemp, Warning, TEXT("Start Task"));
	Super::ExecuteTask(OwnerComp, NodeMemory);
	//FinishLatentTask(OwnerComp, EBTNodeResult::InProgress);
	return EBTNodeResult::InProgress;
	//return EBTNodeResult::Succeeded;
}

void UBTTask_TraverseTo::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	// This ensures the receive tick AI and receive tick in Blueprint is called!
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
	
	// Do logic here then finish task
	//FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
}

FString UBTTask_TraverseTo::GetStaticDescription() const
{
	return FString::Printf(TEXT("Vector"));
}

uint16 UBTTask_TraverseTo::GetInstanceMemorySize() const
{
    return sizeof(FBTMonsterFireWeaponMemory);
}
