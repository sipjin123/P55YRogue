// Fill out your copyright notice in the Description page of Project Settings.


#include "AShipPawn.h"

#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AAShipPawn::AAShipPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SceneComponent;

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	CollisionComponent->SetCollisionProfileName("SphereCollision");
	CollisionComponent->SetupAttachment(RootComponent);

	StaticMeshSource = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StatMeshComp"));
	StaticMeshSource->SetVisibility(true);
	StaticMeshSource->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	if (!MovementComponent)
	{
		// Use this component to drive this projectile's movement.
		MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
		MovementComponent->SetUpdatedComponent(RootComponent);
		MovementComponent->MaxSpeed = 1500.0f;
	}
}

// Called when the game starts or when spawned
void AAShipPawn::BeginPlay()
{
	VehicleData = NewObject<UMiningVehicleData>();
	Super::BeginPlay();
}

// Called every frame
void AAShipPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAShipPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

