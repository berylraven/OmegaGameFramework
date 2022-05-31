using UnrealBuildTool;
using System.IO;

public class OmegaData : ModuleRules
{
	public OmegaData(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "GameplayTags", "OmegaGameFramework", "SlateCore", "UMG"});
 
		PublicIncludePaths.Add( Path.Combine(ModuleDirectory, "Public") );
		PrivateIncludePaths.Add( Path.Combine(ModuleDirectory, "Private") );
	}
}