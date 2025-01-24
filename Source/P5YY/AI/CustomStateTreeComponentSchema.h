// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StateTreeComponentSchema.h"
#include "CustomStateTreeComponentSchema.generated.h"

/**From Dev Gods Tutorial, Prerequisite for Modularization
 * https://www.youtube.com/watch?v=q8aOl5TIho0&t=2501s
 */

// DOESNT SHOW IN EDITOR WHEN SELECTING FROM DROP DOWN, WAIT FOR PATCH
UCLASS(BlueprintType, EditInlineNew, CollapseCategories, meta = (DisplayName = "Our State Tree Schema", CommonSchema))
class P5YY_API UCustomStateTreeComponentSchema : public UStateTreeComponentSchema
{
	GENERATED_BODY()
};
