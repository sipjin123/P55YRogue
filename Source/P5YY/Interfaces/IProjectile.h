#pragma once

#include "CoreMinimal.h"
#include "P5YY/Enums/GameEnums.h"
#include "UObject/Interface.h"
#include "IProjectile.generated.h"


USTRUCT(Blueprintable)
struct FProjectileVectors
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector StartPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector TargetPosition;

	FProjectileVectors()
	{
		StartPosition = FVector::Zero();
		TargetPosition = FVector::Zero();
	}
};


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIProjectile : public UInterface
{
	GENERATED_BODY()
};

class P5YY_API IIProjectile
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	FProjectileVectors GetProjectileVectors();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	void TriggerImpulse(FVector Location);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	EFactionType GetFactionOwner();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	TArray<AActor*> GetActorsToHit(bool ShowDebug, float DebugDuration = 2.0f);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	AActor* GetActorToHit(bool ShowDebug, float DebugDuration = 2.0f);
};