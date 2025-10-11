// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ShootHud.generated.h"

/**
 * 
 */

struct FWidgetControllerParams;
class AShootGameController;
class UShootUserWidget;
class UShootUserWidgetController;

USTRUCT(Blueprintable)
struct FAimCrossHair
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditDefaultsOnly)
	UTexture2D * CenterText;
	UPROPERTY(EditDefaultsOnly)
	UTexture2D * UpTexture;
	UPROPERTY(EditDefaultsOnly)
	UTexture2D * DownTexture;
	UPROPERTY(EditDefaultsOnly)
	UTexture2D * RightTexture;
	UPROPERTY(EditDefaultsOnly)
	UTexture2D * LeftTexture;
	UPROPERTY(EditDefaultsOnly)
	FColor DrawColor = FColor::White;
};



UCLASS()
class SHOOTGAME_API AShootHud : public AHUD
{
	GENERATED_BODY()
public:
	bool bAim = false;
	bool bMove = false;
	bool bInAir = false;
	bool bDrawAimCrossHair = false;
	FAimCrossHair AimCrossHair;

	void InitGameWidget(class UShootAbilitySystemComponent *InASC  ,class UShootAttributeSet * InAS);

	
protected:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UShootUserWidget>GameUserWidgtClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UShootUserWidgetController>GameUserWidgetControllerClass;

	UPROPERTY(BlueprintReadOnly)
	UShootUserWidget * 	GameUserWidet;

	UPROPERTY(BlueprintReadOnly)
	UShootUserWidgetController * ShootUserWidgetController;
	
	
	UPROPERTY(EditDefaultsOnly)
	float BaseCrossHairOffest = 3;
	UPROPERTY(EditDefaultsOnly)
	float AimingOffest= -3;
	
	UPROPERTY(EditDefaultsOnly)
	float AirOffest = 3;
	UPROPERTY(EditDefaultsOnly)
	float MoveOffest = 1;

	
	virtual void DrawHUD() override;
	void DrawCrossHair();
	
	UShootUserWidgetController  * GetShootUserWidgetController(const  FWidgetControllerParams & InWCP);
};
