#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "P5YY/Enums/GameEnums.h"
#include "ATurretBase.generated.h"

UCLASS()
class ATurretBase  : public APawn
{
	GENERATED_BODY()
public:
	ATurretBase();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* StatMeshSource;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	AActor* TargetActor;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float LookLerpSpeedYaw = 100.f;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	EFactionType FactionType;
		
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float LookLerpSpeedPitch = 100.f;
		
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float TargetMaxDistance = 2000.f;
		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
