#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TopViewCameraBase.generated.h"


UCLASS()
class P5YY_API ATopViewCameraBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATopViewCameraBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* TargetActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LerpSpeed = 10.5f;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
