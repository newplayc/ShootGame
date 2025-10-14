// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatComponent.h"

#include "ShootGameCharacter.h"
#include "ShootGameController.h"
#include "ShootUserWidgetController.h"
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
	{
		if(AShootHud * Hud = Cast<AShootHud>(CharacterController->GetHUD()))
		{
			PlayerHUD = Hud;
		}
	}
	
}

void UCombatComponent::EquipUpWeapon(AShootWeapon* EquipWeapon)
{
	if (EquipWeapon && OwnerCharacter)
	{
		EquipedWeapon = EquipWeapon;
		if (const USkeletalMeshSocket * MeshSocket =  OwnerCharacter->GetMesh()->GetSocketByName(OwnerCharacter->GetWeaponSocketName()))
		{
			EquipedWeapon->GetMesh()->SetSimulatePhysics(false);
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
		if(PlayerHUD)
		{	
			PlayerHUD->AimCrossHair = EquipedWeapon->WeaponAimCrossHair;
			PlayerHUD->bDrawAimCrossHair = true;
			PlayerHUD->GetShootUserWidgetController()->OnAmmoChanged.Broadcast(EquipedWeapon->GetAmmo());
			PlayerHUD->GetShootUserWidgetController()->OnMaxAmmoChanged.Broadcast(AmmoCapacity);
			PlayerHUD->GetShootUserWidgetController()->OnWeaponIconChange.Broadcast(EquipedWeapon->GetIcon());
			
			EquipedWeapon->OnRepAmmoChange.BindUObject(this , &ThisClass::WeaponRep);
			DefaultFOV = OwnerCharacter->GetFoV();
		}
}


void UCombatComponent::ServerReloadAmmo_Implementation()
{
	if(AmmoCapacity <=0 || EquipedWeapon->IsFullAmmo())return;

	bIsReLoad  =true;
	
	const int32 NA = EquipedWeapon->NeedFullAmmo();
	
	if(AmmoCapacity >= NA){
		SpendAmmo = NA;
	}
	else{
		SpendAmmo = AmmoCapacity; 
	}
	if(OwnerCharacter)
	{
		OwnerCharacter->PlayReLoadMontage();
	}
	
	ReLoadFinish();
	GetWorld()->GetTimerManager().SetTimer(ReLoadTimerHandle,this , &ThisClass::ReLoadTimerFinish , ReLoadTime , false);
}

void UCombatComponent::WeaponRep(const int32 Ammo) const
{
	if(PlayerHUD)
	{
		PlayerHUD->GetShootUserWidgetController()->OnAmmoChanged.Broadcast(Ammo);
	}
}

void UCombatComponent::On_RepAmmoCapacity(const int32 & OldAmmoCapacity) const
{
	if(PlayerHUD )
	{
		PlayerHUD->GetShootUserWidgetController()->OnMaxAmmoChanged.Broadcast(AmmoCapacity);
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
		if(!EquipedWeapon->Fire(FireImpact)){
			FailFire();
			return;
		}
		if(OwnerCharacter)
		OwnerCharacter->PlayFireMontage();
	}
}

void UCombatComponent::ReLoadFinish_Implementation()
{
	if(EquipedWeapon)
	{
		EquipedWeapon->PlayReloadAudio();
	}
}



void UCombatComponent::FailFire_Implementation()
{
	EquipedWeapon->PlayBulletEmptyAudio();
}


void UCombatComponent::EquipChange() const
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

void UCombatComponent::OnRep_Equip() const
{
	EquipChange();
}

void UCombatComponent::SetAim(const bool NewAim)
{
	bIsAiming = NewAim;
	if(PlayerHUD)
	{
		if(bIsAiming)
		{
			DefaultFOV = OwnerCharacter->GetFoV();
			OwnerCharacter->SetFoV(EquipedWeapon->GetAimFoV());
		}
		else
		{
			OwnerCharacter->SetFoV(DefaultFOV);
		}
		
		PlayerHUD->bAim = NewAim;
	}
}

void UCombatComponent::OnRep_EquipWeapon( AShootWeapon * OldWeapon) const
{
	if(OldWeapon!=nullptr)
	{
		OldWeapon->GetMesh()->SetSimulatePhysics(true);
		OldWeapon->GetMesh()->SetEnableGravity(true);
		OldWeapon->SetWeaponState(EWeaponState::Spare);	
	}
	if(EquipedWeapon !=nullptr)
	{
		EquipedWeapon->GetMesh()->SetSimulatePhysics(false);
		EquipedWeapon->SetWeaponState(EWeaponState::Equipped);	
	}
	
}

void UCombatComponent::ServerDropWeapon_Implementation()
{
	EquipedWeapon->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	EquipedWeapon->SetOwner(nullptr);
	EquipedWeapon->GetMesh()->SetSimulatePhysics(true);
	EquipedWeapon->GetMesh()->SetEnableGravity(true);
	EquipedWeapon->SetWeaponState(EWeaponState::Spare);
	
	bIsEquiped = false;
	EquipChange();

	EquipedWeapon = nullptr;
	bIsAiming = false;
}

void UCombatComponent::DropWeapon()
{
	
	if(PlayerHUD){
		EquipedWeapon->OnRepAmmoChange.Unbind();
		PlayerHUD->GetShootUserWidgetController()->OnAmmoChanged.Broadcast(0);
		PlayerHUD->bDrawAimCrossHair = false;
		PlayerHUD->GetShootUserWidgetController()->OnWeaponIconChange.Broadcast(nullptr);
		bIsEquiped = false;
		OwnerCharacter->SetFoV(DefaultFOV);
		EquipChange();
	}
	ServerDropWeapon();
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
	DOREPLIFETIME(UCombatComponent , bIsReLoad);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatComponent , AmmoCapacity ,COND_OwnerOnly , REPNOTIFY_OnChanged);
}

void UCombatComponent::ReLoadTimerFinish()
{
	EquipedWeapon->AddAmmo(SpendAmmo);
	AmmoCapacity -= SpendAmmo;
	if(PlayerHUD )
	{
		PlayerHUD->GetShootUserWidgetController()->OnMaxAmmoChanged.Broadcast(AmmoCapacity);
	}
	bIsReLoad = false;
}







