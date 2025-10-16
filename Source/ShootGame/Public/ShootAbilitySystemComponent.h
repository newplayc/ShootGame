// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "ShootAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTGAME_API UShootAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void InitAbilities(const TArray<TSubclassOf<UGameplayAbility>> & Abilities);
	void ApplyEffectToInit(const TSubclassOf<UGameplayEffect> & GE , float level , UObject  *Source);
	
};
