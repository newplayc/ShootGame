// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MultiPlayerGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTGAME_API AMultiPlayerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual  void PostLogin(APlayerController* NewPlayer) override;
	virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
	
};
