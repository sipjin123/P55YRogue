// Fill out your copyright notice in the Description page of Project Settings.


#include "ASpawnableObj.h"
#include "Engine/Engine.h"
#include "Components/BoxComponent.h"
#include "Engine/StaticMesh.h"
#include "UObject/Object.h"


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


void AASpawnableObj::OnComponentOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OVERLAP BEGIN C:, %f"), 22.f);
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, "Enter Me");
}

/*
void AASpawnableObj::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("OVERLAP END C:, %f"), 12.f);
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, "Exit Me");
}
*/

void AASpawnableObj::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("OVERLAP ENDDDDDD C:, %f"), 12.f);
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, "Exit Me");
}

// Called every frame
void AASpawnableObj::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

