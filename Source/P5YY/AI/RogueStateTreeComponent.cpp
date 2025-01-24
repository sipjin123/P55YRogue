// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueStateTreeComponent.h"

URogueStateTreeComponent::URogueStateTreeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void URogueStateTreeComponent::BeginPlay()
{
	Super::BeginPlay();
}

void URogueStateTreeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void URogueStateTreeComponent::SetStateTree(UStateTree* InStateTree)
{
	StateTreeRef.SetStateTree(InStateTree);
	InitializeComponent();
}
