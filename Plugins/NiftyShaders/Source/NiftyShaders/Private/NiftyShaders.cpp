// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "NiftyShaders.h"

#define LOCTEXT_NAMESPACE "FNiftyShadersModule"

void FNiftyShadersModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FNiftyShadersModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FNiftyShadersModule, NiftyShaders)