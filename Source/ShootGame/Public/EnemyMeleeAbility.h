// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShootWeapon.h"
#include "Abilities/GameplayAbility.h"
#include "EnemyMeleeAbility.generated.h"

/**
 * 
 */


class AShootEnemy;

UCLASS()
class SHOOTGAME_API UEnemyMeleeAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	
	UFUNCTION()
	void ComingWaitEvent(FGameplayEventData  PayLoad);

	UPROPERTY(EditDefaultsOnly)
	float DamageRadius = 50.f;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayEffect>DamageEffect;
	
	FEffectParams MakeDefaultParams();
	
	AShootEnemy * Enemy = nullptr;
	
	FName DamageSocketName;
};
