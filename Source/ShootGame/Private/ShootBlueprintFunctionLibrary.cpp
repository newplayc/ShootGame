// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootBlueprintFunctionLibrary.h"

#include "AbilitySystemComponent.h"

void UShootBlueprintFunctionLibrary::ApplyEffectParams(const FEffectParams& EffectParams)
{
	EffectParams.TargetASC->ApplyGameplayEffectSpecToSelf(*EffectParams.ApplyEffect.Data);
}
