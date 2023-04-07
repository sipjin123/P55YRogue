// Fill out your copyright notice in the Description page of Project Settings.


#include "AGenTestActor.h"
#include "Components/BoxComponent.h"
#include "Engine/StaticMesh.h"
#include "UObject/Object.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AAGenTestActor::AAGenTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SceneComponent;

	BoxCompRoot = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCompRoot"));
	BoxCompRoot->SetBoxExtent(FVector(15, 15, 15));
	BoxCompRoot->SetCollisionProfileName("TriggerCon");
	BoxCompRoot->SetupAttachment(RootComponent);

	StatMeshSource = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	StatMeshSource->SetCollisionProfileName("MeshXX");
	StatMeshSource->SetVisibility(true);
	StatMeshSource->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	StatMeshSourceBackup = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshCompBackup"));
	StatMeshSourceBackup->SetCollisionProfileName("MeshYY");
	StatMeshSourceBackup->SetVisibility(true);
	StatMeshSourceBackup->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	
	/*
	RaycastSourceBackup = CreateDefaultSubobject<UBoxComponent>(TEXT("SecondBoxComponent"));
	RaycastSourceBackup->SetBoxExtent(FVector(25, 25, 25));
	RaycastSourceBackup->SetCollisionProfileName("TriggerYY");
	RaycastSourceBackup->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	*/
}

// Called when the game starts or when spawned
void AAGenTestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAGenTestActor::TestCall1()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello:, %f"), TestQuantity);
}

void AAGenTestActor::RaycastTarget()
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, "Enter Me");
	UE_LOG(LogTemp, Warning, TEXT("Hello:, %f"), TestQuantity);

	// The length of the raycast
	float LineTraceDistance = 200.f;

	// Get the camera view
	FVector CameraLoc = StatMeshSourceBackup->GetComponentLocation();
	FRotator CameraRot = StatMeshSourceBackup->GetComponentRotation();
	FVector Start = CameraLoc;
	FVector End = CameraLoc + (CameraRot.Vector() * LineTraceDistance);

	UE_LOG(LogTemp, Warning, TEXT("Hello:, %f,%f,%f"), End.X, End.Y, End.Z);


	// additional trace parameters
	FCollisionQueryParams TraceParams(FName(TEXT("InteractTrace")), true, NULL);
	//TraceParams.bTraceComplex = true;
	//TraceParams.bReturnPhysicalMaterial = true;
	
	float lineDuration = 10.0f;

	//Re-initialize hit info
	FHitResult HitDetails = FHitResult(ForceInit);
	//HitDetails.Distance = lineDistance;
	bool bIsHit = GetWorld()->LineTraceSingleByChannel(
		HitDetails,      // FHitResult object that will be populated with hit info
		Start,      // starting position
		End,        // end position
		ECC_Visibility,  // collision channel - 3rd custom one
		TraceParams      // additional trace settings
	);
	UWorld* WorldContext = GetWorld();
	if (!WorldContext) {
		UE_LOG(LogTemp, Warning, TEXT("NO World Context Available!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("YES World Context Available!"));
	}

	if (bIsHit) {
		DrawDebugSphere(GetWorld(), HitDetails.Location, 23, 16, FColor::Green, false, 10);
	}

	DrawDebugLine(GetWorld(), 
		Start, 
		End, 
		FColor::Orange,
		//FColor(255, 0, 0), 
		false, 
		2.0f);
		//1, 
		//10.0f);

	UE_LOG(LogTemp, Warning, TEXT("qqqqq:, %f"), TestQuantity);
	UE_LOG(LogTemp, Warning, TEXT("is hit: %s"), (bIsHit? TEXT("got hit") : TEXT("failed hit")));

	GetOverlapActorFunc();
	GetOverlapActorRadiusFunc();
}

void AAGenTestActor::GetOverlapActorFunc() {
	TArray<AActor*> Result;
	GetOverlappingActors(Result);//, AClassYouLookingFor::StaticClass()

	float NearestDistance = -1;
	UE_LOG(LogTemp, Warning, TEXT("COUNT:::: %d"), Result.Num());
	for (int i = 0; i < Result.Num(); i++) {
		FVector OriginLoc = GetActorLocation();
		FVector TargetLoc = Result[i]->GetActorLocation();
		float Distance = FVector::Dist(TargetLoc, OriginLoc);

		if (NearestDistance < 0) {
			NearestDistance = Distance;
		}
		else if (Distance < NearestDistance) {
			NearestDistance = Distance;
			UE_LOG(LogTemp, Warning, TEXT("Overwriting the nearest distance! by index:{%d}"), i);
		}
		UE_LOG(LogTemp, Warning, TEXT("%s, ----- %s ---- %f"), *Result[i]->GetName(), *Result[i]->GetActorLabel(), Distance);
	}

	UE_LOG(LogTemp, Warning, TEXT("The nearest distance is: %f"), NearestDistance);
}

void AAGenTestActor::GetOverlapActorRadiusFunc() {
	// Set what actors to seek out from it's collision channel
	TArray<TEnumAsByte<EObjectTypeQuery>> traceObjectTypes;
	traceObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Visibility));

	// Ignore any specific actors
	TArray<AActor*> ignoreActors;
	// Ignore self or remove this line to not ignore any
	ignoreActors.Init(this, 1);

	// Array of actors that are inside the radius of the sphere
	TArray<AActor*> Result;

	// Total radius of the sphere
	float radius = 750.0f;
	float displayDuration = 12;

	// Sphere's spawn loccation within the world
	FVector sphereSpawnLocation = GetActorLocation();

	DrawDebugSphere(GetWorld(), sphereSpawnLocation, radius, 16, FColor::Green, false, displayDuration);

	// Class that the sphere should hit against and include in the outActors array (Can be null)
	UClass* seekClass = AActor::StaticClass(); // NULL;

	// Class that the sphere should hit against and include in the outActors array (Can be null)
	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), sphereSpawnLocation, radius, traceObjectTypes, seekClass, ignoreActors, Result);

	float NearestDistance = -1;
	UE_LOG(LogTemp, Warning, TEXT("COUNT:::: %d"), Result.Num());
	for (int i = 0; i < Result.Num(); i++) {
		FVector OriginLoc = GetActorLocation();
		FVector TargetLoc = Result[i]->GetActorLocation();
		float Distance = FVector::Dist(TargetLoc, OriginLoc);

		if (NearestDistance < 0) {
			NearestDistance = Distance;
		}
		else if (Distance < NearestDistance) {
			NearestDistance = Distance;
			UE_LOG(LogTemp, Warning, TEXT("Overwriting the nearest distance! by index:{%d}"), i);
		}

		UE_LOG(LogTemp, Warning, TEXT("%s, ----- %s ---- %f"), *Result[i]->GetName(), *Result[i]->GetActorLabel(), Distance);
	}
	UE_LOG(LogTemp, Warning, TEXT("The nearest distance is: %f"), NearestDistance);
}

// Called every frame
void AAGenTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

