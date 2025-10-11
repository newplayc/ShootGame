// Fill out your copyright notice in the Description page of Project Settings.


#include "AShootGameMode.h"

#include "GameFramework/Character.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"


void AAShootGameMode::PlayerElim(ACharacter* DCharacter, APlayerController* DController)
{
	if(!DCharacter || ! DController)return;
	DCharacter->Reset();
	DCharacter->Destroy();
	
}

void AAShootGameMode::ReLifePlayer(APlayerController* RPlayerController)
{
	TArray<AActor*>Actors;
	UGameplayStatics::GetAllActorsOfClass(this , APlayerStart::StaticClass() , Actors);
	if(Actors.IsEmpty())
	{
		UE_LOG(LogTemp ,  Warning , TEXT("No PlayerStart"));
		return;
	}
	int32 Ran = FMath::RandRange(0 , Actors.Num()-1);
	RestartPlayerAtPlayerStart(RPlayerController , Actors[Ran]);

	
}
