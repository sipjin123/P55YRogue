// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlantBase.generated.h"

UCLASS()
class P5YY_API APlantBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlantBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USceneComponent* PivotComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display")
	class UStaticMeshComponent* StaticMeshSource;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
