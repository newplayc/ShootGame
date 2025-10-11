// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShootUserWidget.generated.h"


/**
 * 
 */

class UShootUserWidgetController;

UCLASS()
class SHOOTGAME_API UShootUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	
	UFUNCTION(BlueprintCallable)
	void SetWidetController(UShootUserWidgetController * InWC);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UShootUserWidgetController>WidgetController;
	
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
