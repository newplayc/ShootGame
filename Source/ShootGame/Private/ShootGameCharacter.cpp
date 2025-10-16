// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootGame/Public/ShootGameCharacter.h"

#include "AbilitySystemComponent.h"
#include "AShootGameMode.h"
#include "CombatComponent.h"
#include "ShootAbilitySystemComponent.h"
#include "ShootAttributeSet.h"
#include "ShootGameController.h"
#include "ShootPlayerState.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Net/UnrealNetwork.h"
#include "ShootGame/ShootGame.h"
#include "ShootGame/Public/ShootWeapon.h"
#include "Windows/WindowsApplication.h"


AShootGameCharacter::AShootGameCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	
	bReplicates = true;
	AActor::SetReplicateMovement(true);

	GetMesh()->SetCollisionResponseToChannel(ECC_Camera , ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_Bullet , ECR_Block);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
	GetMesh()->SetGenerateOverlapEvents(false);
	
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera , ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Bullet , ECR_Ignore);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
	GetCapsuleComponent()->SetGenerateOverlapEvents(true);

	
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


void AShootGameCharacter::PlayReLoadMontage_Implementation()
{
	FName SectionName = GetIsAim() ? FName("Ironsights") : FName("Hip");
	PlayAnimMontage(ReLoadMontage , 1 , SectionName);
}

void AShootGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	BoneHitName.Add(FName("Head"));
	BoneHitName.Add(FName("spine_03"));
	BoneHitName.Add(FName("pelvis"));
}

void AShootGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetAOffest(DeltaTime);
	if(IsLocallyControlled())
	{
		double Dis =  UKismetMathLibrary::Vector_Distance(CameraComp->GetComponentLocation() , GetActorLocation());
		GetMesh()->SetVisibility(Dis >= 80);
	}
	
}

void AShootGameCharacter::SetTouchWeapon(AShootWeapon* NewTouchWeapon)
{
	if (NewTouchWeapon == TouchWeapon)return;
	if (IsLocallyControlled())
	{
		if (TouchWeapon)
		{
			TouchWeapon->SetWeaponState(EWeaponState::Spare);
		}
		if (NewTouchWeapon)
		{
			NewTouchWeapon->SetWeaponState(EWeaponState::Touched);
		}
	}
	TouchWeapon = NewTouchWeapon;
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

void AShootGameCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilityInfo();
}

void AShootGameCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilityInfo();
	
}

void AShootGameCharacter::InitAttributes()
{
	checkf(EffetToInit , TEXT("Please Check Character Effect Init"));
	
	ASC->ApplyEffectToInit(EffetToInit , 1 , this);
}

void AShootGameCharacter::InitAbilityInfo()
{
	
	if(AShootPlayerState * PS = Cast<AShootPlayerState>(GetPlayerState()))
	{
		ASC = Cast<UShootAbilitySystemComponent>(PS->GetAbilitySystemComponent());
		AS =  Cast<UShootAttributeSet>(PS->GetAttributes());
		
		if(ASC)
		{
			ASC->InitAbilityActorInfo(PS , this);
		}
	}

	
	if(HasAuthority())
	{
		InitAttributes();
	}
	if(APlayerController * PC =  Cast<APlayerController>(GetController()))
	{
		if(AShootHud * HUD = Cast<AShootHud>(PC->GetHUD()))
		{
			HUD->InitGameWidget(ASC , AS);	
		}
	}
}

bool AShootGameCharacter::GetIsReLoad() const
{
	if(CombatComp && CombatComp->GetIsEquipped())
	{
		return CombatComp->GetIsReLoad();
	}
	return false;
}


void AShootGameCharacter::ReSpawnPlayer()
{

	APlayerController * PlayerController = Cast<APlayerController>(GetController());
	if(AAShootGameMode * GameMode = Cast<AAShootGameMode>( UGameplayStatics::GetGameMode(this)))
	{
		GameMode->PlayerElim(this , PlayerController);
		GameMode->ReLifePlayer(PlayerController);
	}
}

void AShootGameCharacter::Died_Implementation()
{
	bDead = true;
	PlayDeathMontage();
	GetCharacterMovement()->StopMovementImmediately();
	GetCharacterMovement()->DisableMovement();
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle , this , &ThisClass::ReSpawnPlayer , 3,false);
	if(IsLocallyControlled())
	{
		DropWeapon();
	}
}




void AShootGameCharacter::On_RepDead()
{
	if(IsLocallyControlled())
	{
		DropWeapon();
	}
}

