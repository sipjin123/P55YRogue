// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "P5YY/Enums/GameEnums.h"
#include "UObject/Interface.h"
#include "IGenericAI.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIGenericAI : public UInterface
{
	GENERATED_BODY()
};

class P5YY_API IIGenericAI
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	void EquipWeapon();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	void UnequipWeapon();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	void Attack();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Setup")
	void OnSetCombatRadius(float MeleeRadius, float MeleeStrafeRadius, float RangedRadius, float RangedStrafeRadius);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Setup")
	void OnSetMovement(float WalkSpeed, float RunSpeed);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Setup")
	void OnSetMovementType(EMovementType MovementType);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Setup")
	void OnSetMaxLife(int MaxLife);
	void OnSetMaxLife_Implementation(int MaxLife);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Setup")
	void OnGetCurrentHealth(float& Health);
	void OnGetCurrentHealth_Implementation(float& Health);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Setup")	
	void OnGetCombatRadius(float& MeleeRadius, float &MeleeStrafeRadius, float& RangedRadius, float &RangedStrafeRadius);
	void OnGetCombatRadius_Implementation(float& MeleeRadius, float &MeleeStrafeRadius, float& RangedRadius, float &RangedStrafeRadius);
};