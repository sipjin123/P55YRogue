// Fill out your copyright notice in the Description page of Project Settings.


#include "ACMobilityHandling.h"
#include "Components/SphereComponent.h"
#include "P5YY/Characters/ProtagonistChar.h"

// Sets default values for this component's properties
UACMobilityHandling::UACMobilityHandling()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UACMobilityHandling::BeginPlay()
{
	Super::BeginPlay();
	SourceActor = Cast<AProtagonistChar>(GetOwner());
}

// Called every frame
void UACMobilityHandling::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UACMobilityHandling::InitializeComponent() {
	UE_LOG(LogTemp, Warning, TEXT("Initializing MobilityComponent"));
}

void UACMobilityHandling::RegisterTargetActor(AActor* NewTargetActor)
{
	// CURRENT ISSUE: Cant Overwrite TargetActor without CRASHING!!!
	//TargetActor = NewTargetActor;
	if (NewTargetActor == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to Register New Target to MobilityComponent"));
		return;
	}
	else
	{
#if WITH_EDITOR
		UE_LOG(LogTemp, Warning, TEXT("Registered New Target to MobilityComponent: %s"), *NewTargetActor->GetActorLabel());
#endif
	}
}

void UACMobilityHandling::ServerTriggerMobilityPoint_Implementation(FVector coordinates, AActor* actorRef)
{
	// Handle teleport only on server side since transform is replicated
	if (SourceActor->TargetMobilityNode)
	{
		SourceActor->NetTeleport(SourceActor->TargetMobilityNode->GetActorLocation());
	}
	else
	{
		SourceActor->NetTeleport(TargetLocation);
	}

	// Handle Debug Behavior here across all clients
	MultiTriggerMobilityPoint(coordinates, actorRef);
}

void UACMobilityHandling::MultiTriggerMobilityPoint_Implementation(FVector coordinates, AActor* actorRef)
{
	// Assign Raw Coordinates
	TargetLocation = coordinates;
	if (actorRef != NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("MobilityComponent Warp Client using Actor"));
		// Extract target actor coordinates before destroying
		TargetLocation = actorRef->GetActorLocation();
		actorRef->Destroy();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MobilityComponent Warp Client using Vector"));
	}

	// Generate debug object to simulate visual indicator where the spawn mobility point is
	DrawDebugSphere(GetWorld(), TargetLocation, 30, 12, FColor::Red, false, 2);
	PositionSphere->SetWorldLocation(TargetLocation);
}
