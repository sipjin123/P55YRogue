// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_LookAt.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_LookAt::UBTTask_LookAt()
{
	bNotifyTick = true;
	bNotifyTaskFinished = true;
	NodeName = "Look at New Position";
}

void UBTTask_LookAt::OnGameplayTaskInitialized(UGameplayTask& Task) {

}

void UBTTask_LookAt::OnGameplayTaskActivated(UGameplayTask& Task) {

}

void UBTTask_LookAt::OnGameplayTaskDeactivated(UGameplayTask& Task) {

}

EBTNodeResult::Type UBTTask_LookAt::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	float DrawRadius = 12.0f;
	float Duration = 5.0f;

	AAIController* AIController = OwnerComp.GetAIOwner();
	FVector newLocation = AIController->GetBlackboardComponent()->GetValueAsVector(MyBlackboardKey.SelectedKeyName);
	DrawDebugSphere(GetWorld(), FVector(newLocation.X, newLocation.Y, newLocation.Z), DrawRadius, 16, FColor::Blue, false, Duration);
	
	Super::ExecuteTask(OwnerComp, NodeMemory);
	return EBTNodeResult::InProgress;
}

void UBTTask_LookAt::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	// This ensures the receive tick AI and receive tick in Blueprint is called!
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
	
	// Do logic here then finish task
	//FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
}

FString UBTTask_LookAt::GetStaticDescription() const
{
	return FString::Printf(TEXT("Vector"));
}
