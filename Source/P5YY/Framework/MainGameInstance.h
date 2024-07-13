// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MainGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class P5YY_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	virtual void Init() override;
	virtual void Shutdown() override;
};
