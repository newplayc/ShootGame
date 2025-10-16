// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAiController.generated.h"

class UBehaviorTreeComponent;
/**
 * 
 */
UCLASS()
class SHOOTGAME_API AEnemyAiController : public AAIController
{
	GENERATED_BODY()
public:
	
	AEnemyAiController();

	virtual void BeginPlay() override;
	
};
