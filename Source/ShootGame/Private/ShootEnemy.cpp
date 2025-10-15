// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootEnemy.h"


AShootEnemy::AShootEnemy()
{
	PrimaryActorTick.bCanEverTick = false;


	AiPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>("AiPerceptionComp");
}

void AShootEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void AShootEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

