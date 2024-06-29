// Copyright Epic Games, Inc. All Rights Reserved.

#include "BCLogicUtilityBPLibrary.h"
#include "BCLogicUtility.h"

float UBCLogicUtilityBPLibrary::TestFunctionBG(float NewFloat, int NewInt)
{
	NewFloat += 5;
	
	UE_LOG(LogTemp, Warning, TEXT("Lock Target Success: Test"));
	return NewFloat;
}

float UBCLogicUtilityBPLibrary::TestFunctionPureBG(float NewFloat, int NewInt)
{
	return  5.0f;
}
