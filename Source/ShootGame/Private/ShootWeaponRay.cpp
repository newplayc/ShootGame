// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootWeaponRay.h"

#include "AbilitySystemInterface.h"
#include "EnemyInterface.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "ShootBlueprintFunctionLibrary.h"
#include "Engine/OverlapResult.h"
#include "Kismet/KismetMathLibrary.h"


bool AShootWeaponRay::Fire(const FVector_NetQuantize& FireImpact)
{
	if(!Super::Fire(FireImpact))return false;
	
	FVector  MuzzleLocation =  WeaponMesh->GetSocketLocation(GetMuzzleSocketName());
	FVector SpawnRotation  = UKismetMathLibrary::GetDirectionUnitVector(MuzzleLocation , FireImpact);
	
	FVector End = MuzzleLocation + SpawnRotation * RayLength;
	
	float HalfHieght = RayLength / 2.f;
	FVector Center = MuzzleLocation + HalfHieght * SpawnRotation;
	
	TArray<FOverlapResult>OverlapResults;
	FCollisionShape CollisionShape = FCollisionShape::MakeCapsule(DamageRadio , HalfHieght);
	
	FCollisionObjectQueryParams QueryParams;
	QueryParams.AddObjectTypesToQuery(ECC_Pawn);
	FQuat Quat  = FRotationMatrix::MakeFromZ(SpawnRotation).ToQuat();
	
	FEffectParams EffectParams = MakeDefaultEffectParam();
	SpawnElecrtic(MuzzleLocation , SpawnRotation , End);

	
	GetWorld()->OverlapMultiByObjectType(OverlapResults ,
		Center ,
		Quat,
		QueryParams,
		CollisionShape
		);

	CanFire = false;
	GetWorld()->GetTimerManager().SetTimer(FireDelayTimer , this , &AShootWeapon::SetCanFire ,FireDelay ,false);

	
	for(const  FOverlapResult & Target : OverlapResults)
	{
		if(Target.GetActor()->Implements<UEnemyInterface>())
		{
			if(IAbilitySystemInterface * AbilitySystemInterface = Cast<IAbilitySystemInterface>(Target.GetActor()))
			{
				EffectParams.TargetASC.AddUnique(AbilitySystemInterface->GetAbilitySystemComponent());
			}
		}
	}


	UShootBlueprintFunctionLibrary::ApplyEffectParams(EffectParams);
	return true;
}


void AShootWeaponRay::SpawnElecrtic_Implementation(const FVector_NetQuantize& MuzzleLocation,
	const FVector_NetQuantize& SpawnRotation, const FVector_NetQuantize& End)
{
	UNiagaraComponent * RayNiagare  =  UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld() , RayNiagara , MuzzleLocation ,SpawnRotation.Rotation());
	RayNiagare->SetVectorParameter(FName("Beam Start") , MuzzleLocation);
	RayNiagare->SetVectorParameter(FName("Beam End") , End);
}


