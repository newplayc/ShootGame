
#include "ShootGameplayTags.h"

#include "GameplayTagsManager.h"



FShootGameplayTags FShootGameplayTags::ShootGameplayTags;




void FShootGameplayTags::AddTags()
{
	ShootGameplayTags.ShootWeaponDamageTag = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.ShootWeaponDamageTag") , FString("Shoot Weapon Damage "));


	ShootGameplayTags.EnemyAbilty_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Enemy.Ability.1") ,FString("怪物技能_1"));
	ShootGameplayTags.EnemyAbilty_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Enemy.Ability.2") ,FString("怪物技能_2"));
	ShootGameplayTags.EnemyAbilty_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Enemy.Ability.3") ,FString("怪物技能_3"));

	
	ShootGameplayTags.EnemyMontageAttack_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Enemy.MontageAttack.1") ,FString("怪物蒙太奇攻击动画_1"));
	ShootGameplayTags.EnemyMontageAttack_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Enemy.MontageAttack.2") ,FString("怪物蒙太奇攻击动画_2"));
	ShootGameplayTags.EnemyMontageAttack_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Enemy.MontageAttack.3") ,FString("怪物蒙太奇攻击动画_3"));
}
