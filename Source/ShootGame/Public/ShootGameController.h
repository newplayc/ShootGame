// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShootGameController.generated.h"

struct FInputActionValue;
class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class SHOOTGAME_API AShootGameController : public APlayerController
{
	GENERATED_BODY()


protected:
	
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputMappingContext> MappingContext;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> MoveInputAction;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> TurnInputAction;

private:
	void Move(const FInputActionValue& InputActionValue) ;
	void Turn(const FInputActionValue& InputActionValue);
};
