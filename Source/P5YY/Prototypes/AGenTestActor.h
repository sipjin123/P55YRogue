// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGenTestActor.generated.h"

UCLASS()
class P5YY_API AAGenTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGenTestActor();

	UFUNCTION(BlueprintCallable, Category="Group1")
		void TestCall1();

	UFUNCTION(BlueprintCallable, Category = "Group1")
		void RaycastTarget();

	UFUNCTION(BlueprintCallable, Category = "Group1")
		void GetOverlapActorFunc();

	UFUNCTION(BlueprintCallable, Category = "Group1")
		void GetOverlapActorRadiusFunc();

	UFUNCTION(BlueprintCallable, Category = "Group1")
		void TriggerTimerDelayTest();

	UFUNCTION(BlueprintCallable, Category = "Group1")
		void MethodWithDelay(int32 TestInt);

	UFUNCTION(BlueprintCallable, Category = "Group1")
		void TickDamageFunc(float DamagePerTick);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TestQuantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DamageTickToTake;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PreviousDamageTick;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool DebugObj;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* BoxCompRoot;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//	class UBoxComponent* RaycastSourceBackup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* StatMeshSource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* StatMeshSourceBackup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USceneComponent* SceneComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
