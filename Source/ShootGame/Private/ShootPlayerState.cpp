// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootPlayerState.h"

#include "ShootAbilitySystemComponent.h"
#include "ShootAttributeSet.h"


AShootPlayerState::AShootPlayerState()
{
	Attributes = CreateDefaultSubobject<UShootAttributeSet>("Attributes");
	AbilitySystemComponent = CreateDefaultSubobject<UShootAbilitySystemComponent>("AbilitySystemComponent");
	
}


UAbilitySystemComponent* AShootPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AShootPlayerState::GetAttributes() const
{
	return Attributes;
}
