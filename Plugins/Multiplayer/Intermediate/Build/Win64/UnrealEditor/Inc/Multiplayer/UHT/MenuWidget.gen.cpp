// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Multiplayer/Public/MenuWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMenuWidget() {}

// Begin Cross Module References
MULTIPLAYER_API UClass* Z_Construct_UClass_UMenuWidget();
MULTIPLAYER_API UClass* Z_Construct_UClass_UMenuWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Multiplayer();
// End Cross Module References

// Begin Class UMenuWidget Function HostButtonClicked
struct Z_Construct_UFunction_UMenuWidget_HostButtonClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MenuWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMenuWidget_HostButtonClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMenuWidget, nullptr, "HostButtonClicked", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuWidget_HostButtonClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMenuWidget_HostButtonClicked_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UMenuWidget_HostButtonClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMenuWidget_HostButtonClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMenuWidget::execHostButtonClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HostButtonClicked();
	P_NATIVE_END;
}
// End Class UMenuWidget Function HostButtonClicked

// Begin Class UMenuWidget Function JoinButtonClicked
struct Z_Construct_UFunction_UMenuWidget_JoinButtonClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MenuWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMenuWidget_JoinButtonClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMenuWidget, nullptr, "JoinButtonClicked", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuWidget_JoinButtonClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMenuWidget_JoinButtonClicked_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UMenuWidget_JoinButtonClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMenuWidget_JoinButtonClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMenuWidget::execJoinButtonClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->JoinButtonClicked();
	P_NATIVE_END;
}
// End Class UMenuWidget Function JoinButtonClicked

