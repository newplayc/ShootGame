


// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootEnemy.h"
#include "EnemyAiController.h"
#include "MotionWarpingComponent.h"
#include "ShootAbilitySystemComponent.h"
#include "ShootAttributeSet.h"
#include "ShootBlueprintFunctionLibrary.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"


AShootEnemy::AShootEnemy()
{
	PrimaryActorTick.bCanEverTick = false;
	aiSense_Sight = CreateDefaultSubobject<UAISenseConfig_Sight>("AiSenseSight");
	aiSense_Sight->SightRadius = 500.f;
	aiSense_Sight->DetectionByAffiliation.bDetectEnemies = true;
	aiSense_Sight->DetectionByAffiliation.bDetectFriendlies = true;
	aiSense_Sight->DetectionByAffiliation.bDetectNeutrals = true;
	aiSense_Sight->LoseSightRadius = 100.f;

	AbilitySystemComponent  = CreateDefaultSubobject<UShootAbilitySystemComponent>("AbilitySystemCom");
	AttributeSet = CreateDefaultSubobject<UShootAttributeSet>("Attributes");
	MotionWarpingComponent = CreateDefaultSubobject<UMotionWarpingComponent>("Motion Warp");
	
}

UAbilitySystemComponent* AShootEnemy::GetAbilitySystemComponent() const
{
	 return AbilitySystemComponent;
}


void AShootEnemy::PlayReactMontage_Implementation()
{
	PlayAnimMontage(ReactMontage);
}

void AShootEnemy::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	UShootBlueprintFunctionLibrary::InitEnemy(this);
	
}

void AShootEnemy::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	AEnemyAiController * AiController  =  Cast<AEnemyAiController>(GetController());
	AiController->RunBehaviorTree(BehaviorTree);
	AiController->GetAIPerceptionComponent()->ConfigureSense(*aiSense_Sight);
	AiController->GetAIPerceptionComponent()->SetDominantSense(UAISense_Sight::StaticClass());
}




FName AShootEnemy::GetNearBoneWithBullet_Implementation(const FVector_NetQuantize &  HitLocation)
{
	FName RetName;
	float MinDis = 999999999.f;
	for(const FName & Bone : BoneHitName)
	{
		FVector BoneLocation = GetMesh()->GetBoneLocation(Bone);
		float dis = FVector::Distance(BoneLocation , HitLocation);
		if(dis < MinDis)
		{
			RetName = Bone;
			MinDis = dis;
		}
	}
	return RetName;
}


void AShootEnemy::UpdateMotionWarp_Implementation(FVector TargetLocation)
{
	MotionWarpingComponent->AddOrUpdateWarpTargetFromLocation(FName("FacingTarget") , TargetLocation);
}

void AShootEnemy::Died_Implementation()
{
	DissolveStart();
	SetLifeSpan(1.5);
}
