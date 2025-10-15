// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShootWeapon.h"
#include "ShootWeaponFire.generated.h"

class ABulletBase;
/**
 *
 */




UCLASS()
class SHOOTGAME_API AShootWeaponFire : public AShootWeapon
{
	GENERATED_BODY()
public:
	
	virtual bool Fire(const FVector_NetQuantize& FireImpact)  override;
protected:

	
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ABulletBase> BulletClass;
	
};
