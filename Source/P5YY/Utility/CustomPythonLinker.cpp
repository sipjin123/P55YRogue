#include "CustomPythonLinker.h"

#include "Editor/UnrealEd/Public/Editor.h"
#include "Editor/UnrealEd/Public/LevelEditorViewport.h"

void UCustomPythonLinker::ExecuteConsoleCommand(FString ConsoleCommand)
{
	if (GEditor)
	{
		UWorld* world = GEditor->GetEditorWorldContext().World();
		if (world)
		{
			GEditor->Exec(world, *ConsoleCommand, *GLog);
		}
	}
}
