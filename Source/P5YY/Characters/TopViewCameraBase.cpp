#include "TopViewCameraBase.h"


// Sets default values
ATopViewCameraBase::ATopViewCameraBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATopViewCameraBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATopViewCameraBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TargetActor)
	{
		FVector NewLoc = FMath::VInterpTo(GetActorLocation(), TargetActor->GetActorLocation(), DeltaTime, LerpSpeed);
		SetActorLocation(NewLoc);
	}
}

