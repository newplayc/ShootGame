// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "CombatComponent.h"
#include "GameFramework/Character.h"
#include "ShootGameCharacter.generated.h"

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
class SHOOTGAME_API AShootGameCharacter : public ACharacter
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
	UFUNCTION(BlueprintCallable)
	void Fire();

	
	UFUNCTION(NetMulticast ,Reliable)
	void PlayMontage();

	UFUNCTION(Server, Reliable)
	void ServerFire();
	
	UFUNCTION(BlueprintCallable)
	void Aim(bool NewAim);

	UFUNCTION(Server, Reliable)
	void ServerAim(bool NewAim);
	
	UFUNCTION(BlueprintCallable)
	void EquipWeapon();
	
	UFUNCTION(Server , Reliable)
	void EquipWeaponOnServer();

	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostInitializeComponents() override;
	virtual void NotifyControllerChanged() override;
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

	
	UFUNCTION()
	void OnRep_TouchWeapon(AShootWeapon * LastTouchWeapon) const;

	
	UPROPERTY(Replicated)
	FRotator AimRotation;

	
	float AO_Yaw;
	float AO_Pitch;
	
	void GetAOffest(float DeltaTime);

	
private:
	
};
