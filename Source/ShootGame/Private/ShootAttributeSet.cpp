// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootAttributeSet.h"

#include "EnemyInterface.h"
#include "GameplayEffectExtension.h"
#include "ShootAbilitySystemComponent.h"
#include "ShootAssetManager.h"
#include "ShootGameCharacter.h"
#include "Image/ImageBuilder.h"
#include "Net/UnrealNetwork.h"


void UShootAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UShootAttributeSet , Health , COND_None , REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShootAttributeSet , MaxHealth , COND_None , REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UShootAttributeSet ,InComingDamage ,COND_None , REPNOTIFY_Always);
}

void UShootAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	if(Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue , 0 , GetMaxHealth());
	}
	
}

void UShootAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	AActor * SourceActor = Data.EffectSpec.GetContext().GetOriginalInstigatorAbilitySystemComponent()->GetAvatarActor();
	AActor * TargetActor = Data.Target.GetAvatarActor();

	IEnemyInterface  * SourceCharacter = Cast<IEnemyInterface>(SourceActor);
	IEnemyInterface * TargetCharacter = Cast<IEnemyInterface>(TargetActor);

	
	if(!SourceActor || !TargetActor)return;

	if(TargetActor->Implements<UEnemyInterface>())
	{
		if(IEnemyInterface::Execute_IsDead(TargetActor)) return;
	}
	
	if(Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth() , 0 , GetMaxHealth()));
	}

	if(Data.EvaluatedData.Attribute == GetInComingDamageAttribute())
	{
		const float NewHealth = GetHealth() - GetInComingDamage();
		SetHealth(FMath::Clamp(NewHealth  , 0 , GetMaxHealth()));

		const bool bDead = NewHealth <= 0;
		if(!bDead)
		{
			TargetCharacter->PlayReactMontage();
		}
		else
		{
			TargetCharacter->Died();
		}
	}
}


void UShootAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShootAttributeSet ,MaxHealth , OldMaxHealth);
}


void UShootAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShootAttributeSet , Health  , OldHealth);
}

void UShootAttributeSet::OnRep_InComingDamage(const FGameplayAttributeData& OldInComingDamage) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UShootAttributeSet , InComingDamage  , OldInComingDamage);
}

