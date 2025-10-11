// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletBase.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemInterface.h"
#include "EnemyInterface.h"
#include "NiagaraFunctionLibrary.h"
#include "ShootAttributeSet.h"
#include "ShootBlueprintFunctionLibrary.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ShootGame/ShootGameplayTags.h"

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
	if(OtherActor == GetOwner())
	{
		return;
	}
	if(OtherActor->Implements<UEnemyInterface>())
	{
		if(IAbilitySystemInterface * AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor))
		{
			EffectParams.TargetASC = AbilitySystemInterface->GetAbilitySystemComponent();
			
			FName IncomingDamageName = FName( UShootAttributeSet::GetInComingDamageAttribute().GetName());
			FName HitBoneName =  IEnemyInterface::Execute_GetNearBoneWithBullet(OtherActor , SweepResult.ImpactPoint);
			float Damage = EffectParams.BodyDamage.GetDamage(HitBoneName);\
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

