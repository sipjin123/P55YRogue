#pragma once
UENUM(BlueprintType)
enum class ERobotType : uint8 {
	None = 0 UMETA(DisplayName = "None"),
	Prototype = 1 UMETA(DisplayName = "Prototype"),
	Axle = 2 UMETA(DisplayName = "Axle"),
	Rotor = 3 UMETA(DisplayName = "Rotor"),
	Biped = 4 UMETA(DisplayName = "Biped"),
	Hopper = 5 UMETA(DisplayName = "Hopper"),
};

struct RobotType
{
};
