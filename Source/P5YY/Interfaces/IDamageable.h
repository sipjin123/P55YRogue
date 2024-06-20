// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "P5YY/Enums/GameEnums.h"
#include "UObject/Interface.h"
#include "IDamageable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIDamageable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class P5YY_API IIDamageable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	void OnTakeDamage(float damage);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	void OnDeathTrigger();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	void ReturnAttackSlot(int Slots);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	void StoreAttackSlot(int Slots, AActor* TargetActor);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	void ReserveAttackSlot(int Slots, bool &Success);
	void ReserveAttackSlot_Implementation(int Slots, bool &Success);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	void GetMaxAttackSlot(int& Slots);
	void GetMaxAttackSlot_Implementation(int& Slots);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	void GetCurrentAttackSlot(int& Slots);
	void GetCurrentAttackSlot_Implementation(int& Slots);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Combat")
	AActor* GetTargetActor();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Combat")
	USkeletalMeshComponent* GetSkeletalMesh();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Combat")
	void SetTargetActor(AActor* NewTargetActor);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	void AttackStart(int AttackSlotsNeeded, AActor *TargetActor, bool& Success);
	void AttackStart_Implementation(int AttackSlotsNeeded, AActor *TargetActor, bool& Success);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	void GetFactionType(EFactionType& FactionType);
	void GetFactionType_Implementation(EFactionType& FactionType);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	void AttackEnd(AActor *TargetActor);
};
