// Fill out your copyright notice in the Description page of Project Settings.


#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTTask_DetectTarget.h"

UBTTask_DetectTarget::UBTTask_DetectTarget()
{
	bNotifyTick = true;
	bNotifyTaskFinished = true;
	NodeName = "Detect Target";
}

EBTNodeResult::Type UBTTask_DetectTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("Blackboard Execute Task"));
	FNavLocation Location{};

	// Get AI Pawn
	AAIController* AIController = OwnerComp.GetAIOwner();
	const APawn* AIPawn = AIController->GetPawn();

	// Get Pawn origin
	const FVector Origin = AIPawn->GetActorLocation();

	// Obtain Navigation System and find random location
	const UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());
	if (IsValid(NavSystem) && NavSystem->GetRandomPointInNavigableRadius(Origin, SearchRadius, Location))
	{
		AIController->GetBlackboardComponent()->SetValueAsVector(MyBlackboardKey.SelectedKeyName,
			Location.Location);
	}

	// Signal the BehaviorTreeComponent that the task finished with success
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);

	UE_LOG(LogTemp, Error, TEXT("Search Detect Target Node: [%f]"), SearchRadius);
	
	Super::ExecuteTask(OwnerComp, NodeMemory);
	return EBTNodeResult::Succeeded;
	//return Super::ExecuteTask(OwnerComp, NodeMemory);
}

void UBTTask_DetectTarget::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
}

void UBTTask_DetectTarget::OnGameplayTaskActivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskActivated(Task);
}

void UBTTask_DetectTarget::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskDeactivated(Task);
}

void UBTTask_DetectTarget::OnGameplayTaskInitialized(UGameplayTask& Task)
{
	Super::OnGameplayTaskInitialized(Task);
}
