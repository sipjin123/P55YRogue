// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AvatarAIController.generated.h"

/**
 * 
 */
UCLASS()
class P5YY_API AAvatarAIController : public AAIController
{
	GENERATED_BODY()
public:
	AAvatarAIController(FObjectInitializer const& obj_init = FObjectInitializer::Get());
	void BeginPlay() override;
	void OnPossess(APawn* const pawn) override;
public:
	class UBlackboardComponent* get_blackboard() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		class UBehaviorTreeComponent* BehaviorTreeComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		class UBehaviorTree * BehaviorTree;
};
