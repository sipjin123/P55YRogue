// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "P5YY/Enums/CropsEnum.h"
#include "P5YY/Interfaces/IHarvestable.h"
#include "ACropBase.generated.h"

UCLASS()
class P5YY_API AACropBase : public AActor, public IIHarvestable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AACropBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display")
	class UStaticMeshComponent* StaticMeshSource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USceneComponent* SceneComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	ECropType CropType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int CropId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int CropSpotId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int PlotId;
};
