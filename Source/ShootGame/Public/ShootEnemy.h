// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "EnemyInterface.h"
#include "GameplayTagContainer.h"

#include "GameFramework/Character.h"
#include "ShootEnemy.generated.h"

class UMotionWarpingComponent;
class UShootAttributeSet;
class UShootAbilitySystemComponent;
class UAISenseConfig_Sight;
class UBehaviorTree;


USTRUCT(BlueprintType)
struct FAttackMontageInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly)
	UAnimMontage * AttackMontage;

	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly)
	FGameplayTag MontageAttackTag;

	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly)
	FName DamageSocketName;
	
};

UCLASS()
class SHOOTGAME_API AShootEnemy : public ACharacter  , public IAbilitySystemInterface , public IEnemyInterface
{
	GENERATED_BODY()
public:
	
	AShootEnemy();
	
	virtual UAbilitySystemComponent * GetAbilitySystemComponent() const override;
	
	UFUNCTION(BlueprintCallable)
	const TArray<FAttackMontageInfo> & GetAttackMontages() const {return AttackMontages;}

	
	virtual bool IsDead_Implementation() override{return bIsDead;}

	virtual FName GetNearBoneWithBullet_Implementation(const FVector_NetQuantize& HitLocation) override;

	UPROPERTY(EditDefaultsOnly ,Category="Ai")
	TArray<FName>BoneHitName;
	
	virtual  void UpdateMotionWarp_Implementation(FVector TargetLocation) override;
	
	UFUNCTION(NetMulticast , Reliable)
	virtual void PlayReactMontage() override;

	
	void Died_Implementation();
	
	UPROPERTY()
	AActor * AttackedActor = nullptr;
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere , BlueprintReadOnly , Category = "Ai")
	TObjectPtr<UShootAbilitySystemComponent>AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere , BlueprintReadOnly , Category = "Ai")
	TObjectPtr<UShootAttributeSet>AttributeSet;
	
	UPROPERTY(EditDefaultsOnly , Category="Ai")
	TObjectPtr<UBehaviorTree>BehaviorTree;
	
	UPROPERTY(EditDefaultsOnly ,Category ="Ai")
	TObjectPtr<UAISenseConfig_Sight>aiSense_Sight;

	UPROPERTY(EditDefaultsOnly ,Category= "Ai")
	TObjectPtr<UMotionWarpingComponent>MotionWarpingComponent;
	
	bool bIsDead = false;
	
	virtual void PossessedBy(AController* NewController) override;
	
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly , Category="Ai")
	TArray<FAttackMontageInfo>AttackMontages;

	UPROPERTY(EditDefaultsOnly ,BlueprintReadOnly , Category ="Ai")
	UAnimMontage * ReactMontage;

	UFUNCTION(BlueprintImplementableEvent)
	void DissolveStart();
	
	UPROPERTY(EditDefaultsOnly ,Category="Ai")
	UMaterialInstance * DissolveMesh;

	
};
