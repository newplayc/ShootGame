// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootBlueprintFunctionLibrary.h"

#include "AbilitySystemComponent.h"
#include "AShootGameMode.h"
#include "ShootAbilitySystemComponent.h"
#include "ShootEnemy.h"
#include "Engine/OverlapResult.h"
#include "Kismet/GameplayStatics.h"

void UShootBlueprintFunctionLibrary::ApplyEffectParams(const FEffectParams& EffectParams)
{
	for(UAbilitySystemComponent * TargetASC : EffectParams.TargetASC)
	{
		TargetASC->ApplyGameplayEffectSpecToSelf(*EffectParams.ApplyEffect.Data);
	}
}



void UShootBlueprintFunctionLibrary::InitEnemy(AShootEnemy* InitObject)
{
	
	AAShootGameMode  * ShootGameMode =  Cast<AAShootGameMode> (UGameplayStatics::GetGameMode(InitObject));
	if(!ShootGameMode)return;
	if(IAbilitySystemInterface * IAS = Cast<IAbilitySystemInterface>(InitObject)){
		if(UShootAbilitySystemComponent * TargetAsc = Cast<UShootAbilitySystemComponent>(IAS->GetAbilitySystemComponent())){
			check(ShootGameMode->EnemyAttributeAsset);
			
			TargetAsc->InitAbilities(ShootGameMode->EnemyAttributeAsset->AiAbilitys);
			TargetAsc->ApplyEffectToInit(ShootGameMode->EnemyAttributeAsset->InitAttributeEffect , 1 , InitObject);
		} 
	}
}

void UShootBlueprintFunctionLibrary::GetOverlapActorsAtLocationWithSphere(AActor * WorldContextObject ,  TArray<AActor*>& Overlaps,
	const FVector& Center, float Radius)
{
	
	UWorld * World =  WorldContextObject->GetWorld();
	
	TArray<FOverlapResult>OverlapResults;
	FCollisionShape CollisionShape = FCollisionShape::MakeSphere(Radius);
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(WorldContextObject);
	
	World->OverlapMultiByChannel(OverlapResults ,
		Center ,
		FQuat::Identity ,
		ECC_GameTraceChannel1 ,
		CollisionShape ,
		QueryParams
		);
	
	DrawDebugSphere(World , Center , Radius , 0 , FColor::Red , false, 3.f , 0 , 4);

	
	for(FOverlapResult & Result : OverlapResults)
	{
		Overlaps.AddUnique(Result.GetActor());
	}
}
