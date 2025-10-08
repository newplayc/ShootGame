// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiPlayerGameMode.h"
#include "GameFramework/GameStateBase.h"
void AMultiPlayerGameMode::PostLogin(APlayerController* NewPlayer)
{
	
	Super::PostLogin(NewPlayer);
	if (GameState)
	{
		int numPlayer = GameState->PlayerArray.Num();
		GEngine->AddOnScreenDebugMessage(-1 , 5.f , FColor::Red , FString::Printf(TEXT("Hey im PostLogIn Num of player %d ") , numPlayer));
		if (numPlayer > 1)
		{
			bUseSeamlessTravel = true;
			GetWorld()->ServerTravel("Game/Maps/GameMap1?listen");
		}
		
	}
}

void AMultiPlayerGameMode::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId,
	FString& ErrorMessage)
{
	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
	GEngine->AddOnScreenDebugMessage(-1 ,5.f , FColor::Red , FString::Printf(TEXT( " Hey im GameMode PreLogIn : Options : %s , Address : %s , ErrorMessage : %s"),
		*Options , *Address , *ErrorMessage));
}
