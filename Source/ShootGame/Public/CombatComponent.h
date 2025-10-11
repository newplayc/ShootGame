// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


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
	
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,FActorComponentTickFunction* ThisTickFunction) override;
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(Server, Reliable)
	void ServerFire(const FVector_NetQuantize & FireImpact);
	
	UPROPERTY(Replicated, ReplicatedUsing=OnRep_Equip)
	bool bIsEquiped;

	UFUNCTION()
	void OnRep_Equip();
	
	UPROPERTY(Replicated)
	bool bIsAiming;
	
	UFUNCTION()
	void OnRep_EquipWeapon();

	void SetHudParams();
private:

	UPROPERTY(ReplicatedUSing  = OnRep_EquipWeapon)
	AShootWeapon * EquipedWeapon =  nullptr;
	AShootGameCharacter * OwnerCharacter = nullptr;
	AShootGameController * CharacterController =  nullptr;
	AShootHud  * PlayerHUD = nullptr;
	void EquipChange();
};
