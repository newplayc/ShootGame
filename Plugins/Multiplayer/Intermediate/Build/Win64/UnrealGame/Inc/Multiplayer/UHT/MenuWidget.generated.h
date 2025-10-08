// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MenuWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MULTIPLAYER_MenuWidget_generated_h
#error "MenuWidget.generated.h already included, missing '#pragma once' in MenuWidget.h"
#endif
#define MULTIPLAYER_MenuWidget_generated_h

#define FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MenuWidget_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execJoinButtonClicked); \
	DECLARE_FUNCTION(execHostButtonClicked); \
	DECLARE_FUNCTION(execOnStartSession); \
	DECLARE_FUNCTION(execOnDestroySession); \
	DECLARE_FUNCTION(execOnCreateSession); \
	DECLARE_FUNCTION(execMenuSetup);


#define FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MenuWidget_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMenuWidget(); \
	friend struct Z_Construct_UClass_UMenuWidget_Statics; \
public: \
	DECLARE_CLASS(UMenuWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Multiplayer"), NO_API) \
	DECLARE_SERIALIZER(UMenuWidget)


#define FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MenuWidget_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMenuWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMenuWidget(UMenuWidget&&); \
	UMenuWidget(const UMenuWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMenuWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMenuWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMenuWidget) \
	NO_API virtual ~UMenuWidget();


#define FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MenuWidget_h_14_PROLOG
#define FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MenuWidget_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MenuWidget_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MenuWidget_h_17_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MenuWidget_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MULTIPLAYER_API UClass* StaticClass<class UMenuWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MenuWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
