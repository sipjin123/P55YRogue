#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "BCustomUtility.generated.h"


UCLASS()
class P5YY_API UBCustomUtility : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "My DLL Library")
	static void Test(int a, int b);
	
	UFUNCTION(BlueprintCallable)
	static FVector GetViewportCamLoc();
	UFUNCTION(BlueprintCallable)
	static FRotator GetViewportCamRot();
};