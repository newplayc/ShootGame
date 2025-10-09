// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletBase.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

ABulletBase::ABulletBase()
{
	PrimaryActorTick.bCanEverTick = false;

	bReplicates = true;
	SetReplicatingMovement(true);
	
	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
	RootComponent = BulletMesh;
	BulletMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	BulletMesh->SetCollisionEnabled(ECollisionEnabled::Type::PhysicsOnly);

	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	BoxCollision->SetupAttachment(RootComponent);
	BoxCollision->SetCollisionObjectType(ECC_WorldDynamic);
	
	ProMovement = CreateDefaultSubobject<UProjectileMovementComponent>("ProMovementComponent");
}

void ABulletBase::BeginPlay()
{
	Super::BeginPlay();
	if(HasAuthority())
	{
		BoxCollision->OnComponentBeginOverlap.AddDynamic(this , &ThisClass::OnOverlap);
	}
}

void ABulletBase::Destroyed()
{
	
	if(!HasAuthority())
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld() , HitParticle , GetActorLocation());
	Super::Destroyed();
}




void ABulletBase::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld() , HitParticle , GetActorLocation());

	
	Destroy();
}

void ABulletBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

