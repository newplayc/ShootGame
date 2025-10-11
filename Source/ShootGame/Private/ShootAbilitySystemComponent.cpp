// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootAbilitySystemComponent.h"

void UShootAbilitySystemComponent::ApplyEffectToInit(const TSubclassOf<UGameplayEffect> & GE , float level , UObject * Source)
{
	checkf(GE , TEXT("The InitAttribue GE Is Empty check the Character Bp With EffectToInit "));
	
	FGameplayEffectContextHandle ContextHandle =  MakeEffectContext();
	ContextHandle.AddSourceObject(Source);
	FGameplayEffectSpecHandle EffectSpecHandle =   MakeOutgoingSpec(GE ,level , ContextHandle);
	ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data);
}
