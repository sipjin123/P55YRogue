// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
//#include "ASpawnableObj.h"
//#include "Prototypes/AGenTestActor.h"
#include "P5YYGameMode.generated.h"

UCLASS()//UCLASS(minimalapi)
class AP5YYGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AP5YYGameMode();

	UFUNCTION(BlueprintCallable, Category = "Group1")
		virtual void UpdateGameModeNewX();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<APawn> CustomChar;
};



