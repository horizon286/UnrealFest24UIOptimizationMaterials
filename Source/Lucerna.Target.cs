// @Daniel Janák
// Virtuos Labs Prague

using UnrealBuildTool;
using System.Collections.Generic;

public class LucernaTarget : TargetRules
{
	public LucernaTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
		ExtraModuleNames.Add("Lucerna");
	}
}
