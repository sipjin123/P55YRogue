#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "P5YY/Enums/ProjectileType.h"
#include "WeaponData.generated.h"

// Note: Use soft reference for object and classes only

USTRUCT(BlueprintType)
struct FWeaponData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Name;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Description;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float BaseDamage;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Ammo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Durability;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float RateOfFire;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	ProjectileType ProjectileType;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<UStaticMesh> WeaponModel;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<AActor> ActorClass;
};
