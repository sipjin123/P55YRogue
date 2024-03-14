#pragma once
#include "P5YY/Enums/CropsEnum.h"
#include "FCropData.generated.h"

USTRUCT(BlueprintType)
struct FCropData
{
	GENERATED_BODY()//GENERATED_USTRUCT_BODY();//GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32  CropID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32  PlotId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32  SpotId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECropType CropType;

	FCropData()
	{
		CropID = 0;
		PlotId = 0;
		SpotId = 0;
		CropType = ECropType::None;
	}
};
