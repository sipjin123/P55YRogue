// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "P5YY/ResourceManagement/AHarvestMaster.h"
#include "P5YY/Structs/FCropData.h"
#include "UObject/Interface.h"
#include "IHarvestable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIHarvestable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class P5YY_API IIHarvestable
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Harvesting")
	void SetupCropData(FCropData NewCropData);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Harvesting")
	bool IsHarvestable();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Harvesting")
	void RegisterToHarvestMaster(AACropBase* Crop, int CropSlotId, int CropPlotId, bool& HasSucceeded);
	void RegisterToHarvestMaster_Implementation(AACropBase* Crop, int CropSlotId, int CropPlotId, bool& HasSucceeded);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Harvesting")
	AAHarvestMaster* GetHarvestMaster();
};
