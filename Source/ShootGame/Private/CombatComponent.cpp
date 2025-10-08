// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatComponent.h"

#include "AudioMixerDevice.h"
#include "EdGraphUtilities.h"
#include "ShootGameCharacter.h"
#include "ShootWeapon.h"
#include "Engine/SkeletalMeshSocket.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

#define TRACE_LENGTH 80000


UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
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
			EquipedWeapon->SetWeaponState(EWeaponState::Equipped, OwnerCharacter);
			
		}
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
		FVector EndLocation = WorldPosition + WorldDirection * TRACE_LENGTH;
		GetWorld()->LineTraceSingleByChannel(Hit, WorldPosition , EndLocation , ECC_WorldDynamic);
		
		ServerFire(Hit.TraceEnd);
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
}


void UCombatComponent::OnRep_EquipWeapon()
{
	EquipedWeapon->SetWeaponState(EWeaponState::Equipped, OwnerCharacter);
}

void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
}

void UCombatComponent::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UCombatComponent, bIsEquiped);
	DOREPLIFETIME(UCombatComponent, bIsAiming);
	DOREPLIFETIME(UCombatComponent, EquipedWeapon);
}






