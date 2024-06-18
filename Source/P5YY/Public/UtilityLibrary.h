#pragma once

#include "UtilityLibrary.generated.h"

UCLASS(Blueprintable) 
class UUtilityLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
	
	//FORCEINLNE function
	static FORCEINLINE bool IsValid(AActor* TheActor)
	{
		if(!TheActor) return false;
		if(!TheActor->IsValidLowLevel()) return false;
		return true;
	}
public:
	UFUNCTION(BlueprintCallable, Category = "Function Library")
	static bool IsFacingEachOther(FVector SourceVec, FVector TargetVec);
};