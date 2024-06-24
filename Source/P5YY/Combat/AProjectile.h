// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "P5YY/Enums/GameEnums.h"
#include "AProjectile.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FReturnedToOwner);

UCLASS()
class P5YY_API AAProjectile : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AAProjectile();

	// Sphere collision component.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
		class USphereComponent* CollisionSphere;

	// Projectile movement component.
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (AllowPrivateAccess), Category = "Movement") // Add this to ensure editor visibility in details panel
		class UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display")
		class UStaticMeshComponent* StaticMeshSource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		float Damage;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats", meta = (ExposeOnSpawn="true"))
		float Velocity;
		
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		float TargetPredictionRadius = 10.f;
		
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		float TargetPredictionLength = 1000.f;
		
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		int PassableTargets;
		
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		float Lifetime;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		EFactionType OwnerFaction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		bool IgnorePreset;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		bool ExplodesOnCollision;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		FVector SpawnLocation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		FVector TargetLocation;
	
	// Test for SmartSvn
	// Test from Sourcetree part 2
public:
	UFUNCTION(BlueprintCallable, Category = "Properties")
	void InitializeProjectileVelocity(float NewSpeed, FVector NewVelocity, FVector SpawnPoint, FRotator StartRotator);
	UFUNCTION(BlueprintCallable, Category = "Properties")
	void InitializeProjectile(FVector NewDirection, FVector SpawnPoint, FRotator StartRotator);
	UFUNCTION(BlueprintCallable, Category = "Properties")
	void InitializeProjectileTowards(FVector NewTargetLocation, FVector NewDirection, FVector SpawnPoint, FRotator StartRotator);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "Properties")
	void SetStartLocation(FVector NewLocation);
	UFUNCTION(BlueprintCallable, Category = "Properties")
	void SetTargetLocation(FVector NewLocation);
	UFUNCTION(BlueprintCallable, Category = "Properties")
	void SetFaction(EFactionType NewFaction);
	
	// Allows calling teleport event across c++ and BP
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FReturnedToOwner HasReturnedToOwner; // Can be called via c++ using Broadcast
};
