// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletBase.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemInterface.h"
#include "EnemyInterface.h"
#include "NiagaraFunctionLibrary.h"
#include "ShootBlueprintFunctionLibrary.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ShootGame/ShootGame.h"
#include "ShootGame/ShootGameplayTags.h"

ABulletBase::ABulletBase()
{
	PrimaryActorTick.bCanEverTick = false;

	bReplicates = true;
	SetReplicatingMovement(true);

	AActor::SetLifeSpan(10.f);

	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	BoxCollision->SetCollisionResponseToAllChannels(ECR_Block);
	BoxCollision->SetupAttachment(RootComponent);
	BoxCollision->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
	BoxCollision->SetCollisionObjectType(ECC_Bullet);
	BoxCollision->SetUseCCD(true);
	BoxCollision->SetGenerateOverlapEvents(false);
	BoxCollision->SetNotifyRigidBodyCollision(true);
	RootComponent = BoxCollision;
	
	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
	BulletMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	BulletMesh->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
	BulletMesh->SetupAttachment(RootComponent);

	
	ProMovement = CreateDefaultSubobject<UProjectileMovementComponent>("ProMovementComponent");
}



void ABulletBase::BeginPlay()
{
	Super::BeginPlay();
	if(HasAuthority())
	{
		BoxCollision->OnComponentHit.AddDynamic(this , &ThisClass::OnHit);
	}
}

void ABulletBase::Destroyed()
{
	if(!HasAuthority())
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld() , HitParticle , GetActorLocation());
	Super::Destroyed();
}




void ABulletBase::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if(OtherActor == GetOwner())
	{
		return;
	}
	if(OtherActor->Implements<UEnemyInterface>())
	{
		if(IAbilitySystemInterface * AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor))
		{
			EffectParams.TargetASC.Add( AbilitySystemInterface->GetAbilitySystemComponent());
			FName HitBoneName =  IEnemyInterface::Execute_GetNearBoneWithBullet(OtherActor , Hit.ImpactPoint);
			float Damage = EffectParams.BodyDamage.GetDamage(HitBoneName);
			FGameplayTag ShootWeapontag = FShootGameplayTags::GetShootTags().ShootWeaponDamageTag;
			UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(EffectParams.ApplyEffect ,ShootWeapontag  , Damage);
			UShootBlueprintFunctionLibrary::ApplyEffectParams(EffectParams);
		}
	}

	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld() , HitParticle , GetActorLocation());
	Destroy();
}

void ABulletBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

