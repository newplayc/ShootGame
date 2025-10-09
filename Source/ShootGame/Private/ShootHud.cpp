// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootHud.h"


void AShootHud::DrawHUD()
{
	Super::DrawHUD();
	if(bDrawAimCrossHair)
	{
		DrawCrossHair();
	}
}

void AShootHud::DrawCrossHair()
{
	if(!GEngine)return;
	FVector2D ScreenSize;
	GEngine->GameViewport->GetViewportSize(ScreenSize);

	
	FVector2D ScreenCenter(ScreenSize.X / 2.f ,  ScreenSize.Y  /2.f);
	float AllOffest = BaseCrossHairOffest;
	if(bAim) AllOffest += AimingOffest;
	if(bMove)AllOffest += MoveOffest;
	if(bInAir)AllOffest += AirOffest;

	
	if(AimCrossHair.CenterText)
	{
		FVector2D DrawLoc;
		DrawLoc.X = ScreenCenter.X  - (AimCrossHair.CenterText->GetSizeX() / 2);
		DrawLoc.Y = ScreenCenter.Y - (AimCrossHair.CenterText->GetSizeY() / 2);
		DrawTexture(
			AimCrossHair.CenterText,
			DrawLoc.X,
			DrawLoc.Y,
			AimCrossHair.CenterText->GetSizeX(),
			AimCrossHair.CenterText->GetSizeY(),
			0,
			0,
			1,
			1,
			AimCrossHair.DrawColor
			);
	}

	
	if(AimCrossHair.UpTexture)
	{
		FVector2D DrawLoc;
		DrawLoc.X = ScreenCenter.X - (AimCrossHair.UpTexture->GetSizeX() / 2.f);
		DrawLoc.Y = ScreenCenter.Y - (AimCrossHair.UpTexture->GetSizeY() / 2.f);
		//DrawLoc.Y = ScreenCenter.Y - AimCrossHair.UpTexture->GetSizeY();

		
		DrawTexture(
			AimCrossHair.UpTexture,
			DrawLoc.X,
			DrawLoc.Y - AllOffest,
			AimCrossHair.UpTexture->GetSizeX(),
			AimCrossHair.UpTexture->GetSizeY(),
			0,
			0,
			1,
			1,
			AimCrossHair.DrawColor
			);
	}
	if(AimCrossHair.DownTexture)
	{
		FVector2D DrawLoc;
		DrawLoc.X = ScreenCenter.X - (AimCrossHair.DownTexture->GetSizeX() / 2.f);
		DrawLoc.Y = ScreenCenter.Y - (AimCrossHair.DownTexture->GetSizeY() /2.f);
		//DrawLoc.Y = ScreenCenter.Y;
		DrawTexture(
		AimCrossHair.DownTexture,
		DrawLoc.X,
		DrawLoc.Y + AllOffest,
		AimCrossHair.DownTexture->GetSizeX(),
		AimCrossHair.DownTexture->GetSizeY(),
		0,
		0,
		1,
		1,
		AimCrossHair.DrawColor
		);
	}
	if(AimCrossHair.LeftTexture)
	{
		FVector2D DrawLoc;
		DrawLoc.X = ScreenCenter.X - (AimCrossHair.LeftTexture->GetSizeX() / 2.f);
		//DrawLoc.X = ScreenCenter.X - AimCrossHair.LeftTexture->GetSizeX();
		DrawLoc.Y = ScreenCenter.Y - (AimCrossHair.LeftTexture->GetSizeY() / 2);
		
		DrawTexture(
		AimCrossHair.LeftTexture,
		DrawLoc.X - AllOffest,
		DrawLoc.Y,
		AimCrossHair.LeftTexture->GetSizeX() ,
		AimCrossHair.LeftTexture->GetSizeY(),
		0,
		0,
		1,
		1,
		AimCrossHair.DrawColor
		);
	}
	
	if(AimCrossHair.RightTexture)
	{
		FVector2D DrawLoc;
		DrawLoc.X = ScreenCenter.X - AimCrossHair.RightTexture->GetSizeX() /2.f;
		// DrawLoc.X = ScreenCenter.X;
		DrawLoc.Y = ScreenCenter.Y - (AimCrossHair.RightTexture->GetSizeY() / 2.f);

		
		DrawTexture(
		AimCrossHair.RightTexture,
		DrawLoc.X + AllOffest,
		DrawLoc.Y,
		AimCrossHair.RightTexture->GetSizeX(),
		AimCrossHair.RightTexture->GetSizeY(),
		0,
		0,
		1,
		1,
		AimCrossHair.DrawColor
		);
	}
}