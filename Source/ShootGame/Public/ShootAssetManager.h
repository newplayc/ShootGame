// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "ShootAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTGAME_API UShootAssetManager : public UAssetManager
{
	GENERATED_BODY()

	static const UShootAssetManager&Get();

	virtual void StartInitialLoading() override;
};
