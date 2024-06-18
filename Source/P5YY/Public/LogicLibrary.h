#pragma once
#include "LogicLibrary.generated.h"

USTRUCT()
struct FMyInterpStruct
{
	GENERATED_BODY()

	UPROPERTY()
	float Brightness;

	UPROPERTY()
	float BrightnessGoal; //interping to

	UPROPERTY()
	FVector Location;

	UPROPERTY()
	FVector LocationGoal;

	UPROPERTY()
	float Alpha;

	void InterpInternal()
	{
		Location = FMath::Lerp<FVector>(Location,LocationGoal,Alpha);
		Brightness = FMath::Lerp<float>(Brightness,BrightnessGoal,Alpha);
	}

	//Brightness out is returned, FVector is returned by reference 
	float Interp(const float& NewAlpha, FVector& Out)
	{ 
		// value received from rest of your game engine
		Alpha = NewAlpha;

		//Internal data structure management
		InterpInternal();

		//Return Values
		Out = Location;
		return Brightness;
	}

	FMyInterpStruct()
	{
		Brightness = 2;
		BrightnessGoal = 100;
		Alpha = 0;
		Location = FVector::ZeroVector;
		LocationGoal = FVector(0,0,200000);
	} 
};

USTRUCT()
struct FVRect
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY()
	FVector2D Min;
	
	UPROPERTY()
	FVector2D Max;
	
	//overloaded constructor
	FVRect(const FVector2D& VPoint1, const FVector2D& VPoint2)
	{
		//drag topleft to bottom right
		if(VPoint1.X < VPoint2.X &&
			VPoint1.Y < VPoint2.Y
		){
			Min 	= VPoint1;
			Max 	= VPoint2;
		}
		
		//drag from bottom right to top left
		else if(VPoint1.X > VPoint2.X &&
			VPoint1.Y > VPoint2.Y
		){
			Min 	= VPoint2;
			Max 	= VPoint1;
		}
		
		//drag from bottom left to top right
		else if(VPoint1.X < VPoint2.X &&
			VPoint1.Y > VPoint2.Y
		){
			Min 	= FVector2D(VPoint1.X, VPoint2.Y);
			Max 	= FVector2D(VPoint2.X, VPoint1.Y);
		}
		
		//etc...
	}
	
	//base constructor
	FVRect()
	{
		Min = FVector2D(0,0);
		Max = FVector2D(500,500);
	}
};

USTRUCT()
struct FQuadVRect
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY()
	FVRect Rects[4];

	//base constructor
	FQuadVRect()
	{
	}
};