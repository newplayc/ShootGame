// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShootUserWidgetController.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttribueChanged , float , NewAttribute);

USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<class UShootAbilitySystemComponent>ASC;

	UPROPERTY()
	TObjectPtr<class UShootAttributeSet> AS;
	
	FWidgetControllerParams(){}
	FWidgetControllerParams(UShootAbilitySystemComponent * InASC , UShootAttributeSet * InAS) : ASC(InASC)  ,AS(InAS){}

	
};


UCLASS()
class SHOOTGAME_API UShootUserWidgetController : public UObject
{
	GENERATED_BODY()
public:
	
	void InitShootWidetController(const FWidgetControllerParams & InWidgetParams);

	void InitBroadCast();
	
	UPROPERTY(BlueprintAssignable)
	FOnAttribueChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttribueChanged OnMaxHealhChanged;
	
protected:
	
	void InitAttibute();
	TObjectPtr< UShootAbilitySystemComponent>ASC;
	TObjectPtr<UShootAttributeSet>AS;
};
