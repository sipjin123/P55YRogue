#pragma once

#include "CoreMinimal.h"
#include "P5YY/Enums/GameEnums.h"
#include "UObject/Interface.h"
#include "IProjectileSource.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIProjectileSource : public UInterface
{
	GENERATED_BODY()
};

class P5YY_API IIProjectileSource
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	void ShootProjectileAt(FVector TargetLocation, int ProjectileCount, float ProjectileInterval);
};