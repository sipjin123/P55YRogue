#pragma once
#include "MinerActiveData.generated.h"

UCLASS()
class P5YY_API UMinerActiveData : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32  UnitId;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float  MaxHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float  MaxEnergy;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float  ResourcePerHit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float  MaxCargo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float  CurrentCargo;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float  MovementSpeed;
};
