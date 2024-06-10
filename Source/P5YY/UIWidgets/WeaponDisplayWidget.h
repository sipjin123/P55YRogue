// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Engine/DataTable.h"
#include "WeaponDisplayWidget.generated.h"

/**
 * 
 */
UCLASS()
class P5YY_API UWeaponDisplayWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(RowType="WeaponData"))
	FDataTableRowHandle Weapon;
};
