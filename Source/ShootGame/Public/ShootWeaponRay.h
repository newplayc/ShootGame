// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShootWeapon.h"
#include "ShootWeaponRay.generated.h"

class UNiagaraSystem;
/**
 * 
 */
UCLASS()
class SHOOTGAME_API AShootWeaponRay : public AShootWeapon
{
	GENERATED_BODY()

protected:
	virtual bool Fire(const FVector_NetQuantize& FireImpact) override;

	UPROPERTY(EditDefaultsOnly)
	float DamageRadio;
	
	
	// 射线类武器最远距离
	UPROPERTY(EditDefaultsOnly)
	float RayLength;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UNiagaraSystem>RayNiagara;

	UFUNCTION(NetMulticast , Reliable)
	void SpawnElecrtic(const FVector_NetQuantize & MuzzleLocation ,const FVector_NetQuantize & SpawnRotation , const FVector_NetQuantize & End);
};
