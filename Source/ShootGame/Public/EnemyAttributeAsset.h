// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Engine/DataAsset.h"
#include "EnemyAttributeAsset.generated.h"

/**
 * 
 */
UCLASS(Blueprintable , BlueprintType)
class SHOOTGAME_API UEnemyAttributeAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditDefaultsOnly , Category ="Ability")
	TArray<TSubclassOf<UGameplayAbility>>AiAbilitys;
	UPROPERTY(EditDefaultsOnly , Category = "Attributes")
	TSubclassOf<UGameplayEffect>InitAttributeEffect;
};
