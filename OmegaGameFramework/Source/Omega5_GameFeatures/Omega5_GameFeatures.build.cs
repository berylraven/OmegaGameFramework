using UnrealBuildTool;
using System.IO;

public class Omega5_GameFeatures : ModuleRules
{
	public Omega5_GameFeatures(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine",
			"InputCore",
			"EnhancedInput",
			"GameplayTags",
			"GameplayTasks",
			"GameFeatures",
			"ModularGameplay"
		});
 
		PublicIncludePaths.Add( Path.Combine(ModuleDirectory, "Public") );
		PrivateIncludePaths.Add( Path.Combine(ModuleDirectory, "Private") );
	}
}