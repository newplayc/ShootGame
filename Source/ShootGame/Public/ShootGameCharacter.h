// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "CombatComponent.h"
#include "EnemyInterface.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "ShootGameCharacter.generated.h"

class UGameplayEffect;
class UAttributeSet;
class UCombatComponent;
class AShootWeapon;
class USpringArmComponent;
class UCameraComponent;

UENUM()
enum class ETurnState : uint8
{
	TurnLeft UMETA(DisplayName ="向左转"),
	TurnRight UMETA(DisplayName ="向右转"),
	NoTurning UMETA(DisplayName ="不旋转")
};

UCLASS()
class SHOOTGAME_API AShootGameCharacter : public ACharacter ,public IAbilitySystemInterface ,public IEnemyInterface
{
	GENERATED_BODY()
public:
	
	AShootGameCharacter();
	AShootWeapon *  GetTouchWeapon() const{return TouchWeapon;}
	void SetTouchWeapon(AShootWeapon * NewTouchWeapon);
	static FName GetWeaponSocketName(){return FName("WeaponSocket");}
	bool GetIsEquip()const {return CombatComp->GetIsEquipped();}
	bool GetIsAim()const {return CombatComp->GetIsAim();}
	float GetAoYaw()const {return AO_Yaw;}
	float GetAoPitch()const {return AO_Pitch;}
	ETurnState GetTurnState()const {return TurnState;};
	FTransform GetWeaponLeftHandSocket() const;
	void InitAbilityInfo();
	bool GetIsReLoad() const;
	float GetFoV() const {return CameraComp->FieldOfView;}
	void SetFoV(const float InFoV )  {CameraComp->SetFieldOfView(InFoV);}
	UFUNCTION()
	void ReSpawnPlayer();
	
	void Died();
	
	UPROPERTY(EditDefaultsOnly)
	float ReLifeDelay = 4;
	
	UPROPERTY(Replicated)
	bool bDead;
	
	UFUNCTION(BlueprintCallable)
	void Fire();
	
	UFUNCTION(NetMulticast ,Reliable)
	void PlayFireMontage();
	
	UFUNCTION(BlueprintCallable)
	void Aim(bool NewAim);

	UFUNCTION(Server, Reliable)
	void ServerAim(bool NewAim);
	
	UFUNCTION(BlueprintCallable)
	void EquipWeapon();

	UFUNCTION(BlueprintCallable)
	void ReLoadAmmo();

	UFUNCTION(BlueprintCallable)
	void DropWeapon();
	
	UFUNCTION(Server , Reliable)
	void EquipWeaponOnServer();

	
	virtual UAbilitySystemComponent * GetAbilitySystemComponent() const override;
	UAttributeSet * GetAttribute() const;
	virtual FName GetNearBoneWithBullet_Implementation(const FVector_NetQuantize& HitLocation) override;
	virtual bool IsDead_Implementation() override;
	
	UFUNCTION(NetMulticast , Unreliable)
	void PlayReactMontage();
	
	UFUNCTION(NetMulticast ,Unreliable)
	void PlayDeathMontage();

	UFUNCTION(NetMulticast , Unreliable)
	void PlayReLoadMontage();
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostInitializeComponents() override;
	virtual void NotifyControllerChanged() override;
	virtual  void PossessedBy(AController* NewController) override;
	virtual  void OnRep_PlayerState() override;
	void InitAttributes();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<UCameraComponent>CameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Spring)
	TObjectPtr<USpringArmComponent>SpringArmComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,  Category = CusComp)
	TObjectPtr<UCombatComponent>CombatComp;
	
	UPROPERTY(ReplicatedUsing = OnRep_TouchWeapon)
	AShootWeapon * TouchWeapon;
	
	UPROPERTY()
	ETurnState TurnState = ETurnState::NoTurning;

	UPROPERTY(EditDefaultsOnly)
	UAnimMontage* FireMontage;

	UPROPERTY(EditDefaultsOnly)
	UAnimMontage* CrouchFireMontage;
	
	UPROPERTY(Replicated)
	FRotator AimRotation;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayEffect>EffetToInit;
	
	UFUNCTION()
	void OnRep_TouchWeapon(AShootWeapon * LastTouchWeapon) const;
	
	UPROPERTY(EditDefaultsOnly)
	UAnimMontage * ReactMontage;

	UPROPERTY(EditDefaultsOnly)
	UAnimMontage * DeathMontage;

	UPROPERTY(EditDefaultsOnly)
	UAnimMontage * ReLoadMontage;
	
	void GetAOffest(float DeltaTime);
	float AO_Yaw;
	float AO_Pitch;

private:
	class UShootAbilitySystemComponent * ASC;
	class UShootAttributeSet * AS;
	TArray<FName>BoneHitName;
	
};
