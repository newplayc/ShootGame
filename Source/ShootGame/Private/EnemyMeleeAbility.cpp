// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyMeleeAbility.h"

#include "AbilitySystemBlueprintLibrary.h"

#include "ShootBlueprintFunctionLibrary.h"
#include "ShootEnemy.h"

#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"
#include "Abilities/Tasks/AbilityTask_WaitGameplayEvent.h"

void UEnemyMeleeAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                         const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                         const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	
	Enemy = Cast<AShootEnemy>(ActorInfo->AvatarActor);
	IEnemyInterface::Execute_UpdateMotionWarp(Enemy , Enemy->AttackedActor->GetActorLocation());
	const TArray<FAttackMontageInfo> & Attacks =   Enemy->GetAttackMontages();

	
	if(Attacks.IsEmpty())
	{
		UE_LOG(LogTemp , Warning  ,TEXT("Enemy Attack Montage Empty"));
		return;;
	}
	int Rand = FMath::RandRange(0 , Attacks.Num()-1);
	DamageSocketName = Attacks[Rand].DamageSocketName;
	UAbilityTask_PlayMontageAndWait * TaskProxy = UAbilityTask_PlayMontageAndWait::CreatePlayMontageAndWaitProxy(this ,
		FName("PlayAttackMontage") ,
		Attacks[Rand].AttackMontage,
		1);
	
	
	UAbilityTask_WaitGameplayEvent * WaitGameplayEvent =  UAbilityTask_WaitGameplayEvent::WaitGameplayEvent(this , Attacks[Rand].MontageAttackTag , nullptr , true ,false);
	WaitGameplayEvent->EventReceived.AddDynamic(this , &ThisClass::ComingWaitEvent);
}

void UEnemyMeleeAbility::ComingWaitEvent(FGameplayEventData PayLoad)
{
	FVector DamageCenter =  Enemy->GetMesh()->GetSocketLocation(DamageSocketName);
	
	TArray<AActor*> Objects;
	UShootBlueprintFunctionLibrary::GetOverlapActorsAtLocationWithSphere(Enemy , Objects , DamageCenter , DamageRadius);
	FEffectParams EffectParams = MakeDefaultParams();
	for( AActor* Tar : Objects)
	{
		if(Tar->Implements<UEnemyInterface>())
		{
			if(UAbilitySystemComponent *ASC =  UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Tar))
			{
				EffectParams.TargetASC.AddUnique(ASC);
			}
		}
	}
	UShootBlueprintFunctionLibrary::ApplyEffectParams(EffectParams);
}

FEffectParams UEnemyMeleeAbility::MakeDefaultParams()
{
	FEffectParams EffectParams;

	EffectParams.ApplyEffect = MakeOutgoingGameplayEffectSpec(DamageEffect,1);
	EffectParams.SoucreASC = GetActorInfo().AbilitySystemComponent.Get();
	return EffectParams;
}
