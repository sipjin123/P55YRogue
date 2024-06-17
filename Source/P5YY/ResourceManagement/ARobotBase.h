// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "P5YY/ResourceManagement/AResourceBase.h"
#include "P5YY/Enums/GameEnums.h"
#include "P5YY/Structs/MinerActiveData.h"
#include "ARobotBase.generated.h"

UCLASS()
class P5YY_API AARobotBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AARobotBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	EFactionType FactionType;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* MiningShipActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	UMinerActiveData* MinerActiveData;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	AAResourceBase* CurrentResourceTarget;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
