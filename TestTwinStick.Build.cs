// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TestTwinStick : ModuleRules
{
	public TestTwinStick(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "UMG", "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
