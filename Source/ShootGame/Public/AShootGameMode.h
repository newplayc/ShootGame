// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyAttributeAsset.h"
#include "GameFramework/GameModeBase.h"
#include "AShootGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTGAME_API AAShootGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void PlayerElim(ACharacter * DCharacter  , APlayerController * DController);

	void ReLifePlayer(APlayerController * RPlayerController);

	UPROPERTY(EditDefaultsOnly ,Category ="Data")
	TObjectPtr<UEnemyAttributeAsset>EnemyAttributeAsset;
};
