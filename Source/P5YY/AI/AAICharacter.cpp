// Fill out your copyright notice in the Description page of Project Settings.


#include "AAICharacter.h"
#include "AbilitySystemComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AAAICharacter::AAAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

// Called when the game starts or when spawned
void AAAICharacter::BeginPlay()
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
void AAAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (IsLockingOnTarget)
	{
		LockOnTargetTick(DeltaTime);
	}
}

// Called to bind functionality to input
void AAAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAAICharacter::LockOnTargetTick(float DeltaTime)
{
	FRotator NewRotation = UKismetMathLibrary::FindLookAtRotation(
		GetActorLocation(), TargetLocation);
	NewRotation = FRotator(0.f, NewRotation.Yaw,0.f);
	
	SetActorRotation(FMath::RInterpTo(
		GetActorRotation(), NewRotation, DeltaTime, LockRotationSpeed));
}

void AAAICharacter::SetLockTarget(bool IsLocked, FVector NewTargetLocation)
{
	IsLockingOnTarget = IsLocked;
	TargetLocation = NewTargetLocation;
}

