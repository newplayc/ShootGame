// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletBase.generated.h"

UCLASS()
class SHOOTGAME_API ABulletBase : public AActor
{
	GENERATED_BODY()
public:	
	ABulletBase();
	
protected:
	
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UStaticMeshComponent> BulletMesh; 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UBoxComponent> BoxCollision;
	
	UPROPERTY(VisibleAnywhere,  BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UProjectileMovementComponent>ProMovement;

	

public:	
	virtual void Tick(float DeltaTime) override;

};
