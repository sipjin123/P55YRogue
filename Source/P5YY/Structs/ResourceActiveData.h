#pragma once
#include "P5YY/Enums/RobotType.h"
#include "ResourceActiveData.generated.h"

UCLASS()
class P5YY_API UResourceActiveData : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32  UnitId;

	// Use id instead of enum for flexibility
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32  ResourceIdType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float  MaxResource;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float  CurrentResource;
};
