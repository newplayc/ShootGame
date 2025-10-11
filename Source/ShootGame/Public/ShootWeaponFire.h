// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "ShootWeapon.h"
#include "ShootWeaponFire.generated.h"

class ABulletBase;
/**
 *
 */



USTRUCT(BlueprintType)
struct FBodyDamage
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly)
	float Head;

	UPROPERTY(EditDefaultsOnly)
	float Up;
	
	UPROPERTY(EditDefaultsOnly)
	float Down;
	
	float GetDamage(FName BoneName)
	{
		if(BoneName == "Head")
		{
			return Head;
		}
		if(BoneName == "spine_03")
		{
			return Up;
		}
		if(BoneName == "pelvis")
		{
			return Down;
		}
		return 0;
	}

};


USTRUCT(BlueprintType)
struct FEffectParams
{
	GENERATED_BODY()
	FEffectParams() = default;
	
	UPROPERTY()
	UAbilitySystemComponent * SoucreASC;

	UPROPERTY()
	UAbilitySystemComponent * TargetASC;
	
	UPROPERTY()
	FGameplayEffectSpecHandle ApplyEffect;

	UPROPERTY()
	FBodyDamage BodyDamage;
};

UCLASS()
class SHOOTGAME_API AShootWeaponFire : public AShootWeapon
{
	GENERATED_BODY()
public:
	virtual void Fire(const FVector_NetQuantize& FireImpact)  override;
	
protected:
	UPROPERTY(EditDefaultsOnly)
	FBodyDamage BodyDamage;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayEffect>DamageEffect;
	
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ABulletBase> BulletClass;
	
	FEffectParams MakeDefaultEffectParam() const;
};
