// Fill out your copyright notice in the Description page of Project Settings.


#include "AAvatarPawn.h"
#include "AbilitySystemComponent.h"

// Sets default values
AAAvatarPawn::AAAvatarPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

// Called when the game starts or when spawned
void AAAvatarPawn::BeginPlay()
{
	Super::BeginPlay();
	
	if (IsValid(AbilitySystemComponent))
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Base Attribute Success"));
		BaseAttributeSet = AbilitySystemComponent->GetSet<UBaseAttributeSet>();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Base Attribute Fail"));
	}
}

// Called every frame
void AAAvatarPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAAvatarPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

