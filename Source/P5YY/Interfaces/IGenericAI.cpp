// Fill out your copyright notice in the Description page of Project Settings.


#include "IGenericAI.h"

void IIGenericAI::OnSetMaxLife_Implementation(int MaxLife)
{
	OnSetMaxLife(MaxLife);
}

void IIGenericAI::OnGetCurrentHealth_Implementation(float& Health)
{
	OnGetCurrentHealth(Health);
}

void IIGenericAI::OnGetCombatRadius_Implementation(float& MeleeRadius, float& MeleeStrafeRadius, float& RangedRadius, float& RangedStrafeRadius)
{
	OnGetCombatRadius(MeleeRadius, MeleeStrafeRadius, RangedRadius, RangedStrafeRadius);
}
