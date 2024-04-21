#include "ATurretBase.h"
#include "Engine/StaticMesh.h"

ATurretBase::ATurretBase()
{
	StatMeshSource = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StatMeshComp"));
	StatMeshSource->SetVisibility(true);
	StatMeshSource->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ATurretBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATurretBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
