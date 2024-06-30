// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "P5YY/Data/ItemBase.h"
#include "ACInventoryHandling.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnInventoryUpdated);

UENUM(BlueprintType)
enum class EItemAddResult : uint8
{
	FailedToAddItem UMETA(DisplayName = "No item was added"),
	AddedPartialItem UMETA(DisplayName = "Only partial item was added"),
	AllItemAdded UMETA(DisplayName = "All items added")
};

USTRUCT(BlueprintType)
struct FItemAddResult
{
	GENERATED_BODY()

	/* Broken after upgrading from VS17 to VS22
	FItemAddResult() : ActualAmountAdded(0), ItemAddResult(EItemAddResult::FailedToAddItem), ResultMessage(FText::GetEmpty())
	{
	};*/

	UPROPERTY(BlueprintReadOnly, Category="Item add result")
	EItemAddResult ItemAddResult;
	UPROPERTY(BlueprintReadOnly, Category="Item add result")
	int32 ActualAmountAdded;
	UPROPERTY(BlueprintReadOnly, Category="Item add result")
	FText ResultMessage;
	
	static FItemAddResult AddedNone(const FText& ErrorText)
	{
		FItemAddResult AddedNoneResult;
		AddedNoneResult.ActualAmountAdded = 0;
		AddedNoneResult.ItemAddResult = EItemAddResult::FailedToAddItem;
		AddedNoneResult.ResultMessage = ErrorText;
		return  AddedNoneResult;
	};
	static FItemAddResult AddedPartial(const int32 PartialAmountAdded, const FText& ErrorText)
	{
		FItemAddResult AddedPartialResult;
		AddedPartialResult.ActualAmountAdded = PartialAmountAdded;
		AddedPartialResult.ItemAddResult = EItemAddResult::AddedPartialItem;
		AddedPartialResult.ResultMessage = ErrorText;
		return  AddedPartialResult;
	};
	static FItemAddResult AddedAll(const int32 TotalAmountAdded, const FText& Message)
	{
		FItemAddResult AddedAllResult;
		AddedAllResult.ActualAmountAdded = TotalAmountAdded;
		AddedAllResult.ItemAddResult = EItemAddResult::AllItemAdded;
		AddedAllResult.ResultMessage = Message;
		return  AddedAllResult;
	};
};

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class P5YY_API UACInventoryHandling : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UACInventoryHandling();
	void Initialize();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	
	//==============================================
	// Getters
	//==============================================
	UFUNCTION(BlueprintCallable, Category="Inventory")
	FORCEINLINE TArray<UItemBase*> GetInventoryContents() const { return  InventoryContents; }
	
	UFUNCTION(BlueprintCallable, Category="Inventory")
	FORCEINLINE float GetInventoryWeightCapacity() const { return InventoryWeightCapacity; };
	
	UFUNCTION(BlueprintCallable, Category="Inventory")
	FORCEINLINE float GetInventorySlotCapacity() const { return InventorySlotCapacity; };
	
	//==============================================
	// Setters
	//==============================================
	UFUNCTION(BlueprintCallable, Category="Inventory")
	FORCEINLINE void SetSlotsCapacity (const int32 NewSlotCapacity) { InventorySlotCapacity = NewSlotCapacity; };
	
	UFUNCTION(BlueprintCallable, Category="Inventory")
	FORCEINLINE void SetWeightCapacity (const int32 NewWeightCapacity) { InventoryWeightCapacity = NewWeightCapacity; };
	
protected:
	//==============================================
	// PROPERTIES
	//==============================================
	UPROPERTY(VisibleAnywhere, Category="Inventory")
	float InventoryCurrentWeight;
	UPROPERTY(VisibleAnywhere, Category="Inventory")
	float InventoryWeightCapacity;
	UPROPERTY(VisibleAnywhere, Category="Inventory")
	float InventorySlotCapacity;
	UPROPERTY(VisibleAnywhere, Category="Inventory")
	TArray<TObjectPtr<UItemBase>> InventoryContents;
	
public:	
	//==============================================
	// FUNCTIONS
	//==============================================
	FItemAddResult HandleAddingItem(UItemBase* Item);
	FItemAddResult HandleSingleItem(UItemBase* Item, int32 RequestedAmount);
	int32 HandleStackedItems(UItemBase* Item, int32 RequestedAmount);
	void RemoveSingleInstanceOfItem(UItemBase* Item, int32 RequestedAmount);
	void DeductItemQuantity(UItemBase* Item, int32 DesiredDeduction);
	void AddedNewItem(UItemBase* Item, int32 Quantity);
	int32 CalculateWeightToBeAdded(UItemBase* Item, int32 Quantity);
	FOnInventoryUpdated OnInventoryUpdated;
};
