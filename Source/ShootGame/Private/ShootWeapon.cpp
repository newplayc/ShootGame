// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootGame/Public/ShootWeapon.h"
#include "Components/AudioComponent.h"
#include "NiagaraComponent.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "ShootGame/Public/ShootGameCharacter.h"

AShootWeapon::AShootWeapon()
{
	PrimaryActorTick.bCanEverTick = false;
	
	bReplicates = true;
	AActor::SetReplicateMovement(true);
	
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	SetRootComponent(WeaponMesh);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	
	WidgetComp =CreateDefaultSubobject<UWidgetComponent>("ShowWidget");
	WidgetComp->SetupAttachment(GetRootComponent());
	WidgetComp->SetVisibility(false);
	
	SphereComp = CreateDefaultSubobject<USphereComponent>("CollisionSphere");
	SphereComp->SetCollisionEnabled(ECollisionEnabled::Type::QueryAndPhysics);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComp->SetGenerateOverlapEvents(true);
	SphereComp->SetupAttachment(WeaponMesh);


	FireEffect = CreateDefaultSubobject<UNiagaraComponent>("FireParticle");
	FireEffect->SetupAttachment(WeaponMesh ,FName("Muzzle"));
	FireEffect->bAutoActivate = false;

	
	FireAudio = CreateDefaultSubobject<UAudioComponent>("FireAudio");
	FireAudio->SetupAttachment(WeaponMesh ,FName("Muzzle"));
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
	
	ENetRole RoleNow = GetLocalRole();
	FString RoleText;
	switch (RoleNow)
	{
	case ROLE_Authority :
		RoleText = "Role Authority";
		break;
	case ROLE_AutonomousProxy :
		RoleText = "Role Autonomous Proxy";
		break;
	case ROLE_SimulatedProxy :
		RoleText = "Role Simulated Proxy";
		break;
		default:
		break;
	}
	UE_LOG(LogTemp  , Warning , TEXT("Im %s") , *RoleText);
	switch (NowWeaponState)
	{
	case EWeaponState::Picked :
		SphereComp->SetCollisionResponseToChannel(ECC_Pawn , ECR_Ignore);
		WidgetComp->SetVisibility(false);
		break;
	case EWeaponState::Spare :
		SphereComp->SetCollisionResponseToChannel(ECC_Pawn , ECR_Overlap);
		WidgetComp->SetVisibility(false);
		break;
	case EWeaponState::Touched:
		WidgetComp->SetVisibility(true);
		break;
	case  EWeaponState::Equipped :
		SphereComp->SetCollisionResponseToChannel(ECC_Pawn , ECR_Ignore);
		WidgetComp->SetVisibility(false);
		break;
	default: ;
	}
}


void AShootWeapon::SetWeaponState(EWeaponState NewWeaponState , AShootGameCharacter * TouchCharacter)
{
	NowWeaponState = NewWeaponState;
	ChangeWeaponState();	
}

FTransform AShootWeapon::GetWeaponMeshHandSocket() const
{
	return WeaponMesh->GetSocketTransform(FName("LeftHandSocket") , RTS_World);
}

void AShootWeapon::Fire(const FVector_NetQuantize& FireImpact)
{
	FireEffect->Activate(true);
	FireAudio->Activate(true);
	if (HasAuthority())
	{
		Multicast_Fire();
	}
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
}


void AShootWeapon::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent,
                                        AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                        const FHitResult& SweepResult)
{
	if (AShootGameCharacter * GameCharacter = Cast<AShootGameCharacter>(OtherActor))
	{
		GameCharacter->SetTouchWeapon(this);
	}
}


void AShootWeapon::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (AShootGameCharacter * GameCharacter = Cast<AShootGameCharacter>(OtherActor))
	{
		if (GameCharacter->GetTouchWeapon() == this)
		{
			GameCharacter->SetTouchWeapon(nullptr);
		}
	}
}


