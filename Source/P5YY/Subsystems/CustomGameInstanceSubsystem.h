// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "P5YY/Data/InventoryTrackerDA.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CustomGameInstanceSubsystem.generated.h"

/**
 * 
 */

DECLARE_LOG_CATEGORY_EXTERN(InstanceSubsystemLog, Log, All);
UCLASS(Abstract, Blueprintable)
class P5YY_API UCustomGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
	int TestInt = 0;
public:
	UFUNCTION(BlueprintCallable)
	void TestFunc();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintImplementableEvent)
	// ReSharper disable once CppUEBlueprintImplementableEventNotImplemented
	void InitEventCalledInBlueprint();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<const UInventoryTrackerDA> InventoryTrackerDA;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UInventoryTrackerDA> InventoryTrackerDASub;
};
