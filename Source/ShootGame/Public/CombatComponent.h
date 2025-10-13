// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"

DECLARE_DELEGATE_OneParam(FOnAmmoChange , int32);

class AShootHud;
class AShootGameController;
class AShootGameCharacter;
class AShootWeapon;




UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SHOOTGAME_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UCombatComponent();
	void SetCharacter(AShootGameCharacter * InOwnerCharacter){OwnerCharacter = InOwnerCharacter; }
	void SetController(AShootGameController * InController);
	void EquipUpWeapon(AShootWeapon * EquipWeapon);
	void Fire();
	AShootWeapon * GetEquipWeapon() const{return EquipedWeapon;}
	bool GetIsEquipped() const {return bIsEquiped;}
	bool GetIsAim() const {return bIsAiming;}
	void SetAim(bool NewAim);
	bool GetIsReLoad() const {return bIsReLoad;}
	FOnAmmoChange OnAmmoChange;
	FOnAmmoChange OnMaxAmmoChange;

	void DropWeapon();
	
	UFUNCTION(Server , Reliable)
	void ServerReloadAmmo();

	UFUNCTION(Server ,Reliable)
	void ServerDropWeapon();
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,FActorComponentTickFunction* ThisTickFunction) override;
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	void ReLoadTimerFinish();
	
	UFUNCTION(Client ,Reliable)
	void ReLoadFinish();
	
	UFUNCTION(Server, Reliable)
	void ServerFire(const FVector_NetQuantize & FireImpact);
	
	UPROPERTY(Replicated, ReplicatedUsing=OnRep_Equip)
	bool bIsEquiped = false;

	UFUNCTION()
	void OnRep_Equip() const;
	
	UPROPERTY(Replicated)
	bool bIsAiming = false;

	UPROPERTY(EditDefaultsOnly)
	float ReLoadTime = 2.f;
	
	UPROPERTY(Replicated)
	bool bIsReLoad = false;
	
	UFUNCTION()
	void OnRep_EquipWeapon( AShootWeapon * OldWeapon) const;

	void SetHudParams() const;

	UFUNCTION(Client , Reliable)
	void FailFire();
	
	
	UFUNCTION()
	void WeaponRep(int32 Ammo) const;

	UPROPERTY( ReplicatedUsing = On_RepAmmoCapacity  , EditDefaultsOnly)
	int32 AmmoCapacity;

	UFUNCTION()
	void On_RepAmmoCapacity(const int32 & OldAmmoCapacity) const;
	
private:
	UPROPERTY(ReplicatedUSing  = OnRep_EquipWeapon)
	AShootWeapon * EquipedWeapon =  nullptr;
	
	AShootGameCharacter * OwnerCharacter = nullptr;
	AShootGameController * CharacterController =  nullptr;
	AShootHud  * PlayerHUD = nullptr;
	void EquipChange() const;
	FTimerHandle ReLoadTimerHandle;
	int32 SpendAmmo= 0;
	
};
