// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootGame/Public/ShootWeapon.h"
#include "Components/AudioComponent.h"
#include "NiagaraComponent.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "Net/UnrealNetwork.h"
#include "ShootGame/Public/ShootGameCharacter.h"


AShootWeapon::AShootWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	NetUpdateFrequency = 100;
	MinNetUpdateFrequency = 66;
	
	bReplicates = true;
	AActor::SetReplicateMovement(true);

	
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	SetRootComponent(WeaponMesh);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::Type::QueryAndPhysics);
	
	WidgetComp =CreateDefaultSubobject<UWidgetComponent>("ShowWidget");
	WidgetComp->SetupAttachment(GetRootComponent());
	WidgetComp->SetVisibility(false);
	
	SphereComp = CreateDefaultSubobject<USphereComponent>("CollisionSphere");
	SphereComp->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComp->SetGenerateOverlapEvents(true);
	SphereComp->SetupAttachment(WeaponMesh);


	FireEffect = CreateDefaultSubobject<UNiagaraComponent>("FireParticle");
	FireEffect->SetupAttachment(WeaponMesh ,FName("Muzzle"));
	FireEffect->bAutoActivate = false;

	
	FireAudio = CreateDefaultSubobject<UAudioComponent>("FireAudio");
	FireAudio->SetupAttachment(WeaponMesh ,FName("Muzzle"));
	FireAudio->bAutoActivate = false;

	BulletEmpty = CreateDefaultSubobject<UAudioComponent>("BulletEmpty");
	BulletEmpty->SetupAttachment(WeaponMesh ,FName("Muzzle"));
	BulletEmpty->bAutoActivate = false;

	RelLoadComponent  = CreateDefaultSubobject<UAudioComponent>("ReloadComponent");
	RelLoadComponent->SetupAttachment(WeaponMesh ,FName("Muzzle"));
	RelLoadComponent->bAutoActivate = false;
}

void AShootWeapon::AddAmmo(const int32 Ammos)
{
	Ammo = FMath::Min(MaxAmmo , Ammos + Ammo);
	OnRepAmmoChange.ExecuteIfBound(Ammo);
}

void AShootWeapon::BeginPlay()
{
	Super::BeginPlay();
	if (HasAuthority())
	{
		SphereComp->SetCollisionResponseToChannel(ECC_Pawn , ECR_Overlap);
		SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnSphereBeginOverlap);
		SphereComp->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnSphereEndOverlap);
	}
}


void AShootWeapon::SetWeaponWidgetVisibility(bool NewVisibility) const
{
	WidgetComp->SetVisibility(NewVisibility);
}


void AShootWeapon::ChangeWeaponState() const
{
	
	switch (NowWeaponState)
	{
	case EWeaponState::Spare :
		SphereComp->SetCollisionResponseToChannel(ECC_Pawn , ECR_Overlap);
		WeaponMesh->SetCollisionResponseToChannel(ECC_Pawn , ECR_Overlap);
		WidgetComp->SetVisibility(false);
		break;
	case EWeaponState::Touched:
		WidgetComp->SetVisibility(true);
		break;
	case  EWeaponState::Equipped :
		SphereComp->SetCollisionResponseToChannel(ECC_Pawn , ECR_Ignore);
		WeaponMesh->SetCollisionResponseToChannel(ECC_Pawn , ECR_Ignore);
		WidgetComp->SetVisibility(false);
		
		break;
	default: ;
	}
}


void AShootWeapon::SetWeaponState(EWeaponState NewWeaponState)
{
	NowWeaponState = NewWeaponState;
	ChangeWeaponState();	
}

FTransform AShootWeapon::GetWeaponMeshHandSocket() const
{
	return WeaponMesh->GetSocketTransform(FName("LeftHandSocket") , RTS_World);
}

void AShootWeapon::PlayBulletEmptyAudio()const
{
	BulletEmpty->Activate();
}

bool AShootWeapon::Fire(const FVector_NetQuantize& FireImpact)
{

	if(Ammo <=0)
	{
		return false;	
	}
	FireEffect->Activate(true);
	FireAudio->Activate(true);
	if (HasAuthority())
	{
		Multicast_Fire();
	}
	return true;
}

void AShootWeapon::PlayReloadAudio() const
{
	RelLoadComponent->Activate();
}

void AShootWeapon::SetSimulatePhysic_Implementation(bool IsSim)
{
	GetMesh()->SetSimulatePhysics(IsSim);	
}


void AShootWeapon::Multicast_Fire_Implementation()
{
	FireEffect->Activate(true);
	FireAudio->Activate(true);
}

void AShootWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AShootWeapon::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(AShootWeapon , Ammo , COND_OwnerOnly);
}

void AShootWeapon::On_RepAmmo(const int32& oldAmmo) const
{
	bool f = OnRepAmmoChange.ExecuteIfBound(Ammo);
}

void AShootWeapon::SpendAmmo()
{
	--Ammo;
	bool f = OnRepAmmoChange.ExecuteIfBound(Ammo);
}

void AShootWeapon::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent,
                                        AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                        const FHitResult& SweepResult)
{
	
	if(static_cast<uint8>(NowWeaponState) > 1) return;
	if (AShootGameCharacter * GameCharacter = Cast<AShootGameCharacter>(OtherActor))
	{
		GameCharacter->SetTouchWeapon(this);
	}
}


void AShootWeapon::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(static_cast<uint8>(NowWeaponState) > 1) return;
	if (AShootGameCharacter * GameCharacter = Cast<AShootGameCharacter>(OtherActor))
	{
		if (GameCharacter->GetTouchWeapon() == this)
		{
			GameCharacter->SetTouchWeapon(nullptr);
		}
	}
}
