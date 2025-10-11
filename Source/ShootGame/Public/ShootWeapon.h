// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShootHud.h"
#include "GameFramework/Actor.h"
#include "ShootWeapon.generated.h"

class UWidgetComponent;
class UStaticMeshComponent;
class USphereComponent;

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
	
	virtual void Fire(const FVector_NetQuantize& FireImpact);

	UFUNCTION(NetMulticast, Unreliable)
	void Multicast_Fire();

	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly)
	FAimCrossHair WeaponAimCrossHair;
	
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

private:
	
	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32  OtherBodyIndex, bool  bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
