// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/AIPerceptionComponent.h"
#include "ShootEnemy.generated.h"

class UAISense_Sight;

UCLASS()
class SHOOTGAME_API AShootEnemy : public ACharacter
{
	GENERATED_BODY()
public:
	
	AShootEnemy();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere , BlueprintReadOnly ,Category = "AI|PawSensing")
	TObjectPtr<UAIPerceptionComponent> AiPerceptionComponent;


	UPROPERTY(VisibleAnywhere , BlueprintReadOnly ,Category = "AI|PawSensing")
	TObjectPtr<UAISense_Sight>SenseSight;

	
public:	
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
