// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatWidget.h"
#include "Components/ProgressBar.h"

void UPlayerStatWidget::SetHealth(float CurrHealth, float MaxHealth) {
	if (HealthBar) {
		HealthBar->SetPercent(CurrHealth / MaxHealth);
	}
}

void UPlayerStatWidget::SetStamina(float Currstamina, float MaxStamina) {
	if (StaminaBar) {
		StaminaBar->SetPercent(Currstamina / MaxStamina);
	}
}