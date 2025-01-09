// Copyright Motorica AB. All Rights Reserved.

using System;
using UnrealBuildTool;

public class MoHttp : ModuleRules
{
	public MoHttp(ReadOnlyTargetRules Target) : base(Target)
	{
		AddEnvDefinitionText("MOSTUDIO_CLIENT_ID_DEV", "MOSTUDIO_CLIENT_ID_DEV");
		AddEnvDefinitionText("MOSTUDIO_CLIENT_ID_STAGING", "MOSTUDIO_CLIENT_ID_STAGING");
		AddEnvDefinitionText("MOSTUDIO_CLIENT_ID_PROD", "MOSTUDIO_CLIENT_ID_PROD");

		// Set during build time
		var EnvVarBuildDev = System.Environment.GetEnvironmentVariable("MOSTUDIO_BUILD_DEV");
		var IsBeingBuilt = !String.IsNullOrEmpty(EnvVarBuildDev);

		// Set this during development
		// Loses precedence if "MOSTUDIO_BUILD" is present
		var EnableDevelopmentMode = true;

		// Determine if we run "development" or "production" build of our UE plugin
		// Not to be confused with the project's DebugGame, Development, etc. build
		// configurations - these do not correspond to the plugin builds we make.
		var DevelopmentMode = 0;
		if (IsBeingBuilt)
		{
			DevelopmentMode = EnvVarBuildDev == "1" ? 1 : 0;
		}
		else
		{
			DevelopmentMode = EnableDevelopmentMode ? 1 : 0;
		}

		PublicDefinitions.Add($"MOSTUDIO_DEVELOPMENT={DevelopmentMode}");
		Console.WriteLine($"[MOSTUDIO] - Setting \"MOSTUDIO_DEVELOPMENT\" to {DevelopmentMode}.");

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
				"DeveloperSettings",
				"HTTP",
				"HTTPServer",
				"Json",
				"JsonUtilities",
				"WebBrowser",
				"Slate",
				"SlateCore",
				"OnlineServicesInterface",
				"OnlineServicesCommon",
				"CoreOnline",
				"Projects"
			}
			);

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}

	private void AddEnvDefinition(string EnvName)
	{
		var Value = System.Environment.GetEnvironmentVariable(EnvName);
		if (!String.IsNullOrEmpty(Value))
		{
			PrivateDefinitions.Add($"{EnvName}=1");
		}
	}

	private void AddEnvDefinitionText(string EnvName, string DefName)
	{
		var Value = System.Environment.GetEnvironmentVariable(EnvName);
		if (!String.IsNullOrEmpty(Value) && !String.IsNullOrEmpty(Value.Trim()))
		{
			PrivateDefinitions.Add($"{DefName}=TEXT(\"{Value}\")");
		}
	}

	private void AddEnvDefinitionByLookup(string EnvName, string EnvValue, string DefName)
	{
		var Value = System.Environment.GetEnvironmentVariable(EnvName);
		if (!String.IsNullOrEmpty(Value) && Value.Trim().Equals(EnvValue, StringComparison.OrdinalIgnoreCase))
		{
			PublicDefinitions.Add($"{DefName}=1");
		}
		else
		{
			PublicDefinitions.Add($"{DefName}=0");
		}
	}
}
