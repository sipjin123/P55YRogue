// Copyright Epic Games, Inc. All Rights Reserved.

#include "P5YYGameMode.h"
#include "P5YYCharacter.h"
#include "UObject/ConstructorHelpers.h"

AP5YYGameMode::AP5YYGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
