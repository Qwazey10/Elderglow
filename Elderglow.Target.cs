// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ElderglowTarget : TargetRules
{
	public ElderglowTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;
		ExtraModuleNames.Add("Elderglow");

		
		ExtraModuleNames.AddRange(
			new string[]
			{
				"Elderglow",
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"GameplayAbilities",
				"GameplayTasks",
				"ImGui"
			});
	}
}

