#pragma once

UENUM(BlueprintType)
enum class EPlayerActionState : uint8 {
	None = 0 UMETA(DisplayName = "None"),
	Combat = 1,
	Build = 2,
	Customize = 3
};

struct PlayerActionState
{
	
};
