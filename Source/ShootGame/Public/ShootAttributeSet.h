// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "ShootAttributeSet.generated.h"

/**
 * 
 */

# define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)



UCLASS()
class SHOOTGAME_API UShootAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_Health, Category = "Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UShootAttributeSet, Health)

	UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_MaxHealth, Category = "Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UShootAttributeSet, MaxHealth)

	
	UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_InComingDamage, Category = "Attributes")
	FGameplayAttributeData InComingDamage;
	ATTRIBUTE_ACCESSORS(UShootAttributeSet, InComingDamage)
protected:

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData & OldMaxHealth)const;
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData & OldHealth) const;

	UFUNCTION()
	void OnRep_InComingDamage(const FGameplayAttributeData & OldInComingDamage)const;
	
};