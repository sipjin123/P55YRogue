// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class P5YYTarget : TargetRules
{
	public P5YYTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
        //BuildEnvironment = TargetBuildEnvironment.Unique;
        DefaultBuildSettings = BuildSettingsVersion.V4;
        //DefaultBuildSettings = BuildSettingsVersion.V2;
        //IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
        ExtraModuleNames.Add("P5YY");
	}
}
