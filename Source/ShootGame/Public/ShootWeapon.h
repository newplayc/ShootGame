// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "ShootHud.h"
#include "GameFramework/Actor.h"
#include "ShootWeapon.generated.h"

class UAbilitySystemComponent;
class UWidgetComponent;
class UStaticMeshComponent;
class USphereComponent;

DECLARE_DELEGATE_OneParam(FRepAmmo , int32);

USTRUCT(BlueprintType)
struct FBodyDamage
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly)
	float Head;

	UPROPERTY(EditDefaultsOnly)
	float Up;
	
	UPROPERTY(EditDefaultsOnly)
	float Down;
	
	float GetDamage(FName BoneName)
	{
		if(BoneName == "Head")
		{
			return Head;
		}
		if(BoneName == "spine_03")
		{
			return Up;
		}
		if(BoneName == "pelvis")
		{
			return Down;
		}
		return 0;
	}

};


USTRUCT(BlueprintType)
struct FEffectParams
{
	GENERATED_BODY()
	FEffectParams() = default;
	
	UPROPERTY()
	UAbilitySystemComponent * SoucreASC;

	UPROPERTY()
	 TArray<UAbilitySystemComponent *>  TargetASC;
	
	UPROPERTY()
	FGameplayEffectSpecHandle ApplyEffect;

	UPROPERTY()
	FBodyDamage BodyDamage;
};

UENUM(BlueprintType)
enum class EWeaponState : uint8
{
	Spare UMETA(DisplayName = "Spare"),
	Touched UMETA(DisplayName = "Touched"),
	Picked UMETA(DisplayName = "Picked"),
	Equipped UMETA(DisplayName = "Equipped")
};


UCLASS()
class SHOOTGAME_API AShootWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AShootWeapon();
	void SetWeaponWidgetVisibility(bool NewVisibility) const;
	void ChangeWeaponState() const;
	void SetWeaponState(EWeaponState NewWeaponState);

	
	FTransform GetWeaponMeshHandSocket()const;
	
	virtual  FName GetMuzzleSocketName(){return FName("Muzzle");};
	virtual bool Fire(const FVector_NetQuantize& FireImpact);
	
	USkeletalMeshComponent * GetMesh(){return WeaponMesh;};
	UTexture2D * GetIcon()const {return WeaponIcon;}
	
	float GetAimFoV(){return AimFOV;}

	UFUNCTION(NetMulticast, Reliable)
	virtual void  Multicast_Fire();

	
	UFUNCTION(NetMulticast ,Reliable)
	void SetSimulatePhysic(bool IsSim);

	
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly , Category="Weapon")
	FAimCrossHair WeaponAimCrossHair;

	int32 GetAmmo() const{return Ammo;};
	int32 GetMaxAmmo()const {return MaxAmmo;}
	
	FRepAmmo OnRepAmmoChange;

	bool IsFullAmmo() const {return MaxAmmo == Ammo;}
	
	// 填满这把武器需要多少子弹
	int32 NeedFullAmmo()const {return MaxAmmo - Ammo;}
	// 填充子弹
	void AddAmmo(int32 Ammos);
	
	void PlayBulletEmptyAudio()const;
	
	void PlayReloadAudio() const;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USphereComponent>SphereComp;

	UPROPERTY(VisibleAnywhere , BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> WidgetComp;
	
	EWeaponState NowWeaponState;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAudioComponent * BulletEmpty;

	UPROPERTY(VisibleAnywhere , BlueprintReadOnly)
	UAudioComponent * RelLoadComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UNiagaraComponent * FireEffect;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAudioComponent * FireAudio;
	
	
	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	UTexture2D * WeaponIcon;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	float AimFOV;

	UPROPERTY(EditDefaultsOnly,Category="Weapon")
	int32 MaxAmmo = 30;
	
	UPROPERTY(ReplicatedUsing=On_RepAmmo ,EditDefaultsOnly,Category="Weapon")
	int32 Ammo =  MaxAmmo;
	
	UPROPERTY(EditDefaultsOnly ,Category="Weapon")
	TSubclassOf<class UGameplayEffect>DamageEffect;
	
	UPROPERTY(EditDefaultsOnly)
	FBodyDamage BodyDamage;
	
	UFUNCTION()
	void On_RepAmmo(const int32& oldAmmo) const;
	
	void SpendAmmo();
	
	virtual FEffectParams MakeDefaultEffectParam() const;
private:
	
	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32  OtherBodyIndex, bool  bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
