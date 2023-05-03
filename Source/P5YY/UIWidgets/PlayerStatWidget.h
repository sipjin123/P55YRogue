// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerStatWidget.generated.h"

/**
 * 
 */
UCLASS()
class P5YY_API UPlayerStatWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetHealth(float CurrHealth, float MaxHealth);
	void SetStamina(float Currstamina, float MaxStamina);

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		class UProgressBar* HealthBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		class UProgressBar* StaminaBar;
};
