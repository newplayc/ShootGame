// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootAssetManager.h"

#include "AbilitySystemGlobals.h"
#include "ShootGame/ShootGameplayTags.h"

const UShootAssetManager& UShootAssetManager::Get()
{
	check(GEngine)
	return *Cast<UShootAssetManager>(GEngine->AssetManager);
	
}

void UShootAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	FShootGameplayTags::AddTags();
	UAbilitySystemGlobals::Get().InitGlobalData();	
}
