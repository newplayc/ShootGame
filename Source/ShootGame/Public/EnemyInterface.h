// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()

};

/**
 * 
 */
class SHOOTGAME_API IEnemyInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	FName GetNearBoneWithBullet(const FVector_NetQuantize & HitLocation);

	UFUNCTION(BlueprintNativeEvent)
	void UpdateMotionWarp(FVector TargetLocation);
	
	UFUNCTION(BlueprintNativeEvent)
	bool IsDead();

	UFUNCTION(BlueprintNativeEvent)
	void Died();
	
	UFUNCTION(NetMulticast , Reliable)
	virtual  void PlayReactMontage();
	
	
	UFUNCTION(NetMulticast ,Reliable)
	virtual void PlayDeathMontage();
	
	
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
};
