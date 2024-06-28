// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RaccoonGameJam/RaccoonGameJamGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRaccoonGameJamGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
RACCOONGAMEJAM_API UClass* Z_Construct_UClass_ARaccoonGameJamGameMode();
RACCOONGAMEJAM_API UClass* Z_Construct_UClass_ARaccoonGameJamGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_RaccoonGameJam();
// End Cross Module References

// Begin Class ARaccoonGameJamGameMode
void ARaccoonGameJamGameMode::StaticRegisterNativesARaccoonGameJamGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARaccoonGameJamGameMode);
UClass* Z_Construct_UClass_ARaccoonGameJamGameMode_NoRegister()
{
	return ARaccoonGameJamGameMode::StaticClass();
}
struct Z_Construct_UClass_ARaccoonGameJamGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "RaccoonGameJamGameMode.h" },
		{ "ModuleRelativePath", "RaccoonGameJamGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARaccoonGameJamGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ARaccoonGameJamGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_RaccoonGameJam,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARaccoonGameJamGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ARaccoonGameJamGameMode_Statics::ClassParams = {
	&ARaccoonGameJamGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARaccoonGameJamGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ARaccoonGameJamGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ARaccoonGameJamGameMode()
{
	if (!Z_Registration_Info_UClass_ARaccoonGameJamGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARaccoonGameJamGameMode.OuterSingleton, Z_Construct_UClass_ARaccoonGameJamGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ARaccoonGameJamGameMode.OuterSingleton;
}
template<> RACCOONGAMEJAM_API UClass* StaticClass<ARaccoonGameJamGameMode>()
{
	return ARaccoonGameJamGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ARaccoonGameJamGameMode);
ARaccoonGameJamGameMode::~ARaccoonGameJamGameMode() {}
// End Class ARaccoonGameJamGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_bites_Desktop_Unreal_Projects_RaccoonGameJam_RaccoonGameJam_Source_RaccoonGameJam_RaccoonGameJamGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ARaccoonGameJamGameMode, ARaccoonGameJamGameMode::StaticClass, TEXT("ARaccoonGameJamGameMode"), &Z_Registration_Info_UClass_ARaccoonGameJamGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARaccoonGameJamGameMode), 3103637584U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_bites_Desktop_Unreal_Projects_RaccoonGameJam_RaccoonGameJam_Source_RaccoonGameJam_RaccoonGameJamGameMode_h_1466687972(TEXT("/Script/RaccoonGameJam"),
	Z_CompiledInDeferFile_FID_Users_bites_Desktop_Unreal_Projects_RaccoonGameJam_RaccoonGameJam_Source_RaccoonGameJam_RaccoonGameJamGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_bites_Desktop_Unreal_Projects_RaccoonGameJam_RaccoonGameJam_Source_RaccoonGameJam_RaccoonGameJamGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
