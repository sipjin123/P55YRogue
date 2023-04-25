// Fill out your copyright notice in the Description page of Project Settings.


#include "AvatarAIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

AAvatarAIController::AAvatarAIController(FObjectInitializer const& obj_init) {
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComp"));
	BehaviorTree = CreateDefaultSubobject<UBehaviorTree>(TEXT("BehaviorTree"));
	Blackboard = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
}

void AAvatarAIController::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("C++ Begin AIControl"));
}


void AAvatarAIController::OnPossess(APawn* const pawn) {
	Super::OnPossess(pawn);
	UE_LOG(LogTemp, Warning, TEXT("C++ Possess AIControl"));

}

UBlackboardComponent* AAvatarAIController::get_blackboard() const {
	return Blackboard;// Inherited variable
}