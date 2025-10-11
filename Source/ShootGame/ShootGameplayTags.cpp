#include "ShootGameplayTags.h"

#include "GameplayTagsManager.h"



FShootGameplayTags FShootGameplayTags::ShootGameplayTags;




void FShootGameplayTags::AddTags()
{
	ShootGameplayTags.ShootWeaponDamageTag = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.ShootWeaponDamageTag") , FString("Shoot Weapon Damage "));
}
