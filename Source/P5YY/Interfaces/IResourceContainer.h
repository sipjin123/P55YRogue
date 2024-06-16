#pragma once

#include "CoreMinimal.h"
#include "P5YY/Enums/GameEnums.h"
#include "UObject/Interface.h"
#include "P5YY/ResourceManagement/AResourceBase.h"
#include "IResourceContainer.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIResourceContainer : public UInterface
{
	GENERATED_BODY()
};

class P5YY_API IIResourceContainer
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Base")
	FVector GetResourceReturnLocation(FVector OriginLocation);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Harvesting")
	AAResourceBase* RequestResourceTarget();
};