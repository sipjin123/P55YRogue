// Fill out your copyright notice in the Description page of Project Settings.


#include "IDamageable.h"

// Add default functionality here for any IIDamageable functions that are not pure virtual.

void IIDamageable::ReserveAttackSlot_Implementation(int Slots, bool& Success)
{
	ReserveAttackSlot(Slots, Success);
}

void IIDamageable::GetMaxAttackSlot_Implementation(int& Slots)
{
	GetMaxAttackSlot(Slots);
}

void IIDamageable::GetCurrentAttackSlot_Implementation(int& Slots)
{
	GetCurrentAttackSlot(Slots);
}

void IIDamageable::AttackStart_Implementation(int AttackSlotsNeeded, AActor* TargetActor, bool& Success)
{
	AttackStart(AttackSlotsNeeded, TargetActor, Success);
}

void IIDamageable::GetFactionType_Implementation(EFactionType& FactionType)
{
	GetFactionType((FactionType));
}
