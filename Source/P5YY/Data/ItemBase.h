#pragma once
#include "ItemData.h"
#include "ItemBase.generated.h"

UCLASS()
class UItemBase : public  UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, Category="Item Data")
	int32 Id;
	UPROPERTY(VisibleAnywhere, Category="Item Data", meta=(UIMin=1, UIMax=100))
	int32 Quantity;
	
	UPROPERTY(EditAnywhere, Category="Item Data")
	EItemRarity ItemRarity;
	UPROPERTY(VisibleAnywhere, Category="Item Data")
	FItemTextData ItemTextData;
	UPROPERTY(EditAnywhere, Category="Item Data")
	EItemType ItemType;
	UPROPERTY(VisibleAnywhere, Category="Item Data")
	FItemStats ItemStats;
	UPROPERTY(VisibleAnywhere, Category="Item Data")
	FItemAssetData ItemAssetData;
	UPROPERTY(VisibleAnywhere, Category="Item Data")
	FItemStorageInfo ItemStorageInfo;
	
public:
	UItemBase();
	UItemBase* CreateItemCopy() const;

	FORCEINLINE float GetItemStackWeight() const { return Quantity * ItemStorageInfo.Weight; };
	FORCEINLINE float GetItemSingleWeight() const { return ItemStorageInfo.Weight; };
	FORCEINLINE bool IsFullStack() const { return ItemStorageInfo.MaxStackSize == Quantity; };

	void SetQuanity(int32 NewQuantity);
};
