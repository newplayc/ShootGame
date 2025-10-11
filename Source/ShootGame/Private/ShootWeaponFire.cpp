// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootWeaponFire.h"

#include "AbilitySystemComponent.h"
#include "BulletBase.h"
#include "ShootGameCharacter.h"


void AShootWeaponFire::Fire(const FVector_NetQuantize& FireImpact)
{
	Super::Fire(FireImpact);
	FVector  MuzzleLocation =  WeaponMesh->GetSocketLocation(GetMuzzleSocketName());
	FRotator SpawnRotation = (FireImpact - MuzzleLocation).Rotation();

	
	FTransform SpawnTransform(SpawnRotation , MuzzleLocation);
	ABulletBase *SpawnBullet =  GetWorld()->SpawnActorDeferred<ABulletBase>(
		BulletClass ,
		SpawnTransform ,
		GetOwner() ,
		Cast<AShootGameCharacter>(GetOwner())
		);
	SpawnBullet->EffectParams = MakeDefaultEffectParam();
	SpawnBullet->FinishSpawning(SpawnTransform);
	
}

FEffectParams AShootWeaponFire::MakeDefaultEffectParam() const
{
		FEffectParams Params;
		if(AShootGameCharacter * Player = Cast<AShootGameCharacter>(GetOwner()))
		{
			Params.SoucreASC = Player->GetAbilitySystemComponent();
			FGameplayEffectContextHandle EffectContextHandle = Params.SoucreASC->MakeEffectContext();
			EffectContextHandle.AddSourceObject(Player);
			Params.ApplyEffect = Params.SoucreASC->MakeOutgoingSpec(DamageEffect , 1 , EffectContextHandle);
			Params.BodyDamage = BodyDamage;
		}
		return Params;
}
