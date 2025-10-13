// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShootHud.h"
#include "GameFramework/Actor.h"
#include "ShootWeapon.generated.h"

class UWidgetComponent;
class UStaticMeshComponent;
class USphereComponent;


DECLARE_DELEGATE_OneParam(FRepAmmo , int32);

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
	static FName GetMuzzleSocketName(){return FName("Muzzle");};
	void PlayBulletEmptyAudio()const;
	virtual bool Fire(const FVector_NetQuantize& FireImpact);
	void PlayReloadAudio() const;
	USkeletalMeshComponent * GetMesh(){return WeaponMesh;};
	
	UFUNCTION(NetMulticast, Unreliable)
	void Multicast_Fire();

	UFUNCTION(NetMulticast ,Reliable)
	void SetSimulatePhysic(bool IsSim);
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly)
	FAimCrossHair WeaponAimCrossHair;

	int32 GetAmmo() const{return Ammo;};
	int32 GetMaxAmmo()const {return MaxAmmo;}
	
	FRepAmmo OnRepAmmoChange;

	bool IsFullAmmo() const {return MaxAmmo == Ammo;}
	
	// 填满这把武器需要多少子弹
	int32 NeedFullAmmo()const {return MaxAmmo - Ammo;}
	
	// 填充子弹
	void AddAmmo(int32 Ammos);
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
	class UNiagaraComponent * FireEffect;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAudioComponent * FireAudio;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAudioComponent * BulletEmpty;

	UPROPERTY(VisibleAnywhere , BlueprintReadOnly)
	UAudioComponent * RelLoadComponent;
	
	UPROPERTY(EditDefaultsOnly)
	int32 MaxAmmo = 30;
	
	UPROPERTY(ReplicatedUsing=On_RepAmmo ,EditDefaultsOnly)
	int32 Ammo =  MaxAmmo;
	
	UFUNCTION()
	void On_RepAmmo(const int32& oldAmmo) const;
	
	void SpendAmmo();
private:
	
	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32  OtherBodyIndex, bool  bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
