// Fill out your copyright notice in the Description page of Project Settings.


#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTTask_FindPatrolNode.h"

UBTTask_FindPatrolNode::UBTTask_FindPatrolNode()
{
	bNotifyTick = true;
	bNotifyTaskFinished = true;
	NodeName = "Detect Patrol Node";
	MyBlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_FindPatrolNode, MyBlackboardKey));
}

EBTNodeResult::Type UBTTask_FindPatrolNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("Blackboard Execute Task Find Patrol"));
	FNavLocation Location{};

	// Get AI Pawn
	AAIController* AIController = OwnerComp.GetAIOwner();
	const APawn* AIPawn = AIController->GetPawn();

	// Get Pawn origin
	const FVector Origin = AIPawn->GetActorLocation();

	// Obtain Navigation System and find random location
	const UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());
	if (IsValid(NavSystem) && NavSystem->GetRandomPointInNavigableRadius(Origin, MaxSearchRadius, Location))
	{
		AIController->GetBlackboardComponent()->SetValueAsVector(MyBlackboardKey.SelectedKeyName,
			Location.Location);
		UE_LOG(LogTemp, Warning, TEXT("Search Radius Patrol Node: [%f] -> [{%f}]-[{%f}]"), Location.Location.X, Location.Location.Y, Location.Location.Z);
	DrawDebugSphere(GetWorld(), FVector(Location.Location.X, Location.Location.Y, Location.Location.Z), 10, 16, FColor::Blue, false, 5);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Search Radius Patrol Node: [%f] FAIL"), MaxSearchRadius);
	}

	// Signal the BehaviorTreeComponent that the task finished with success
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	//SET_WARN_COLOR( COLOR_CYAN );
	
	Super::ExecuteTask(OwnerComp, NodeMemory);
	return EBTNodeResult::Succeeded;
	//return Super::ExecuteTask(OwnerComp, NodeMemory);
}

void UBTTask_FindPatrolNode::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
}

void UBTTask_FindPatrolNode::OnGameplayTaskActivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskActivated(Task);
}

void UBTTask_FindPatrolNode::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskDeactivated(Task);
}

void UBTTask_FindPatrolNode::OnGameplayTaskInitialized(UGameplayTask& Task)
{
	Super::OnGameplayTaskInitialized(Task);
}
