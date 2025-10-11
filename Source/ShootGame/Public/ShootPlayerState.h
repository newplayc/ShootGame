// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "ShootPlayerState.generated.h"


class UAttributeSet;
class UShootAbilitySystemComponent;
class UShootAttributeSet;
/**
 * 
 */
UCLASS()
class SHOOTGAME_API AShootPlayerState : public APlayerState , public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AShootPlayerState();
	virtual UAbilitySystemComponent * GetAbilitySystemComponent() const override;
	
	UAttributeSet * GetAttributes() const;
protected:
	
	UPROPERTY(VisibleAnywhere , BlueprintReadOnly)
	TObjectPtr<UShootAttributeSet>Attributes;

	
	UPROPERTY(VisibleAnywhere ,BlueprintReadOnly)
	TObjectPtr<UShootAbilitySystemComponent> AbilitySystemComponent;
};
