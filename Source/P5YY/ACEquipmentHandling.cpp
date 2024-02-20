// Fill out your copyright notice in the Description page of Project Settings.


#include "ACEquipmentHandling.h"

// Sets default values for this component's properties
UACEquipmentHandling::UACEquipmentHandling()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UACEquipmentHandling::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UACEquipmentHandling::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UACEquipmentHandling::InitializeComponent() {
	UE_LOG(LogTemp, Warning, TEXT("Initializing EquipmentComponent"));
}
