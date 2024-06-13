#pragma once
#include "P5YY/Enums/RobotType.h"
#include "MinerData.generated.h"

USTRUCT(BlueprintType)
struct FMinerData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32  UnitId;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float  MaxHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float  MaxEnergy;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float  MaxCargo;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float  MovementSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ERobotType RobotType;

	FMinerData()
	{
		UnitId = 0;
		MaxHealth = 100;
		MaxEnergy = 100;
		MaxCargo = 100;
		MovementSpeed = 500;
		
		RobotType = ERobotType::None;
	}
};
