// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

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
			"UnrealEd"
		});
		
		PrivateDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "GameplayTags", "GameplayTasks" });
	}
}
