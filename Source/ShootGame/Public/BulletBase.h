// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShootWeaponFire.h"
#include "GameFramework/Actor.h"
#include "BulletBase.generated.h"




UCLASS()
class SHOOTGAME_API ABulletBase : public AActor
{
	GENERATED_BODY()
public:	
	ABulletBase();
	
	FEffectParams EffectParams;

protected:
	
	virtual void BeginPlay() override;
	
	virtual void Destroyed() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr< UStaticMeshComponent> BulletMesh; 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UBoxComponent> BoxCollision;
	
	UPROPERTY(VisibleAnywhere,  BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UProjectileMovementComponent>ProMovement;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class UNiagaraSystem>HitParticle;
	
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
public:	
	virtual void Tick(float DeltaTime) override;

};
 