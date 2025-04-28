using UnrealBuildTool;

public class Puerts_Demo : ModuleRules
{
	public Puerts_Demo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
        
		PrivateDependencyModuleNames.AddRange(new string[] { "JsEnv", "Puerts" });
	}
}
