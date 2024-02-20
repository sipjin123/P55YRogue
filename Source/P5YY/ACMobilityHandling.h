// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/ProtagonistChar.h"
#include "Components/ActorComponent.h"
#include "ACMobilityHandling.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class P5YY_API UACMobilityHandling : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UACMobilityHandling();

	// Sphere collision component.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	class USphereComponent* PositionSphere;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	AProtagonistChar* SourceActor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* TargetActor;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
	bool CanMove;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
	FVector TargetLocation;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void InitializeComponent();
	void RegisterTargetActor(AActor* NewTargetActor);
	
	UFUNCTION(BlueprintCallable, Category = "Properties")
	void TriggerMobilityPoint(FVector coordinates, AActor* actorRef);
};
