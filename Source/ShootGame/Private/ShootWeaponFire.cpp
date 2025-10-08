// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootWeaponFire.h"
#include "BulletBase.h"


void AShootWeaponFire::Fire(const FVector_NetQuantize& FireImpact)
{
	Super::Fire(FireImpact);
	FVector  MuzzleLocation =  WeaponMesh->GetSocketLocation(GetMuzzleSocketName());
	FRotator SpawnRotation = (FireImpact - MuzzleLocation).Rotation();
	GetWorld()->SpawnActor<ABulletBase>(BulletClass , MuzzleLocation, SpawnRotation);
}
