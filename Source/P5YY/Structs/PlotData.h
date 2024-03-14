#pragma once
#include "CropSpotData.h"
#include "PlotData.generated.h"

USTRUCT(BlueprintType)
struct FPlotData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlotId;
	//CropSpotData CropSpotDataCollection[];
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCropSpotData> CropSpotDataCollection;
	FPlotData()
	{
		PlotId = 0;
		//CropSpotDataCollection = new TArray<CropSpotData>();
	}
};
