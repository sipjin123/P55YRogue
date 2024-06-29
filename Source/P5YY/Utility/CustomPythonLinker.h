#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CustomPythonLinker.generated.h"

UCLASS()
class P5YY_API UCustomPythonLinker : public  UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category="Unreal Python")
	static void ExecuteConsoleCommand(FString ConsoleCommand);
public:
	UFUNCTION(BlueprintImplementableEvent)
	void MyTest();
	void MyTest_Implementation();
	
	UFUNCTION(BlueprintCallable)
	static float CallMyTest();

	UFUNCTION(BlueprintCallable)
	static void CalledFromPython(FString wat);
};
