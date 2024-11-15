// Copyright Epic Games, Inc. All Rights Reserved.

#include "BCWidgetToolsPluginBPLibrary.h"
#include "BCWidgetToolsPlugin.h"
#if WITH_EDITOR
#include "EditorViewportClient.h"
#endif

UBCWidgetToolsPluginBPLibrary::UBCWidgetToolsPluginBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UBCWidgetToolsPluginBPLibrary::BCWidgetToolsPluginSampleFunction(float Param)
{
	return -1;
}
