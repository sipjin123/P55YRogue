// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "P5YY/Structs/MiningVehicleData.h"
#include "AShipPawn.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHasReachedMaxCargo);

UCLASS()
class P5YY_API AAShipPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAShipPawn();

	// Box collision component.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	class UBoxComponent* CollisionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USceneComponent* SceneComponent;

	// Movement component.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
	class UFloatingPawnMovement* MovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display")
	class UStaticMeshComponent* StaticMeshSource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	UMiningVehicleData* VehicleData;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FHasReachedMaxCargo HasReachedMaxCargo;
};
