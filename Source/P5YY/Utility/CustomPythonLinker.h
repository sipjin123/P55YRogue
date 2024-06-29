#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CustomPythonLinker.generated.h"

UCLASS()
class P5YY_API UCustomPythonLinker : public  UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category="Unreal Python")
	static void ExecuteConsoleCommand(FString ConsoleCommand);
};