void AShootGameCharacter::Fire()
{
	
	if (CombatComp && CombatComp->GetIsEquipped() && !CombatComp->GetIsReLoad())
	{
		CombatComp->Fire();
	}
}


void AShootGameCharacter::PlayFireMontage_Implementation()
{
	FName SectionName = GetIsAim() ? FName("Ironsights") : FName("Hip");
	if(bIsCrouched)
		PlayAnimMontage(CrouchFireMontage , 1, SectionName);
	else
	PlayAnimMontage(FireMontage , 1 , SectionName);
	
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



void AShootGameCharacter::ServerAim_Implementation(bool NewAim)
{
	if (CombatComp && CombatComp->GetIsEquipped())
	{
		CombatComp->SetAim(NewAim);	
	}
}



void AShootGameCharacter::EquipWeapon()
{
	if (CombatComp && TouchWeapon)
	{
		auto temp = TouchWeapon;
		TouchWeapon = nullptr;
		CombatComp->EquipUpWeapon(temp);
	}
}


void AShootGameCharacter::ReLoadAmmo()
{
	if(CombatComp && CombatComp->GetIsEquipped())
	{
		CombatComp->ServerReloadAmmo();
	}
}


void AShootGameCharacter::DropWeapon()
{
	if(CombatComp && CombatComp->GetIsEquipped())
	{
		CombatComp->DropWeapon();
	}
}


void AShootGameCharacter::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(AShootGameCharacter , TouchWeapon , COND_OwnerOnly);
	DOREPLIFETIME(AShootGameCharacter , bDead);
	DOREPLIFETIME_CONDITION(AShootGameCharacter , AimRotation ,COND_SimulatedOnly);
}




void AShootGameCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	CombatComp->SetCharacter(this);
}

void AShootGameCharacter::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();
	if(CombatComp && IsLocallyControlled())
	{
		CombatComp->SetController(Cast<AShootGameController>(GetController()));
	}
}

UAbilitySystemComponent* AShootGameCharacter::GetAbilitySystemComponent() const
{
	if(ASC)return ASC;
	if(AShootPlayerState * PS = Cast<AShootPlayerState>(GetPlayerState()))
	{
		return PS->GetAbilitySystemComponent();
	}
	return nullptr;
}

UAttributeSet* AShootGameCharacter::GetAttribute() const
{
	if(AShootPlayerState * PS = Cast<AShootPlayerState>(GetPlayerState()))
	{
		return PS->GetAttributes();
	}
	return nullptr;
}

FName AShootGameCharacter::GetNearBoneWithBullet_Implementation(const FVector_NetQuantize &  HitLocation)
{
	FName RetName;
	float MinDis = 999999999.f;
	for(const FName & Bone : BoneHitName)
	{
		FVector BoneLocation = GetMesh()->GetBoneLocation(Bone);
		float dis = FVector::Distance(BoneLocation , HitLocation);
		if(dis < MinDis)
		{
			RetName = Bone;
			MinDis = dis;
		}
	}
	return RetName;
}


bool AShootGameCharacter::IsDead_Implementation()
{
	return bDead;
}


void AShootGameCharacter::PlayReactMontage_Implementation()
{
	PlayAnimMontage(ReactMontage , 1);
	
}

void AShootGameCharacter::PlayDeathMontage_Implementation()
{
	PlayAnimMontage(DeathMontage , 1);
}


void AShootGameCharacter::OnRep_TouchWeapon(AShootWeapon* LastWeapon) const
{
	if (LastWeapon == TouchWeapon)return;
	if (LastWeapon)
	{
		LastWeapon->SetWeaponState(EWeaponState::Spare);
	}
	if (TouchWeapon)
	{
		TouchWeapon->SetWeaponState(EWeaponState::Touched);
	}
}

void AShootGameCharacter::GetAOffest(float DeltaTime)
{
	if (!CombatComp || !CombatComp->GetIsEquipped()){return;}
	
	bUseControllerRotationYaw = GetVelocity().Length() != 0;
	
	if (bUseControllerRotationYaw || GetCharacterMovement()->IsFalling())
	{
		AO_Yaw  =0;
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
			FRotator Rotator(GetActorRotation().Pitch, AimRotation.Yaw , GetActorRotation().Roll);
			SetActorRotation(Rotator);
			TurnState = ETurnState::TurnRight;
		}
		else if (AO_Yaw < -90.f){
			FRotator Rotator(GetActorRotation().Pitch, AimRotation.Yaw , GetActorRotation().Roll);
			SetActorRotation(Rotator);
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

