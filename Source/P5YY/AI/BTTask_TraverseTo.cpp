// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_TraverseTo.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_TraverseTo::UBTTask_TraverseTo() {
	bNotifyTick = true;
	bNotifyTaskFinished = true;
	//bCreateNodeInstance = false;
	NodeName = "My Special Task";
	UE_LOG(LogTemp, Warning, TEXT("Constructed"));
}

EBTNodeResult::Type UBTTask_TraverseTo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	const APawn* AIPawn = AIController->GetPawn();
	
	float DrawRadius = 12.0f;
	float Duration = 5.0f;

	FVector newLocation = AIController->GetBlackboardComponent()->GetValueAsVector(MyBlackboardKey.SelectedKeyName);
	DrawDebugSphere(GetWorld(), FVector(newLocation.X, newLocation.Y, newLocation.Z), DrawRadius, 16, FColor::Orange, false, Duration);
	
	UE_LOG(LogTemp, Warning, TEXT("AI_Task_Traverse to: {%f}-{%f}-{%f}"), newLocation.X, newLocation.Y, newLocation.Z);
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

void UBTTask_TraverseTo::OnGameplayTaskInitialized(UGameplayTask& Task) {

}

void UBTTask_TraverseTo::OnGameplayTaskActivated(UGameplayTask& Task) {

}

void UBTTask_TraverseTo::OnGameplayTaskDeactivated(UGameplayTask& Task) {

}

FString UBTTask_TraverseTo::GetStaticDescription() const
{
	return FString::Printf(TEXT("Vector"));
}

uint16 UBTTask_TraverseTo::GetInstanceMemorySize() const
{
    return sizeof(FBTMonsterFireWeaponMemory);
}
