// Fill out your copyright notice in the Description page of Project Settings.


#include "ASpawnableObj.h"
#include "Engine/Engine.h"
#include "Components/BoxComponent.h"
#include "Engine/StaticMesh.h"
#include "UObject/Object.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AASpawnableObj::AASpawnableObj()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SceneComponent;

	NewCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCompRoot"));
	NewCollisionBox->SetBoxExtent(FVector(15, 15, 15));
	NewCollisionBox->SetCollisionProfileName("TriggerCon");
	NewCollisionBox->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AASpawnableObj::TestSpawn()
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, "Spawn Test Me");
}

// Called when the game starts or when spawned
void AASpawnableObj::BeginPlay()
{
	Super::BeginPlay();
	NewCollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AASpawnableObj::OnComponentOverlapBegin);
	NewCollisionBox->OnComponentEndOverlap.AddDynamic(this, &AASpawnableObj::OnComponentEndOverlap);
}

void AASpawnableObj::GetRandomSpawnPoint() {
	const FVector SpawnOrigin = NewCollisionBox->Bounds.Origin;
	const FVector SpawnLimit = NewCollisionBox->Bounds.BoxExtent;

	FVector NewSpawnPoint = UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnLimit);
}

void AASpawnableObj::OnComponentOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	float Distance = FVector::Dist(GetActorLocation(), OtherActor->GetActorLocation());
	UE_LOG(LogTemp, Warning, TEXT("Overlap Begin with Component: "), Distance);
}

void AASpawnableObj::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	float Distance = FVector::Dist(GetActorLocation(), OtherActor->GetActorLocation());
	UE_LOG(LogTemp, Warning, TEXT("Overlap END with Component: %f"), Distance);
}

// Called every frame
void AASpawnableObj::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

