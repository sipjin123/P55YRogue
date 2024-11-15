// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class P5YYEditorTarget : TargetRules
{
	public P5YYEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
        //BuildEnvironment = TargetBuildEnvironment.Unique;
        DefaultBuildSettings = BuildSettingsVersion.V4;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
        //IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
		ExtraModuleNames.Add("P5YY");
	}
}
