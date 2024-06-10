#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "WeaponData.generated.h"

USTRUCT(BlueprintType)
struct FWeaponData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Name;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float BaseDamage;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Ammo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float RateOfFire;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<UStaticMesh> WeaponModel;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<AActor> ActorClass;
};

// Note: Use soft reference for object and classes only
