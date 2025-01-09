// Copyright Motorica AB. All Rights Reserved.

using UnrealBuildTool;

public class MoEditor : ModuleRules
{
	public MoEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		bUsePrecompiled = true;

		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);


		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"MoRuntime",
				"AssetRegistry",
				"EditorSubsystem",
				"Settings",
				"DeveloperSettings",
				"Slate",
				"SlateCore",
				"EditorStyle",
				"Blutility",
				"UMG",
				"Kismet",
				"AnimGraph",
				"Persona",
				"WorkspaceMenuStructure",
				"ToolMenus",
				"Projects",
				"UnrealEd",
				"LevelEditor",
				"LevelSequence",
				"MovieScene",
				"MovieSceneTracks",
				"Sequencer",
				"PropertyEditor",
				"HTTP",
				"Json",
				"JsonUtilities",
				"EditorFramework", // FEditorModeInfo
				"InteractiveToolsFramework",
				"EditorInteractiveToolsFramework",
				"SceneOutliner",
				"InputCore", // Input keys such has EKeys::Escape
				"MoHttp",
				"OnlineServicesInterface",
				"OnlineServicesCommon"
				// ... add private dependencies that you statically link with here ...
			}
			);


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
