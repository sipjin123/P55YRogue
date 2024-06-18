// Copyright Epic Games, Inc. All Rights Reserved.

#include "P5YYGameMode.h"
//#include "P5YYCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "DrawDebugHelpers.h"

AP5YYGameMode::AP5YYGameMode()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	//if (PlayerPawnBPClass.Class != NULL)
	//{
		//DefaultPawnClass = PlayerPawnBPClass.Class;
		//AAGenTestActor* genTest = NULL;
		//AASpawnableObj* genTest2 = NULL;
	//}
}

void AP5YYGameMode::UpdateGameModeNewX()
{
	UE_LOG(LogTemp, Warning, TEXT("Game mode is now called"));
}
