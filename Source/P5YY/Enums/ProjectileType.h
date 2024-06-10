#pragma once

UENUM(BlueprintType)
enum class ProjectileType : uint8 {
	None = 0,
	Normal = 1,
	HighAngle = 2,
	Curved = 3,
	Piercing = 4
};
