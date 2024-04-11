#pragma once

UENUM(BlueprintType)
enum class EMinerState : uint8 {
	None = 0 UMETA(DisplayName = "None"),
	FindTarget = 1,
	MoveToTarget = 2,
	Mining = 3,
	ReturnResource = 4,
	StoringResource = 5,
	Charging = 6,
	Dead = 7,
	Processing = 8
};

struct MinerState
{
	
};
