// Fill out your copyright notice in the Description page of Project Settings.


#include "AvatarBTTask_FindRandomEnemy.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UAvatarBTTask_FindRandomEnemy::UAvatarBTTask_FindRandomEnemy() {
	NodeName = TEXT("Find Random Location");
	//bNotifyTick = true;
	
	// Accept only vectors
	BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UAvatarBTTask_FindRandomEnemy, BlackboardKey));
}

EBTNodeResult::Type UAvatarBTTask_FindRandomEnemy::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//return EBTNodeResult::InProgress;
	
	// Test Events
	TakeDmg_Implementation(32);
	TakeDmg_ImplementationVer2(55);

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
		AIController->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName,
			Location.Location);
	}

	// Signal the BehaviorTreeComponent that the task finished with success
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);

	UE_LOG(LogTemp, Warning, TEXT("FindRandEnemy Task Node:, %f"), SearchRadius);
	
	Super::ExecuteTask(OwnerComp, NodeMemory);
	return EBTNodeResult::Succeeded;
}

void UAvatarBTTask_FindRandomEnemy::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	//UE_LOG(LogTemp, Warning, TEXT("Tick Task"));
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
}

FString UAvatarBTTask_FindRandomEnemy::GetStaticDescription() const
{
	return FString::Printf(TEXT("Vector: %s"), *BlackboardKey.SelectedKeyName.ToString());
}

void UAvatarBTTask_FindRandomEnemy::TriggerTestFunc() {

}
void UAvatarBTTask_FindRandomEnemy::OnGameplayTaskInitialized(UGameplayTask& Task) {
	UE_LOG(LogTemp, Warning, TEXT("BB Task Init"));
}

void UAvatarBTTask_FindRandomEnemy::OnGameplayTaskActivated(UGameplayTask& Task) {
	UE_LOG(LogTemp, Warning, TEXT("BB Task Activated"));
}

void UAvatarBTTask_FindRandomEnemy::OnGameplayTaskDeactivated(UGameplayTask& Task) {
	UE_LOG(LogTemp, Warning, TEXT("BB Task Deactivated"));
}

void UAvatarBTTask_FindRandomEnemy::TakeDmg_ImplementationVer2_Implementation(int32 Damage) {
	// Needs to add "_Implementation" to differentiate c++ and BP versions
	UE_LOG(LogTemp, Warning, TEXT("Event Called: Damage is: {%d}"), Damage);
}