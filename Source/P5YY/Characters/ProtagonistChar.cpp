// Fill out your copyright notice in the Description page of Project Settings.


#include "ProtagonistChar.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Engine/StaticMesh.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

#include "P5YY/ACEquipmentHandling.h"
#include "P5YY/ACMobilityHandling.h"
#include "P5YY/UIWidgets/PlayerStatWidget.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.h"
#include "Components/SphereComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AProtagonistChar::AProtagonistChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Configure character movement
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
}

// Called when the game starts or when spawned
void AProtagonistChar::BeginPlay()
{
	Super::BeginPlay();
	if (GetOwner())
	{
		MobilityHandling = GetOwner()->FindComponentByClass<UACMobilityHandling>();
	}
	
	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		check(PlayerController);
		PlayerHUD = CreateWidget<UPlayerStatWidget>(PlayerController, PlayerHUDClass);
		check(PlayerHUD);
		PlayerHUD->AddToPlayerScreen();
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	if (IsValid(AbilitySystemComponent))
	{
		BaseAttributeSet = AbilitySystemComponent->GetSet<UBaseAttributeSet>();
        AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UBaseAttributeSet::GetManaAttribute()).AddUObject(this, &AProtagonistChar::OnManaUpdated);
        AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UBaseAttributeSet::GetHealthAttribute()).AddUObject(this, &AProtagonistChar::OnHealthUpdated);
	}
}

void AProtagonistChar::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (PlayerHUD) {
		PlayerHUD->RemoveFromParent();
		PlayerHUD = nullptr;
	}
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void AProtagonistChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Input
void AProtagonistChar::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {

		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AProtagonistChar::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AProtagonistChar::Look);
	}
}

void AProtagonistChar::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AProtagonistChar::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

bool AProtagonistChar::Server_SpawnProjectile_Validate(FVector newSpawnPt)
{
	return true;
}

void AProtagonistChar::Server_SpawnProjectile_Implementation(FVector newSpawnPt)
{
	SpawnProjectileAt(newSpawnPt);
}

void AProtagonistChar::SpawnProjectileAt(FVector newSpawnPt) {
	ProjectileSpawnPt = newSpawnPt;
	if (CustomProjectile) {
		// Spawns the projectile new instance
		AAProjectile* NewProjectile = GetWorld()->SpawnActor<AAProjectile>(CustomProjectile);
		NewProjectile->SetOwner(this);

		// Initialize new projectile parameters
		FVector newDir = GetActorForwardVector() * ProjectileOffset;
		FRotator newRot = GetActorRotation();
		FVector newLoc = ProjectileSpawnPt;
		NewProjectile->InitializeProjectile(newDir, newLoc, newRot);

		// Assign target node to allow player to use mobility on node
		TargetMobilityNode = NewProjectile;
		TargetMobilityLocation = NewProjectile->GetActorLocation();
		MobilityHandling->RegisterTargetActor(NewProjectile);
	}
}

void AProtagonistChar::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AProtagonistChar, TargetMobilityLocation)
}

void AProtagonistChar::UpdateEquipmentHandling() {
	// Trigger Actor Component for equipment handling
	if (EquipmentHandling == NULL) {
		UACEquipmentHandling* newHandler = AActor::FindComponentByClass<UACEquipmentHandling>();
		if (newHandler) {
			EquipmentHandling = newHandler;
			EquipmentHandling->InitializeComponent();
		}
	}
	else {
		EquipmentHandling->InitializeComponent();
	}
}

void AProtagonistChar::LockTarget() {
	// Snap player rotation to lock on target
	APlayerController* ControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (TargetActor != NULL) {
		UE_LOG(LogTemp, Warning, TEXT("Lock Target Success: {%s}"), TargetActor);
		FRotator NewRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), TargetActor->GetActorLocation());
		ControllerRef->SetControlRotation(NewRotation);
	} else {
		UE_LOG(LogTemp, Warning, TEXT("Lock Target Success"));
	}
}

void AProtagonistChar::NetTeleport_Implementation(FVector newLoc)
{
	UE_LOG(LogTemp, Warning, TEXT("ShouldTeleport"));
}

void AProtagonistChar::AssignLockTarget(AActor* NewTargetActor)
{
	// Assign target actor to lock on
#if WITH_EDITOR
	UE_LOG(LogTemp, Warning, TEXT("Registered New Target to Protagonist: %s"), *NewTargetActor->GetActorLabel());
#endif
	TargetActor = NewTargetActor;
}

void AProtagonistChar::OnManaUpdated(const FOnAttributeChangeData& Data) const
{
	// Fire the callback. Data contains more than NewValue, in case it is needed.
	OnManaChange.Broadcast(Data.NewValue);
}

void AProtagonistChar::OnHealthUpdated(const FOnAttributeChangeData& Data) const
{
	// Fire the callback. Data contains more than NewValue, in case it is needed.
	OnHealthChange.Broadcast(Data.NewValue);
}
