// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameInstanceSubsystem.h"

DEFINE_LOG_CATEGORY(InstanceSubsystemLog);
void UCustomGameInstanceSubsystem::TestFunc()
{
	TestInt++;
}

void UCustomGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	UE_LOG(InstanceSubsystemLog, Log, TEXT("INITIALIZED INSTANCE SUBSYSTEM C++"));
	Super::Initialize(Collection);
	InitEventCalledInBlueprint();
}
