// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootBlueprintFunctionLibrary.h"

#include "AbilitySystemComponent.h"

void UShootBlueprintFunctionLibrary::ApplyEffectParams(const FEffectParams& EffectParams)
{
	for(UAbilitySystemComponent * TargetASC : EffectParams.TargetASC)
	{
		TargetASC-> ApplyGameplayEffectSpecToSelf(*EffectParams.ApplyEffect.Data);
	}
}
