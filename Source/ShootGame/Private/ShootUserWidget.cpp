// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootUserWidget.h"



void UShootUserWidget::SetWidetController(UShootUserWidgetController* InWC)
{
	WidgetController = InWC;
	WidgetControllerSet();
}
