// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "AbilitySystemInterface.h"

#include "P5YY/AProjectile.h"
#include "P5YY/ACEquipmentHandling.h"
#include "P5YY/UIWidgets/PlayerStatWidget.h"

#include "ProtagonistChar.generated.h"

UCLASS()
class P5YY_API AProtagonistChar : public ACharacter, public  IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AProtagonistChar();

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputAction* LookAction;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* StatMeshSource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawnable")
		TSubclassOf<AAProjectile> CustomProjectile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
		class UACEquipmentHandling* EquipmentHandling;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
		class UACMobilityHandling* MobilityHandling;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UPlayerStatWidget> PlayerHUDClass;

	UPROPERTY()
		UPlayerStatWidget* PlayerHUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector ProjectileSpawnPt;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ProjectileOffset = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 TestID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* TargetActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* TargetMobilityNode;
	
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite)
		FVector TargetMobilityLocation;
	
	UFUNCTION(BlueprintCallable, Category = "Group1")
		void LockTarget();

	UFUNCTION(BlueprintCallable, Category = "Group1")
		void AssignLockTarget(AActor* NewTargetActor);

	UFUNCTION(BlueprintCallable, Category = "Group1")
		void UpdateEquipmentHandling();
	
protected:
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="NetworkCombat")
	void Server_SpawnProjectile(FVector newSpawnPt);
	bool Server_SpawnProjectile_Validate(FVector newSpawnPt);
	void Server_SpawnProjectile_Implementation(FVector newSpawnPt);
	
	UFUNCTION(BlueprintCallable, Category = "Group1")
	void SpawnProjectileAt(FVector newSpawnPt);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GAS", meta = (AllowPrivateAccess="true"))
	class UAbilitySystemComponent* AbilitySystemComponent;

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return  AbilitySystemComponent;
	}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GAS", meta = (AllowPrivateAccess="true"))
	const class UBaseAttributeSet* BaseAttributeSet;

public:
	// Allows calling teleport event across c++ and BP
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "NetworkCombat")
	void NetTeleport (FVector newLoc);
	virtual void NetTeleport_Implementation(FVector newLoc);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
