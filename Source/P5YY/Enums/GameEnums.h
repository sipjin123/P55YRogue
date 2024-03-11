// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class ECombatState : uint8 {
	None = 0 UMETA(DisplayName = "None"),
	Melee = 1 UMETA(DisplayName = "Melee"),
	Ranged = 2 UMETA(DisplayName = "Ranged"),
	Mage = 3 UMETA(DisplayName = "Mage"),
};
class P5YY_API GameEnums
{
public:
	GameEnums();
	~GameEnums();
};
