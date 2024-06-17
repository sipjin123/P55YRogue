#pragma once
#include "P5YY/Enums/RobotType.h"
#include "MiningVehicleData.generated.h"

// Struct to Class Convert!
//USTRUCT(BlueprintType)
UCLASS()
class P5YY_API UMiningVehicleData : public UObject
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
	float  MaxCargo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float  CurrentCargo;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float  MovementSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float  MineRadius;
	/*
	UMiningVehicleData()
	{
		UnitId = 0;
		MaxHealth = 100;
		MaxEnergy = 100;
		MaxCargo = 100;
		CurrentCargo = 0;
		MovementSpeed = 500;
	}*/
};
