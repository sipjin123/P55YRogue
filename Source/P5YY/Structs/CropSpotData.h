#pragma once

#include "CropSpotData.generated.h"

USTRUCT(BlueprintType)
struct FCropSpotData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlotId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SpotId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CropId;
	
	FCropSpotData()
	{
		PlotId = 0;
		SpotId = 0;
		CropId = 0;
	}
};
