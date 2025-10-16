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


	FGameplayTag EnemyAbilty_1;
	FGameplayTag EnemyAbilty_2;
	FGameplayTag EnemyAbilty_3;
	
	FGameplayTag EnemyMontageAttack_1;
	FGameplayTag EnemyMontageAttack_2;
	FGameplayTag EnemyMontageAttack_3;

private:
	 static FShootGameplayTags ShootGameplayTags;
};
