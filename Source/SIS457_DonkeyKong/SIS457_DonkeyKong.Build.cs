// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SIS457_DonkeyKong : ModuleRules
{
	public SIS457_DonkeyKong(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