// Begin Class UMenuWidget Function MenuSetup
struct Z_Construct_UFunction_UMenuWidget_MenuSetup_Statics
{
	struct MenuWidget_eventMenuSetup_Parms
	{
		int32 NumberOfPublicConnections;
		FString TypeOfMatch;
		FString LobbyPath;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CPP_Default_LobbyPath", "/Game/ThirdPersonCPP/Maps/Lobby" },
		{ "CPP_Default_NumberOfPublicConnections", "4" },
		{ "CPP_Default_TypeOfMatch", "FreeForAll" },
		{ "ModuleRelativePath", "Public/MenuWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumberOfPublicConnections;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TypeOfMatch;
	static const UECodeGen_Private::FStrPropertyParams NewProp_LobbyPath;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMenuWidget_MenuSetup_Statics::NewProp_NumberOfPublicConnections = { "NumberOfPublicConnections", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MenuWidget_eventMenuSetup_Parms, NumberOfPublicConnections), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMenuWidget_MenuSetup_Statics::NewProp_TypeOfMatch = { "TypeOfMatch", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MenuWidget_eventMenuSetup_Parms, TypeOfMatch), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMenuWidget_MenuSetup_Statics::NewProp_LobbyPath = { "LobbyPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MenuWidget_eventMenuSetup_Parms, LobbyPath), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMenuWidget_MenuSetup_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMenuWidget_MenuSetup_Statics::NewProp_NumberOfPublicConnections,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMenuWidget_MenuSetup_Statics::NewProp_TypeOfMatch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMenuWidget_MenuSetup_Statics::NewProp_LobbyPath,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuWidget_MenuSetup_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMenuWidget_MenuSetup_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMenuWidget, nullptr, "MenuSetup", nullptr, nullptr, Z_Construct_UFunction_UMenuWidget_MenuSetup_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuWidget_MenuSetup_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMenuWidget_MenuSetup_Statics::MenuWidget_eventMenuSetup_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuWidget_MenuSetup_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMenuWidget_MenuSetup_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMenuWidget_MenuSetup_Statics::MenuWidget_eventMenuSetup_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMenuWidget_MenuSetup()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMenuWidget_MenuSetup_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMenuWidget::execMenuSetup)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_NumberOfPublicConnections);
	P_GET_PROPERTY(FStrProperty,Z_Param_TypeOfMatch);
	P_GET_PROPERTY(FStrProperty,Z_Param_LobbyPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->MenuSetup(Z_Param_NumberOfPublicConnections,Z_Param_TypeOfMatch,Z_Param_LobbyPath);
	P_NATIVE_END;
}
// End Class UMenuWidget Function MenuSetup

// Begin Class UMenuWidget Function OnCreateSession
struct Z_Construct_UFunction_UMenuWidget_OnCreateSession_Statics
{
	struct MenuWidget_eventOnCreateSession_Parms
	{
		bool bWasSuccessful;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\n// Callbacks for the custom delegates on the MultiplayerSessionsSubsystem\n//\n" },
#endif
		{ "ModuleRelativePath", "Public/MenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Callbacks for the custom delegates on the MultiplayerSessionsSubsystem" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bWasSuccessful_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UMenuWidget_OnCreateSession_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
{
	((MenuWidget_eventOnCreateSession_Parms*)Obj)->bWasSuccessful = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMenuWidget_OnCreateSession_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MenuWidget_eventOnCreateSession_Parms), &Z_Construct_UFunction_UMenuWidget_OnCreateSession_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMenuWidget_OnCreateSession_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMenuWidget_OnCreateSession_Statics::NewProp_bWasSuccessful,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuWidget_OnCreateSession_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMenuWidget_OnCreateSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMenuWidget, nullptr, "OnCreateSession", nullptr, nullptr, Z_Construct_UFunction_UMenuWidget_OnCreateSession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuWidget_OnCreateSession_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMenuWidget_OnCreateSession_Statics::MenuWidget_eventOnCreateSession_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuWidget_OnCreateSession_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMenuWidget_OnCreateSession_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMenuWidget_OnCreateSession_Statics::MenuWidget_eventOnCreateSession_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMenuWidget_OnCreateSession()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMenuWidget_OnCreateSession_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMenuWidget::execOnCreateSession)
{
	P_GET_UBOOL(Z_Param_bWasSuccessful);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnCreateSession(Z_Param_bWasSuccessful);
	P_NATIVE_END;
}
// End Class UMenuWidget Function OnCreateSession

// Begin Class UMenuWidget Function OnDestroySession
struct Z_Construct_UFunction_UMenuWidget_OnDestroySession_Statics
{
	struct MenuWidget_eventOnDestroySession_Parms
	{
		bool bWasSuccessful;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MenuWidget.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bWasSuccessful_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UMenuWidget_OnDestroySession_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
{
	((MenuWidget_eventOnDestroySession_Parms*)Obj)->bWasSuccessful = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMenuWidget_OnDestroySession_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MenuWidget_eventOnDestroySession_Parms), &Z_Construct_UFunction_UMenuWidget_OnDestroySession_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMenuWidget_OnDestroySession_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMenuWidget_OnDestroySession_Statics::NewProp_bWasSuccessful,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuWidget_OnDestroySession_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMenuWidget_OnDestroySession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMenuWidget, nullptr, "OnDestroySession", nullptr, nullptr, Z_Construct_UFunction_UMenuWidget_OnDestroySession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuWidget_OnDestroySession_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMenuWidget_OnDestroySession_Statics::MenuWidget_eventOnDestroySession_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuWidget_OnDestroySession_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMenuWidget_OnDestroySession_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMenuWidget_OnDestroySession_Statics::MenuWidget_eventOnDestroySession_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMenuWidget_OnDestroySession()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMenuWidget_OnDestroySession_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMenuWidget::execOnDestroySession)
{
	P_GET_UBOOL(Z_Param_bWasSuccessful);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnDestroySession(Z_Param_bWasSuccessful);
	P_NATIVE_END;
}
// End Class UMenuWidget Function OnDestroySession

// Begin Class UMenuWidget Function OnStartSession
struct Z_Construct_UFunction_UMenuWidget_OnStartSession_Statics
{
	struct MenuWidget_eventOnStartSession_Parms
	{
		bool bWasSuccessful;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MenuWidget.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bWasSuccessful_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UMenuWidget_OnStartSession_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
{
	((MenuWidget_eventOnStartSession_Parms*)Obj)->bWasSuccessful = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMenuWidget_OnStartSession_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MenuWidget_eventOnStartSession_Parms), &Z_Construct_UFunction_UMenuWidget_OnStartSession_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMenuWidget_OnStartSession_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMenuWidget_OnStartSession_Statics::NewProp_bWasSuccessful,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuWidget_OnStartSession_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMenuWidget_OnStartSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMenuWidget, nullptr, "OnStartSession", nullptr, nullptr, Z_Construct_UFunction_UMenuWidget_OnStartSession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuWidget_OnStartSession_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMenuWidget_OnStartSession_Statics::MenuWidget_eventOnStartSession_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuWidget_OnStartSession_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMenuWidget_OnStartSession_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMenuWidget_OnStartSession_Statics::MenuWidget_eventOnStartSession_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMenuWidget_OnStartSession()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMenuWidget_OnStartSession_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMenuWidget::execOnStartSession)
{
	P_GET_UBOOL(Z_Param_bWasSuccessful);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnStartSession(Z_Param_bWasSuccessful);
	P_NATIVE_END;
}
// End Class UMenuWidget Function OnStartSession

// Begin Class UMenuWidget
void UMenuWidget::StaticRegisterNativesUMenuWidget()
{
	UClass* Class = UMenuWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "HostButtonClicked", &UMenuWidget::execHostButtonClicked },
		{ "JoinButtonClicked", &UMenuWidget::execJoinButtonClicked },
		{ "MenuSetup", &UMenuWidget::execMenuSetup },
		{ "OnCreateSession", &UMenuWidget::execOnCreateSession },
		{ "OnDestroySession", &UMenuWidget::execOnDestroySession },
		{ "OnStartSession", &UMenuWidget::execOnStartSession },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMenuWidget);
UClass* Z_Construct_UClass_UMenuWidget_NoRegister()
{
	return UMenuWidget::StaticClass();
}
struct Z_Construct_UClass_UMenuWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "MenuWidget.h" },
		{ "ModuleRelativePath", "Public/MenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HostButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JoinButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MenuWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HostButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JoinButton;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMenuWidget_HostButtonClicked, "HostButtonClicked" }, // 1126357762
		{ &Z_Construct_UFunction_UMenuWidget_JoinButtonClicked, "JoinButtonClicked" }, // 3842039259
		{ &Z_Construct_UFunction_UMenuWidget_MenuSetup, "MenuSetup" }, // 2326370985
		{ &Z_Construct_UFunction_UMenuWidget_OnCreateSession, "OnCreateSession" }, // 3580631790
		{ &Z_Construct_UFunction_UMenuWidget_OnDestroySession, "OnDestroySession" }, // 1196121778
		{ &Z_Construct_UFunction_UMenuWidget_OnStartSession, "OnStartSession" }, // 2393228291
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMenuWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMenuWidget_Statics::NewProp_HostButton = { "HostButton", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMenuWidget, HostButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HostButton_MetaData), NewProp_HostButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMenuWidget_Statics::NewProp_JoinButton = { "JoinButton", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMenuWidget, JoinButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JoinButton_MetaData), NewProp_JoinButton_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMenuWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMenuWidget_Statics::NewProp_HostButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMenuWidget_Statics::NewProp_JoinButton,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMenuWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMenuWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Multiplayer,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMenuWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMenuWidget_Statics::ClassParams = {
	&UMenuWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UMenuWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UMenuWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMenuWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UMenuWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMenuWidget()
{
	if (!Z_Registration_Info_UClass_UMenuWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMenuWidget.OuterSingleton, Z_Construct_UClass_UMenuWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMenuWidget.OuterSingleton;
}
template<> MULTIPLAYER_API UClass* StaticClass<UMenuWidget>()
{
	return UMenuWidget::StaticClass();
}
UMenuWidget::UMenuWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMenuWidget);
UMenuWidget::~UMenuWidget() {}
// End Class UMenuWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MenuWidget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMenuWidget, UMenuWidget::StaticClass, TEXT("UMenuWidget"), &Z_Registration_Info_UClass_UMenuWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMenuWidget), 3438691361U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MenuWidget_h_4226515177(TEXT("/Script/Multiplayer"),
	Z_CompiledInDeferFile_FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MenuWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_ShootGame_Plugins_Multiplayer_Source_Multiplayer_Public_MenuWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
