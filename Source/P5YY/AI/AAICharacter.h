// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "P5YY\Public\BaseAttributeSet.h"
#include "AAICharacter.generated.h"

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
};
