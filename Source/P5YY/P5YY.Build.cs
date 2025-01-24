// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class P5YY : ModuleRules
{
	public P5YY(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"HeadMountedDisplay", 
			"EnhancedInput", 
			"AIModule", 
			"UMG", 
			"NavigationSystem",
			"GameplayStateTreeModule",
			"StateTreeModule"
		});

        if (Target.bBuildEditor)
        {
            PublicDependencyModuleNames.AddRange(new string[] 
			{ 
				"UnrealEd",
				"Blutility",
			});
        }
        PrivateDependencyModuleNames.AddRange(new string[] 
		{ 
			"GameplayAbilities", 
			"GameplayTags", 
			"GameplayTasks" 
		});
        //PrivateIncludePaths.Add(Path.Combine(EngineDirectory, "Source/Editor"));
        //PrivateIncludePaths.AddRange(new string[] { System.IO.Path.GetFullPath(Target.RelativeEnginePath) + "Source/Editor/Blutility/Private" });
        PrivateIncludePaths.AddRange(new string[] { System.IO.Path.GetFullPath(Target.RelativeEnginePath) + "Source/Editor" });
    }
}
