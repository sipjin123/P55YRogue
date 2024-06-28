#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "BMathLibraryLinker.generated.h"


UCLASS()
class P5YY_API UBMathLibraryLinker : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "My DLL Library")
	static bool importDLL( FString folder, FString name);

	UFUNCTION(BlueprintCallable, Category = "My DLL Library")
	static bool importMethodGetInvertedBool( );

	UFUNCTION(BlueprintCallable, Category = "My DLL Library")
	static bool importMethodGetIntPlusPlus( );

	UFUNCTION(BlueprintCallable, Category = "My DLL Library")
	static bool importMethodGetCircleArea( );

	UFUNCTION( BlueprintCallable, Category = "My DLL Library" )
	static bool importMethodGetVector4( );

	
	UFUNCTION( BlueprintCallable, Category = "My DLL Library" )
	static bool importMethodinitCustomVoid();
	UFUNCTION( BlueprintCallable, Category = "My DLL Library" )
	static bool importMethodsetCustomVoid();
	UFUNCTION( BlueprintCallable, Category = "My DLL Library" )
	static bool importMethodgetCustomVoid();
	UFUNCTION( BlueprintCallable, Category = "My DLL Library" )
	static bool importMethodgetCustomVoidAdditive();

	
	UFUNCTION( BlueprintCallable, Category = "My DLL Library" )
	static bool importMethodfibonacci_init();
	UFUNCTION( BlueprintCallable, Category = "My DLL Library" )
	static bool importMethodfibonacci_next();
	UFUNCTION( BlueprintCallable, Category = "My DLL Library" )
	static bool importMethodfibonacci_current();
	
	
	UFUNCTION(BlueprintCallable, Category = "My DLL Library")
	static bool getInvertedBoolFromDll(bool boolState);

	UFUNCTION(BlueprintCallable, Category = "My DLL Library")
	static int getIntPlusPlusFromDll(int lastInt);

	UFUNCTION(BlueprintCallable, Category = "My DLL Library")
	static float getCircleAreaFromDll(float radius);

	UFUNCTION(BlueprintCallable, Category = "My DLL Library")
	static FString getCharArrayFromDll(FString parameterText);

	UFUNCTION( BlueprintCallable, Category = "My DLL Library" )
	static FVector4 getVector4FromDll( FVector4 vector4 );

	UFUNCTION(BlueprintCallable, Category = "My DLL Library")
	static void freeDLL();

	
	UFUNCTION(BlueprintCallable, Category = "My DLL Library")
	static int initCustomVoidFromDll();
	UFUNCTION(BlueprintCallable, Category = "My DLL Library")
	static void setCustomVoidFromDll(int addVal);
	UFUNCTION(BlueprintCallable, Category = "My DLL Library")
	static int getCustomVoidFromDll();
	UFUNCTION(BlueprintCallable, Category = "My DLL Library")
	static int getCustomVoidAdditiveFromDll(int addVal);
	
	UFUNCTION(BlueprintCallable, Category = "My DLL Library")
	static void fibonacci_initFromDll(int a, int b);
	UFUNCTION(BlueprintCallable, Category = "My DLL Library")
	static bool fibonacci_nextFromDll();
	UFUNCTION( BlueprintCallable, Category = "My DLL Library" )
	static int getfibonacci_currentFromDLL();
};