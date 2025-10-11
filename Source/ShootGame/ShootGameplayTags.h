#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"


/*
 * GameplayTags SingleTon
 */

struct FShootGameplayTags
{
public:
	static FShootGameplayTags  GetShootTags(){return ShootGameplayTags;}
	static void AddTags();

	
	FGameplayTag ShootWeaponDamageTag;


private:
	 static FShootGameplayTags ShootGameplayTags;
};
