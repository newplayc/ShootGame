// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletBase.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

ABulletBase::ABulletBase()
{
	PrimaryActorTick.bCanEverTick = false;

	bReplicates = true;
	SetReplicatingMovement(true);
	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
	RootComponent = BulletMesh;


	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	BoxCollision->SetupAttachment(RootComponent);
	
	ProMovement = CreateDefaultSubobject<UProjectileMovementComponent>("ProMovementComponent");
	
}

void ABulletBase::BeginPlay()
{
	Super::BeginPlay();
	
	
}

void ABulletBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

