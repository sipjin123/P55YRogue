// Fill out your copyright notice in the Description page of Project Settings.


#include "AvatarBTTask_FindRandomEnemy.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UAvatarBTTask_FindRandomEnemy::UAvatarBTTask_FindRandomEnemy() {
	NodeName = TEXT("Find Random Location");

	// accept only vectors
	BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UAvatarBTTask_FindRandomEnemy, BlackboardKey));
}

EBTNodeResult::Type UAvatarBTTask_FindRandomEnemy::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
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
		AIController->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName,
			Location.Location);
	}

	// Signal the BehaviorTreeComponent that the task finished with success
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);

	UE_LOG(LogTemp, Warning, TEXT("Hello:, %f"), SearchRadius);
	return EBTNodeResult::Succeeded;
}

FString UAvatarBTTask_FindRandomEnemy::GetStaticDescription() const
{
	return FString::Printf(TEXT("Vector: %s"), *BlackboardKey.SelectedKeyName.ToString());
	//return FString::Printf(TEXT("Vector"));
}

void UAvatarBTTask_FindRandomEnemy::OnGameplayTaskInitialized(UGameplayTask& Task) {

}

void UAvatarBTTask_FindRandomEnemy::OnGameplayTaskActivated(UGameplayTask& Task) {

}

void UAvatarBTTask_FindRandomEnemy::OnGameplayTaskDeactivated(UGameplayTask& Task) {

}