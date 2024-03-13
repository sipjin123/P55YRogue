// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "P5YY/Enums/GameEnums.h"
#include "P5YY\Public\BaseAttributeSet.h"
#include "AAICharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAttackEnded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEquipWeapon);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUnequipWeapon);

UCLASS()
class P5YY_API AAAICharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAAICharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GAS", meta = (AllowPrivateAccess="true"))
	class UAbilitySystemComponent* AbilitySystemComponent;

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return  AbilitySystemComponent;
	}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GAS", meta = (AllowPrivateAccess="true"))
	const class UBaseAttributeSet* BaseAttributeSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	int AttackSlots = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	int MaxAttackSlots = 1;
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FAttackEnded AttackEnded;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	bool IsAttacking;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float MeleeRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float MeleeStrafeRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float RangedRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float RangedStrafeRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float WalkSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float RunSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	EEnemyType EnemyType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	ECombatType CombatType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	EMovementType MovementType;
	
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnEquipWeapon OnEquipWeaponTrigger;
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnUnequipWeapon OnUnequipWeaponTrigger;
};
