// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShootWeaponFire.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ShootBlueprintFunctionLibrary.generated.h"

class AShootEnemy;
/**
 * 
 */
UCLASS()
class SHOOTGAME_API UShootBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	static	void ApplyEffectParams(const FEffectParams & EffectParams);
	
	static void InitEnemy(AShootEnemy * InitObject);
	
	static void GetOverlapActorsAtLocationWithSphere(AActor * WorldContextObject   ,TArray<AActor*>&Overlaps , const FVector & Center  , float Radius);  
};
