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
	Processing = 8,
	DeployingPawns = 9,
	CallbackPawns = 10,
	MoveToExitNode = 11,
	ExitParking = 12,
	MoveToParking = 13,
	ReturnToSpawner = 14,
	BoardMiningVehicle = 15,
	InitializeBoardingSequence = 16
};

struct MinerState
{
	
};
