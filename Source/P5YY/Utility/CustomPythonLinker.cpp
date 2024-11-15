#include "CustomPythonLinker.h"
#if WITH_EDITOR
#include "Editor/UnrealEd/Public/Editor.h"
#include "Editor/UnrealEd/Public/LevelEditorViewport.h"
#endif
void UCustomPythonLinker::ExecuteConsoleCommand(FString ConsoleCommand)
{
#if WITH_EDITOR
	if (GEditor)
	{
		UWorld* world = GEditor->GetEditorWorldContext().World();
		if (world)
		{
			GEditor->Exec(world, *ConsoleCommand, *GLog);
		}
	}
#endif
}
void UCustomPythonLinker::MyTest_Implementation()
{
	// Logic needed when blueprints don't implement the event. Can be empty.
}
float UCustomPythonLinker::CallMyTest()
{
	return 1.;
}

void UCustomPythonLinker::CalledFromPython(FString wat)
{
	UE_LOG(LogTemp, Error, TEXT("%s"), *wat);
}
