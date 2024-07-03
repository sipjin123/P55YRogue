#pragma once

struct CompanionState
{
	
};

UENUM(BlueprintType)
enum class ECompanionState : uint8 {
	None = 0 UMETA(DisplayName = "None"),
	AssessCombat = 1,
	MoveToTarget = 2,
	MoveToLeader = 3,
	Retreat = 4,
	Attack = 5,
	UseAbility = 6,
	Strafe = 7,
	Orbit = 8,
	Roam = 9,
	Die = 10,
	Protect = 11,
};
