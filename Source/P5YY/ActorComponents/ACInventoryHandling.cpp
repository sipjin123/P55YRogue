// Fill out your copyright notice in the Description page of Project Settings.


#include "ACInventoryHandling.h"

// Sets default values for this component's properties
UACInventoryHandling::UACInventoryHandling()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UACInventoryHandling::Initialize()
{
	UE_LOG(LogTemp, Warning, TEXT("Initialized Inventory Handling"));
}


// Called when the game starts
void UACInventoryHandling::BeginPlay()
{
	Super::BeginPlay();
	// ...
	
}

// Called every frame
void UACInventoryHandling::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FItemAddResult UACInventoryHandling::HandleAddingItem(UItemBase* Item)
{
	if(GetOwner())
	{
		const int32 InitialRequestedAmount = Item->Quantity;
		if (!Item->ItemStorageInfo.IsStackable)
		{
			return HandleSingleItem(Item, 1);
		}
		
		const int32 StackableAmountAdded = HandleStackedItems(Item, InitialRequestedAmount);
		if (StackableAmountAdded == InitialRequestedAmount)
		{
			// Full
		}
		
		if (StackableAmountAdded < InitialRequestedAmount && StackableAmountAdded > 0)
		{
			// Partial			
		}

		if (StackableAmountAdded <= 0)
		{
			// Fail
		}
	}

	return FItemAddResult::AddedNone(FText::Format(
			FText::FromString("Could not add {0} to inventory. UNKNOWN"), Item->ItemTextData.Name));
}

FItemAddResult UACInventoryHandling::HandleSingleItem(UItemBase* Item, int RequestedAmount)
{
	if (FMath::IsNearlyZero(Item->GetItemStackWeight()) || Item->GetItemSingleWeight() < 0)
	{
		return FItemAddResult::AddedNone(FText::Format(
			FText::FromString("Could not add {0} to inventory. Item weight is invalid"), Item->ItemTextData.Name));
	}

	if (InventoryCurrentWeight + Item->GetItemSingleWeight() > GetInventoryWeightCapacity())
	{
		float weightExceeded = GetInventoryWeightCapacity() - (InventoryCurrentWeight + Item->GetItemSingleWeight());
		return FItemAddResult::AddedNone(FText::Format(
			FText::FromString("Could not add {0} to inventory. Exceed weight capacity by {1}"), Item->ItemTextData.Name, weightExceeded));
	}

	if (InventoryContents.Num() + 1 > InventorySlotCapacity)
	{
		return FItemAddResult::AddedNone(FText::Format(
			FText::FromString("Could not add {0} to inventory. Exceed slot capacity"), Item->ItemTextData.Name));
	}

	AddedNewItem(Item, RequestedAmount);
	return FItemAddResult::AddedAll(RequestedAmount, FText::Format(
	FText::FromString("Successfully added {0} pcs of {1} to inventory."), RequestedAmount, Item->ItemTextData.Name));
}

int32 UACInventoryHandling::HandleStackedItems(UItemBase* Item, int32 RequestedAmount)
{
	return 0;
}

void UACInventoryHandling::RemoveSingleInstanceOfItem(UItemBase* Item, int32 RequestedAmount)
{
}

void UACInventoryHandling::DeductItemQuantity(UItemBase* Item, int32 DesiredDeduction)
{
}

void UACInventoryHandling::AddedNewItem(UItemBase* Item, int32 Quantity)
{
	UItemBase* NewItem;
	if (Item->IsCopy || Item->IsPickup)
	{
		NewItem = Item;
		NewItem->ResetFlags();
	}
	else
	{
		NewItem = Item->CreateItemCopy();
	}
	
	NewItem->OwningInventory = this;
	NewItem->SetQuanity(Quantity);
	
	InventoryContents.Add(NewItem);
	InventoryCurrentWeight += NewItem->GetItemStackWeight();
	
	OnInventoryUpdated.Broadcast();
}

int32 UACInventoryHandling::CalculateWeightToBeAdded(UItemBase* Item, int32 Quantity)
{
	return 0;
}

