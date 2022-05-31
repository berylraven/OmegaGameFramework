using UnrealBuildTool;
using System.IO;

public class OmegaFlow : ModuleRules
{
	public OmegaFlow(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "GameplayTags", "OmegaGameFramework"});
 
		PublicIncludePaths.Add( Path.Combine(ModuleDirectory, "Public") );
		PrivateIncludePaths.Add( Path.Combine(ModuleDirectory, "Private") );
	}
}