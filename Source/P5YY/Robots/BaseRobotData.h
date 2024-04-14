#pragma once
#include "P5YY/Enums/RobotType.h"
#include "BaseRobotData.generated.h"

USTRUCT(BlueprintType)
struct FBaseRobotData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	int32 Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	ERobotType RobotType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	float MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	float MaxFuel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	float MaxResourceCapacity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	float MovementSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	float MiningSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	float UnloadingSpeed;
	
	FBaseRobotData()
	{
		Id = 0;
		RobotType = ERobotType::None;
		MaxHealth = 0.0f;
		MaxFuel = 0.0f;
		MaxResourceCapacity = 0.0f;
		MovementSpeed = 0.0f;
		MiningSpeed = 0.0f;
		UnloadingSpeed = 0.0f;
	}
};