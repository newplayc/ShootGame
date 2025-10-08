// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMultiplayer_init() {}
	MULTIPLAYER_API UFunction* Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnCreateSessionComplete__DelegateSignature();
	MULTIPLAYER_API UFunction* Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnDestroySessionComplete__DelegateSignature();
	MULTIPLAYER_API UFunction* Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnStartSessionComplete__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Multiplayer;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Multiplayer()
	{
		if (!Z_Registration_Info_UPackage__Script_Multiplayer.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnCreateSessionComplete__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnDestroySessionComplete__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Multiplayer_MultiplayerOnStartSessionComplete__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Multiplayer",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xAC660EFF,
				0xAD3F20DE,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Multiplayer.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Multiplayer.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Multiplayer(Z_Construct_UPackage__Script_Multiplayer, TEXT("/Script/Multiplayer"), Z_Registration_Info_UPackage__Script_Multiplayer, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xAC660EFF, 0xAD3F20DE));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
