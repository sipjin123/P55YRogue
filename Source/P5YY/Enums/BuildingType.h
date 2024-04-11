#pragma once

UENUM(BlueprintType)
enum class EBuildingType : uint8 {
	None = 0 UMETA(DisplayName = "None"),
	SleepingHut = 1 UMETA(DisplayName = "Sleeping Hut"),
	Storage = 2 UMETA(DisplayName = "Storage Node"),
	FarmingHub = 3 UMETA(DisplayName = "Farming Hub"),
	MiningHub = 4 UMETA(DisplayName = "Mining Hub"),
	WindGenerator = 5 UMETA(DisplayName = "Mining Hub"),
	SolarGenerator = 6 UMETA(DisplayName = "Solar Generator"),
	ResourceBay = 7 UMETA(DisplayName = "Reource Bay"),
	Workshop = 8 UMETA(DisplayName = "Workshop"),
	Kitchen = 9 UMETA(DisplayName = "Kitchen"),
	Techhub = 10 UMETA(DisplayName = "Tech hub"),
};

struct BuildingType
{
	
};
