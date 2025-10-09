// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ShootHud.generated.h"

/**
 * 
 */


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
	
protected:


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
	
};
