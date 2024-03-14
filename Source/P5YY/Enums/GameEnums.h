// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EFactionType : uint8 {
	Neutral = 0 UMETA(DisplayName = "None"),
	Allies = 1 UMETA(DisplayName = "Allies"),
	Mechs = 2 UMETA(DisplayName = "Mechs"),
	Ancients = 3 UMETA(DisplayName = "Ancients"),
	Wildings = 4 UMETA(DisplayName = "Wildings")
};

UENUM(BlueprintType)
enum class ECombatType : uint8 {
	None = 0 UMETA(DisplayName = "None"),
	Melee = 1 UMETA(DisplayName = "Melee"),
	Ranged = 2 UMETA(DisplayName = "Ranged"),
	Mage = 3 UMETA(DisplayName = "Mage"),
	Healer = 4 UMETA(DisplayName = "Healer")
};

UENUM(BlueprintType)
enum class EMovementType : uint8 {
	None = 0,
	Walking = 1,
	Jogging = 2,
	Running = 3,
	Flying = 3
};

UENUM(BlueprintType)
enum class EEnemyType : uint8 {
	None = 0 UMETA(DisplayName = "None"),
	Melee1 = 1 UMETA(DisplayName = "Droid"),
	Ranged1 = 2 UMETA(DisplayName = "ScoutDroid"),
	Mage1 = 3 UMETA(DisplayName = "Magus"),
	Healer1 = 4  UMETA(DisplayName = "Willow")
};

class P5YY_API GameEnums
{
public:
	GameEnums();
	~GameEnums();
};
