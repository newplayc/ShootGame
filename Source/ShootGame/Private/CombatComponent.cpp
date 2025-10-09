// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatComponent.h"

#include "ShootGameCharacter.h"
#include "ShootGameController.h"
#include "ShootWeapon.h"
#include "Engine/SkeletalMeshSocket.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

#define TRACE_LENGTH 30000


UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCombatComponent::SetController(AShootGameController* InController)
{
	CharacterController = InController;
	
	if(CharacterController)
	if(AShootHud * Hud = Cast<AShootHud>(CharacterController->GetHUD()))
	{
		PlayerHUD = Hud;
	}
}

void UCombatComponent::EquipUpWeapon(AShootWeapon* EquipWeapon)
{
	if (EquipWeapon && OwnerCharacter)
	{
		EquipedWeapon = EquipWeapon;
		if (const USkeletalMeshSocket * MeshSocket =  OwnerCharacter->GetMesh()->GetSocketByName(OwnerCharacter->GetWeaponSocketName()))
		{
			MeshSocket->AttachActor(EquipedWeapon , OwnerCharacter->GetMesh());
			bIsEquiped = true;
			EquipChange();
			EquipedWeapon->SetOwner(OwnerCharacter);
			EquipedWeapon->SetWeaponState(EWeaponState::Equipped);
		}

		
		SetHudParams();
	}
}


void UCombatComponent::SetHudParams()
{
		if(PlayerHUD){	
			PlayerHUD->AimCrossHair = EquipedWeapon->WeaponAimCrossHair;
			PlayerHUD->bDrawAimCrossHair = true;
		}
}



void UCombatComponent::Fire()
{
	if (GEngine && GEngine->GameViewport)
	{
		FVector2D ViewportSize;
		GEngine->GameViewport->GetViewportSize(ViewportSize);
		const FVector2D ScreenPosition(ViewportSize.X/2.0 , ViewportSize.Y / 2.0);

		FVector WorldPosition , WorldDirection;
		UGameplayStatics::DeprojectScreenToWorld(GetWorld()->GetFirstPlayerController() , ScreenPosition , WorldPosition , WorldDirection);
		
		FHitResult Hit;
		FVector StartLocation = WorldPosition + WorldDirection * 500;
		FVector EndLocation = StartLocation + WorldDirection * TRACE_LENGTH;
		GetWorld()->LineTraceSingleByChannel(Hit, StartLocation , EndLocation , ECC_WorldDynamic);
		if(Hit.bBlockingHit == false)
		{
			Hit.ImpactPoint = EndLocation;
		}
		ServerFire(Hit.ImpactPoint);
	}
	
}
void UCombatComponent::ServerFire_Implementation(const FVector_NetQuantize& FireImpact)
{
	if (EquipedWeapon)
	{
		EquipedWeapon->Fire(FireImpact);
	}
}


void UCombatComponent::EquipChange()
{
	if (!OwnerCharacter)return;
	switch (bIsEquiped)
	{
	case true:
		OwnerCharacter->GetCharacterMovement()->bOrientRotationToMovement =false;
		OwnerCharacter->bUseControllerRotationYaw = true;
		break;
	case false:
		OwnerCharacter->GetCharacterMovement()->bOrientRotationToMovement =true;
		OwnerCharacter->bUseControllerRotationYaw = false;
		break;
	}
}

void UCombatComponent::OnRep_Equip()
{
		EquipChange();
}

void UCombatComponent::SetAim(bool NewAim)
{
	bIsAiming = NewAim;
	if(PlayerHUD)
	{
		PlayerHUD->bAim = NewAim;
	}
}


void UCombatComponent::OnRep_EquipWeapon()
{
	EquipedWeapon->SetWeaponState(EWeaponState::Equipped);
}



void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if(PlayerHUD && EquipedWeapon != nullptr)
	{
		PlayerHUD->bInAir = OwnerCharacter->GetMovementComponent()->IsFalling();
		PlayerHUD->bMove = OwnerCharacter->GetCharacterMovement()->Velocity.Length() != 0;
	}
}

void UCombatComponent::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UCombatComponent, bIsEquiped);
	DOREPLIFETIME(UCombatComponent, bIsAiming);
	DOREPLIFETIME(UCombatComponent, EquipedWeapon);
}






