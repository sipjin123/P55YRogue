#pragma once
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
};
