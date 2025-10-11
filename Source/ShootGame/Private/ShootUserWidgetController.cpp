// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootUserWidgetController.h"
#include "ShootAbilitySystemComponent.h"
#include "ShootAttributeSet.h"


void UShootUserWidgetController::InitShootWidetController(const FWidgetControllerParams& InWidgetParams)
{
	ASC = InWidgetParams.ASC;
	AS = InWidgetParams.AS;
	InitAttibute();
}

void UShootUserWidgetController::InitBroadCast()
{
	// 首次广播
	OnMaxHealhChanged.Broadcast(AS->GetMaxHealth());
	OnHealthChanged.Broadcast(AS->GetHealth());
	
}

void UShootUserWidgetController::InitAttibute()
{
	// 添加绑定
	if(ASC)
	{
		ASC->GetGameplayAttributeValueChangeDelegate(UShootAttributeSet::GetHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData &Data)
		{
			OnHealthChanged.Broadcast(Data.NewValue);
		});

		ASC->GetGameplayAttributeValueChangeDelegate(UShootAttributeSet::GetMaxHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData &Data)
			{
				OnMaxHealhChanged.Broadcast(Data.NewValue);
			});
	}
}
