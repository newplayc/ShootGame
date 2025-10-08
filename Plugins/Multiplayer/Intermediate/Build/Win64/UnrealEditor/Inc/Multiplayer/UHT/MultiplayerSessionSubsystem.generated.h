// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MultiplayerSessionSubsystem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MULTIPLAYER_MultiplayerSessionSubsystem_generated_h
#error "MultiplayerSessionSubsystem.generated.h already included, missing '#pragma once' in MultiplayerSessionSubsystem.h"
#endif
#define MULTIPLAYER_MultiplayerSessionSubsystem_generated_h

#define FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MultiplayerSessionSubsystem_h_14_DELEGATE \
MULTIPLAYER_API void FMultiplayerOnCreateSessionComplete_DelegateWrapper(const FMulticastScriptDelegate& MultiplayerOnCreateSessionComplete, bool bWasSuccessful);


#define FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MultiplayerSessionSubsystem_h_17_DELEGATE \
MULTIPLAYER_API void FMultiplayerOnDestroySessionComplete_DelegateWrapper(const FMulticastScriptDelegate& MultiplayerOnDestroySessionComplete, bool bWasSuccessful);


#define FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MultiplayerSessionSubsystem_h_18_DELEGATE \
MULTIPLAYER_API void FMultiplayerOnStartSessionComplete_DelegateWrapper(const FMulticastScriptDelegate& MultiplayerOnStartSessionComplete, bool bWasSuccessful);


#define FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MultiplayerSessionSubsystem_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMultiplayerSessionSubsystem(); \
	friend struct Z_Construct_UClass_UMultiplayerSessionSubsystem_Statics; \
public: \
	DECLARE_CLASS(UMultiplayerSessionSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Multiplayer"), NO_API) \
	DECLARE_SERIALIZER(UMultiplayerSessionSubsystem)


#define FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MultiplayerSessionSubsystem_h_28_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMultiplayerSessionSubsystem(UMultiplayerSessionSubsystem&&); \
	UMultiplayerSessionSubsystem(const UMultiplayerSessionSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMultiplayerSessionSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMultiplayerSessionSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMultiplayerSessionSubsystem) \
	NO_API virtual ~UMultiplayerSessionSubsystem();


#define FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MultiplayerSessionSubsystem_h_25_PROLOG
#define FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MultiplayerSessionSubsystem_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MultiplayerSessionSubsystem_h_28_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MultiplayerSessionSubsystem_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MULTIPLAYER_API UClass* StaticClass<class UMultiplayerSessionSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MultiplayerSessionSubsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
