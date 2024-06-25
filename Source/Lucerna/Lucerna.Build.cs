// @Daniel Janák
// Virtuos Labs Prague

using UnrealBuildTool;

public class Lucerna : ModuleRules
{
	public Lucerna(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput",
			"CommonUI",
			"Slate",
			"SlateCore",
			"UMG"
		});
		
		PrivateIncludePaths.AddRange(new string[] 
		{
			"Lucerna/Public",
			"Lucerna/Public/Grid",
			"Lucerna/Public/Map",
			"Lucerna/Public/Hud",
			"Lucerna/Public/Custom",
		}); 
	}
}
