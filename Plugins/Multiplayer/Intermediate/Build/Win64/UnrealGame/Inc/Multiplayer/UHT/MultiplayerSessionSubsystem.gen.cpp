// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Multiplayer/Public/MultiplayerSessionSubsystem.h"
#include "Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMultiplayerSessionSubsystem() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
MULTIPLAYER_API UClass* Z_Construct_UClass_UMultiplayerSessionSubsystem();
MULTIPLAYER_API UClass* Z_Construct_UClass_UMultiplayerSessionSubsystem_NoRegister();
MULTIPLAYER_API UFunction* Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnCreateSessionComplete__DelegateSignature();
MULTIPLAYER_API UFunction* Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnDestroySessionComplete__DelegateSignature();
MULTIPLAYER_API UFunction* Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnStartSessionComplete__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_Multiplayer();
// End Cross Module References

// Begin Delegate FMultiplayerOnCreateSessionComplete
struct Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics
{
	struct _Script_Multiplayer_eventMultiplayerOnCreateSessionComplete_Parms
	{
		bool bWasSuccessful;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\n// Delcaring our own custom delegates for the Menu class to bind callbacks to\n//\n" },
#endif
		{ "ModuleRelativePath", "Public/MultiplayerSessionSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delcaring our own custom delegates for the Menu class to bind callbacks to" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bWasSuccessful_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
{
	((_Script_Multiplayer_eventMultiplayerOnCreateSessionComplete_Parms*)Obj)->bWasSuccessful = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_Multiplayer_eventMultiplayerOnCreateSessionComplete_Parms), &Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Multiplayer, nullptr, "MultiplayerOnCreateSessionComplete__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::_Script_Multiplayer_eventMultiplayerOnCreateSessionComplete_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::_Script_Multiplayer_eventMultiplayerOnCreateSessionComplete_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnCreateSessionComplete__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FMultiplayerOnCreateSessionComplete_DelegateWrapper(const FMulticastScriptDelegate& MultiplayerOnCreateSessionComplete, bool bWasSuccessful)
{
	struct _Script_Multiplayer_eventMultiplayerOnCreateSessionComplete_Parms
	{
		bool bWasSuccessful;
	};
	_Script_Multiplayer_eventMultiplayerOnCreateSessionComplete_Parms Parms;
	Parms.bWasSuccessful=bWasSuccessful ? true : false;
	MultiplayerOnCreateSessionComplete.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FMultiplayerOnCreateSessionComplete

// Begin Delegate FMultiplayerOnDestroySessionComplete
struct Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics
{
	struct _Script_Multiplayer_eventMultiplayerOnDestroySessionComplete_Parms
	{
		bool bWasSuccessful;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MultiplayerSessionSubsystem.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bWasSuccessful_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
{
	((_Script_Multiplayer_eventMultiplayerOnDestroySessionComplete_Parms*)Obj)->bWasSuccessful = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_Multiplayer_eventMultiplayerOnDestroySessionComplete_Parms), &Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Multiplayer, nullptr, "MultiplayerOnDestroySessionComplete__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::_Script_Multiplayer_eventMultiplayerOnDestroySessionComplete_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::_Script_Multiplayer_eventMultiplayerOnDestroySessionComplete_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnDestroySessionComplete__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnDestroySessionComplete__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FMultiplayerOnDestroySessionComplete_DelegateWrapper(const FMulticastScriptDelegate& MultiplayerOnDestroySessionComplete, bool bWasSuccessful)
{
	struct _Script_Multiplayer_eventMultiplayerOnDestroySessionComplete_Parms
	{
		bool bWasSuccessful;
	};
	_Script_Multiplayer_eventMultiplayerOnDestroySessionComplete_Parms Parms;
	Parms.bWasSuccessful=bWasSuccessful ? true : false;
	MultiplayerOnDestroySessionComplete.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FMultiplayerOnDestroySessionComplete

// Begin Delegate FMultiplayerOnStartSessionComplete
struct Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnStartSessionComplete__DelegateSignature_Statics
{
	struct _Script_Multiplayer_eventMultiplayerOnStartSessionComplete_Parms
	{
		bool bWasSuccessful;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MultiplayerSessionSubsystem.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bWasSuccessful_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
{
	((_Script_Multiplayer_eventMultiplayerOnStartSessionComplete_Parms*)Obj)->bWasSuccessful = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_Multiplayer_eventMultiplayerOnStartSessionComplete_Parms), &Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Multiplayer, nullptr, "MultiplayerOnStartSessionComplete__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::_Script_Multiplayer_eventMultiplayerOnStartSessionComplete_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::_Script_Multiplayer_eventMultiplayerOnStartSessionComplete_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnStartSessionComplete__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnStartSessionComplete__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FMultiplayerOnStartSessionComplete_DelegateWrapper(const FMulticastScriptDelegate& MultiplayerOnStartSessionComplete, bool bWasSuccessful)
{
	struct _Script_Multiplayer_eventMultiplayerOnStartSessionComplete_Parms
	{
		bool bWasSuccessful;
	};
	_Script_Multiplayer_eventMultiplayerOnStartSessionComplete_Parms Parms;
	Parms.bWasSuccessful=bWasSuccessful ? true : false;
	MultiplayerOnStartSessionComplete.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FMultiplayerOnStartSessionComplete

// Begin Class UMultiplayerSessionSubsystem
void UMultiplayerSessionSubsystem::StaticRegisterNativesUMultiplayerSessionSubsystem()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMultiplayerSessionSubsystem);
UClass* Z_Construct_UClass_UMultiplayerSessionSubsystem_NoRegister()
{
	return UMultiplayerSessionSubsystem::StaticClass();
}
struct Z_Construct_UClass_UMultiplayerSessionSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "MultiplayerSessionSubsystem.h" },
		{ "ModuleRelativePath", "Public/MultiplayerSessionSubsystem.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMultiplayerSessionSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UMultiplayerSessionSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_Multiplayer,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMultiplayerSessionSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMultiplayerSessionSubsystem_Statics::ClassParams = {
	&UMultiplayerSessionSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMultiplayerSessionSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UMultiplayerSessionSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMultiplayerSessionSubsystem()
{
	if (!Z_Registration_Info_UClass_UMultiplayerSessionSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMultiplayerSessionSubsystem.OuterSingleton, Z_Construct_UClass_UMultiplayerSessionSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMultiplayerSessionSubsystem.OuterSingleton;
}
template<> MULTIPLAYER_API UClass* StaticClass<UMultiplayerSessionSubsystem>()
{
	return UMultiplayerSessionSubsystem::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMultiplayerSessionSubsystem);
UMultiplayerSessionSubsystem::~UMultiplayerSessionSubsystem() {}
// End Class UMultiplayerSessionSubsystem

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MultiplayerSessionSubsystem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMultiplayerSessionSubsystem, UMultiplayerSessionSubsystem::StaticClass, TEXT("UMultiplayerSessionSubsystem"), &Z_Registration_Info_UClass_UMultiplayerSessionSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMultiplayerSessionSubsystem), 539350904U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MultiplayerSessionSubsystem_h_322351459(TEXT("/Script/Multiplayer"),
	Z_CompiledInDeferFile_FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MultiplayerSessionSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MultiplayerSessionSubsystem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
