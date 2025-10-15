// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootWeaponFire.h"
#include "BulletBase.h"
#include "ShootGameCharacter.h"
#include "Kismet/KismetMathLibrary.h"



bool AShootWeaponFire::Fire(const FVector_NetQuantize& FireImpact)
{
	
	if(!Super::Fire(FireImpact))return false;

	
	FVector  MuzzleLocation =  WeaponMesh->GetSocketLocation(GetMuzzleSocketName());
	FRotator SpawnRotation  = UKismetMathLibrary::GetDirectionUnitVector(MuzzleLocation , FireImpact).Rotation();
	FTransform SpawnTransform(SpawnRotation , MuzzleLocation);
		
	ABulletBase *SpawnBullet =  GetWorld()->SpawnActorDeferred<ABulletBase>(
		BulletClass ,
		SpawnTransform ,
		GetOwner() ,
		Cast<AShootGameCharacter>(GetOwner())
		);
	
	SpawnBullet->EffectParams = MakeDefaultEffectParam();
	SpawnBullet->FinishSpawning(SpawnTransform);
	SpendAmmo();

	CanFire = false;
	GetWorld()->GetTimerManager().SetTimer(FireDelayTimer , this , &AShootWeapon::SetCanFire ,FireDelay ,false);
	
	return true;
}



