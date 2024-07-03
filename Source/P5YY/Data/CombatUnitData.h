#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CombatUnitData.generated.h"

USTRUCT(BlueprintType)
struct FCombatUnitData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="BaseStats")
	float CurrentHealth;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="BaseStats")
	float MaxHealth;
	
	/** Slots you take as a Defender */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="BaseStats")
	int AttackSlots;

	/** Slots you take as an Attacker */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="BaseStats")
	int ConsumedAttackSlots;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="BaseStats")
	int MaxAttackSlots;
	
	FCombatUnitData()
	{
		CurrentHealth = 0;
		MaxHealth = 0;
		AttackSlots = 0;
		ConsumedAttackSlots = 0;
		MaxAttackSlots = 0;
	}
};
