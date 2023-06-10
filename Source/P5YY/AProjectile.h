// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AProjectile.generated.h"

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
	UPROPERTY(EditAnywhere, Category = "Movement")
		class UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display")
		class UStaticMeshComponent* StaticMeshSource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		float Damage;
	
public:
	UFUNCTION(BlueprintCallable, Category = "Properties")
	void InitializeProjectile(FVector& newDirection, FVector& spawnPoint, FRotator& startRotator);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
