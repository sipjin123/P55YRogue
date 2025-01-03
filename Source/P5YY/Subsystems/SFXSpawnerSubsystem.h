// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "SFXSpawnerSubsystem.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class P5YY_API USFXSpawnerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)

	// ReSharper disable once CppUEBlueprintImplementableEventNotImplemented
	void InitEventCalledInBlueprint();

protected:
	virtual void Initialize(FSubsystemCollectionBase& collection) override;
};
