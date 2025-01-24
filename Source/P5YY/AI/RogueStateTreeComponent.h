// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StateTreeComponent.h"
#include "RogueStateTreeComponent.generated.h"

/**From Dev Gods Tutorial, Prerequisite for Modularization
 * https://www.youtube.com/watch?v=q8aOl5TIho0&t=2501s
 */

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class P5YY_API URogueStateTreeComponent : public UStateTreeComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	URogueStateTreeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "State Tree")
	void SetStateTree(UStateTree* InStateTree);
};