// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ShootGameAnimInstance.generated.h"

class AShootGameCharacter;
enum class ETurnState : uint8;
/**
 * 
 */
UCLASS()
class SHOOTGAME_API UShootGameAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(BlueprintReadOnly , Category = "Variable")
	AShootGameCharacter *  NowCharacter = nullptr;
	UPROPERTY(BlueprintReadOnly , Category = "Variable")
	bool bIsFalling;
	UPROPERTY(BlueprintReadOnly ,Category = "Variable")
	bool bIsAccelerated;
	UPROPERTY(BlueprintReadOnly ,Category = "Variable")
	float Velocity;
	UPROPERTY(BlueprintReadOnly ,Category = "Variable")
	bool bIsEquipped;
	UPROPERTY(BlueprintReadOnly ,Category = "Variable")
	bool bIsCrouch;
	UPROPERTY(BlueprintReadOnly ,Category = "Variable")
	bool bIsAiming;
	UPROPERTY(BlueprintReadOnly ,Category = "Variable")
	float YawOffest;

	UPROPERTY(BlueprintReadOnly ,Category = "Variable")
	float AO_Yaw;

	UPROPERTY(BlueprintReadOnly ,Category = "Variable")
	float AO_Pitch;

	UPROPERTY(BlueprintReadOnly ,Category = "Variable")
	FTransform WeaponLeftHandTransform;

	UPROPERTY(BlueprintReadOnly ,Category = "Variable")
	ETurnState TurnState;
	 
	
};
