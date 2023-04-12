// Fill out your copyright notice in the Description page of Project Settings.


#include "AGenTestActor.h"
#include "Components/BoxComponent.h"
#include "Engine/StaticMesh.h"
#include "UObject/Object.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "TimerManager.h"

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

	// The length of the raycast
	float LineTraceDistance = 200.f;

	// Get the camera view
	FVector CameraLoc = StatMeshSourceBackup->GetComponentLocation();
	FRotator CameraRot = StatMeshSourceBackup->GetComponentRotation();
	FVector Start = CameraLoc;
	FVector End = CameraLoc + (CameraRot.Vector() * LineTraceDistance);

	// additional trace parameters
	FCollisionQueryParams TraceParams(FName(TEXT("InteractTrace")), true, NULL);
	TraceParams.bTraceComplex = true;
	TraceParams.bReturnPhysicalMaterial = true;

	//Re-initialize hit info
	FHitResult HitDetails = FHitResult(ForceInit);
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
	} else {
		UE_LOG(LogTemp, Warning, TEXT("YES World Context Available!"));
	}

	float DrawRadius = 24.0f;
	float LineDuration = 10.0f;
	if (bIsHit) {
		DrawDebugSphere(GetWorld(), HitDetails.Location, DrawRadius, 16, FColor::Green, false, LineDuration);
	}

	float LifeTime = 5.0f;
	DrawDebugLine(GetWorld(), Start, End, FColor::Orange, false, LifeTime);

	UE_LOG(LogTemp, Warning, TEXT("TestQuantityF: %f"), TestQuantity);
	UE_LOG(LogTemp, Warning, TEXT("is hit: %s"), (bIsHit? TEXT("got hit") : TEXT("failed hit")));

	GetOverlapActorFunc();
	GetOverlapActorRadiusFunc();
}

void AAGenTestActor::GetOverlapActorFunc() {
	TArray<AActor*> Result;
	GetOverlappingActors(Result);//, AClassYouLookingFor::StaticClass()

	float NearestDistance = -1;
	UE_LOG(LogTemp, Warning, TEXT("Total Overlap Component -> %d"), Result.Num());
	for (int i = 0; i < Result.Num(); i++) {
		FVector OriginLoc = GetActorLocation();
		FVector TargetLoc = Result[i]->GetActorLocation();
		float Distance = FVector::Dist(TargetLoc, OriginLoc);

		if (NearestDistance < 0) {
			NearestDistance = Distance;
		}
		else if (Distance < NearestDistance) {
			NearestDistance = Distance;
			UE_LOG(LogTemp, Warning, TEXT("Overwriting the nearest distance by index:{%d}"), i);
		}
		UE_LOG(LogTemp, Warning, TEXT("%s --> %f"), *Result[i]->GetActorLabel(), Distance);
	}

	UE_LOG(LogTemp, Warning, TEXT("The nearest distance is: %f"), NearestDistance);
}

void AAGenTestActor::GetOverlapActorRadiusFunc() {
	// Set what actors to seek out from it's collision channel
	TArray<TEnumAsByte<EObjectTypeQuery>> traceObjectTypes;
	traceObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Visibility));

	// Ignore any specific actors
	TArray<AActor*> IgnoreActors;
	// Ignore self or remove this line to not ignore any
	IgnoreActors.Init(this, 1);

	// Array of actors that are inside the radius of the sphere
	TArray<AActor*> Result;

	// Total radius of the sphere
	float Radius = 750.0f;
	float DisplayDuration = 12;

	// Sphere's spawn loccation within the world
	FVector sphereSpawnLocation = GetActorLocation();

	DrawDebugSphere(GetWorld(), sphereSpawnLocation, Radius, 16, FColor::Green, false, DisplayDuration);

	// Class that the sphere should hit against and include in the outActors array (Can be null)
	UClass* seekClass = AActor::StaticClass(); // NULL;

	// Class that the sphere should hit against and include in the outActors array (Can be null)
	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), sphereSpawnLocation, Radius, traceObjectTypes, seekClass, IgnoreActors, Result);

	float NearestDistance = -1;
	UE_LOG(LogTemp, Warning, TEXT("Total Overlap --> %d"), Result.Num());
	for (int i = 0; i < Result.Num(); i++) {
		FVector OriginLoc = GetActorLocation();
		FVector TargetLoc = Result[i]->GetActorLocation();
		float Distance = FVector::Dist(TargetLoc, OriginLoc);

		if (NearestDistance < 0) {
			NearestDistance = Distance;
		}
		else if (Distance < NearestDistance) {
			NearestDistance = Distance;
			UE_LOG(LogTemp, Warning, TEXT("Overwriting the nearest distance by index:{%d}"), i);
		}

		UE_LOG(LogTemp, Warning, TEXT("%s --> %f"), *Result[i]->GetActorLabel(), Distance);
	}
	UE_LOG(LogTemp, Warning, TEXT("The nearest distance is: %f"), NearestDistance);
}

void AAGenTestActor::TriggerTimerDelayTest() {
	int32 ParameterToPass = 100; // You can use any supported variable type

	FTimerHandle TimerHandle;
	UE_LOG(LogTemp, Warning, TEXT("Method timer has Started"));
	FTimerDelegate TimerDelegate = FTimerDelegate::CreateUObject(this, &AAGenTestActor::MethodWithDelay, ParameterToPass);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, 3, false);
}

void AAGenTestActor::MethodWithDelay(int32 TestInt) {
	DamageTickToTake = 100;
	UE_LOG(LogTemp, Warning, TEXT("Method timer is finished: %d"), TestInt);
}

void AAGenTestActor::TickDamageFunc (float DamagePerTick)
{
	float DamagePerSec = 1;
	DamageTickToTake -= DamagePerSec * DamagePerTick;
	if (int32(PreviousDamageTick) != int32(DamageTickToTake)) {
		//UE_LOG(LogTemp, Warning, TEXT("Tick: %d"), int32(DamageTickToTake));
		PreviousDamageTick = DamageTickToTake;
	}
}

// Called every frame
void AAGenTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (DebugObj && DamageTickToTake > 0) {
		TickDamageFunc(DeltaTime);
	}
}

