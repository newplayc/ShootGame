// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAiController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Chaos/ChaosPerfTest.h"
#include "Perception/AIPerceptionComponent.h"


AEnemyAiController::AEnemyAiController()
{
	Blackboard = CreateDefaultSubobject<UBlackboardComponent>("BlackComp");
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>("AiPerceptionComp");
}

void AEnemyAiController::BeginPlay()
{
	Super::BeginPlay();
	
}
