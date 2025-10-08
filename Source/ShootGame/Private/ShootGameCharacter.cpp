// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootGame/Public/ShootGameCharacter.h"

#include "CombatComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Net/UnrealNetwork.h"
#include "ShootGame/Public/ShootWeapon.h"


AShootGameCharacter::AShootGameCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;
	AActor::SetReplicateMovement(true);


	NetUpdateFrequency = 100;
	MinNetUpdateFrequency = 40;
	
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("Spring Arm Component");
	SpringArmComp->SetupAttachment(GetMesh());
	SpringArmComp->bUsePawnControlRotation = true;
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComp->SetupAttachment(SpringArmComp);
	CameraComp->bUsePawnControlRotation = false;

	CombatComp = CreateDefaultSubobject<UCombatComponent>("CombatComponent");
	CombatComp->SetIsReplicated(true);
	
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->bUseControllerDesiredRotation = false;
}


void AShootGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AShootGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetAOffest(DeltaTime);
	
}

void AShootGameCharacter::SetTouchWeapon(AShootWeapon* NewTouchWeapon)
{
	if (NewTouchWeapon == TouchWeapon)return;
	if (IsLocallyControlled())
	{
		if (TouchWeapon)
		{
			TouchWeapon->SetWeaponState(EWeaponState::Spare, nullptr);
		}
		if (NewTouchWeapon)
		{
			NewTouchWeapon->SetWeaponState(EWeaponState::Touched, this);
		}
	}
	TouchWeapon = NewTouchWeapon;
}

void AShootGameCharacter::ServerAim_Implementation(bool NewAim)
{
	if (CombatComp && CombatComp->GetIsEquipped())
	{
		CombatComp->SetAim(NewAim);	
	}
}

FTransform AShootGameCharacter::GetWeaponLeftHandSocket() const
{
	if (!CombatComp || !CombatComp->GetIsEquipped()) return FTransform();
	FTransform  LeftHand  =  CombatComp->GetEquipWeapon()->GetWeaponMeshHandSocket();
	FVector OutLocation;
	FRotator OutRotation;
	GetMesh()->TransformToBoneSpace(FName("hand_r") , LeftHand.GetLocation() , LeftHand.GetRotation().Rotator() , OutLocation , OutRotation);
	
	return FTransform(OutRotation , OutLocation , FVector());
}

void AShootGameCharacter::Fire()
{
	if (CombatComp && CombatComp->GetIsEquipped())
	{
		ServerFire();
		CombatComp->Fire();
	}
}

void AShootGameCharacter::PlayMontage_Implementation()
{
	FName SectionName = GetIsAim() ? FName("Ironsights") : FName("Hip");
	PlayAnimMontage(FireMontage , 1 , SectionName);
	
}

void AShootGameCharacter::ServerFire_Implementation()
{
	PlayMontage();
}


void AShootGameCharacter::Aim(bool NewAim)
{
	if (CombatComp && CombatComp->GetIsEquipped())
	{
		CombatComp->SetAim(NewAim);
	}
	if (!HasAuthority())
	{
		ServerAim(NewAim);
	}
}

void AShootGameCharacter::EquipWeapon()
{
	if (CombatComp && TouchWeapon)
	{
		if (HasAuthority())
		{
			auto temp = TouchWeapon;
			TouchWeapon = nullptr;
			CombatComp->EquipUpWeapon(temp);
		}
		else
		{
			EquipWeaponOnServer();
		}
	}
}

void AShootGameCharacter::EquipWeaponOnServer_Implementation()
{
	if (CombatComp  && TouchWeapon)
	{
		auto temp = TouchWeapon;
		TouchWeapon = nullptr;
		CombatComp->EquipUpWeapon(temp);
	}
}



void AShootGameCharacter::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(AShootGameCharacter , TouchWeapon , COND_OwnerOnly);
	//DOREPLIFETIME(AShootGameCharacter , AO_Yaw);
	DOREPLIFETIME_CONDITION(AShootGameCharacter , AimRotation ,COND_SimulatedOnly);
}

void AShootGameCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	CombatComp->SetCharacter(this);
}


void AShootGameCharacter::OnRep_TouchWeapon(AShootWeapon* LastWeapon)
{
	if (LastWeapon == TouchWeapon)return;
	if (LastWeapon)
	{
		LastWeapon->SetWeaponState(EWeaponState::Spare, nullptr);
	}
	if (TouchWeapon)
	{
		TouchWeapon->SetWeaponState(EWeaponState::Touched,  this);
	}
}

void AShootGameCharacter::GetAOffest(float DeltaTime)
{
	if (!CombatComp || !CombatComp->GetIsEquipped()){return;}
	
	bUseControllerRotationYaw = GetVelocity().Length() != 0;
	
	if (bUseControllerRotationYaw)
	{
		//AO_Yaw = 0;
		TurnState = ETurnState::NoTurning;
		return;
	}


	if (IsLocallyControlled() || HasAuthority())
	{
		AimRotation =  GetBaseAimRotation();
	}
	
	FRotator MeshRotation = UKismetMathLibrary::MakeRotFromX(GetActorForwardVector());
	
	AO_Yaw = UKismetMathLibrary::NormalizedDeltaRotator(AimRotation , MeshRotation).Yaw;
	AO_Pitch = GetBaseAimRotation().Pitch;

	
	if (!bUseControllerRotationYaw)
	{
		if (AO_Yaw > 90.f){
			TurnState = ETurnState::TurnRight;}
		else if (AO_Yaw < -90.f){
			TurnState = ETurnState::TurnLeft;
		}
		else
		{
			TurnState = ETurnState::NoTurning;
		}
	}
	
	if (AO_Pitch > 90.f && !IsLocallyControlled())
	{
		FVector2D InRange(270.f ,360.f);
		FVector2D OutRange(-90.f, 0.f);
		AO_Pitch = FMath::GetMappedRangeValueClamped(InRange,OutRange,AO_Pitch);
	}
	
}

