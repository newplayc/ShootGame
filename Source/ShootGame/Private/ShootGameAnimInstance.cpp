// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootGame/Public/ShootGameAnimInstance.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "ShootGame/Public/ShootGameCharacter.h"


void UShootGameAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	NowCharacter = Cast<AShootGameCharacter>(TryGetPawnOwner());
}

void UShootGameAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (!NowCharacter){NowCharacter = Cast<AShootGameCharacter>(TryGetPawnOwner());}
	if (NowCharacter)
	{
		bIsFalling = NowCharacter->GetCharacterMovement()->IsFalling();
		bIsAccelerated = NowCharacter->GetCharacterMovement()->GetCurrentAcceleration().Length() > 0;
		Velocity = NowCharacter->GetCharacterMovement()->Velocity.Length();
		bIsEquipped = NowCharacter->GetIsEquip();
		bIsCrouch = NowCharacter->bIsCrouched;
		bIsAiming = NowCharacter->GetIsAim();
		
		// 摄像机方向 和 速度方向 做差值
		FRotator AimRotator = NowCharacter->GetBaseAimRotation();
		FRotator VelocityRotator = UKismetMathLibrary::MakeRotFromX(NowCharacter->GetCharacterMovement()->Velocity);
		float YawoffestNew = UKismetMathLibrary::NormalizedDeltaRotator(VelocityRotator, AimRotator).Yaw;
		YawOffest = UKismetMathLibrary::FInterpTo(YawOffest , YawoffestNew, DeltaSeconds, 10.f);

		
		AO_Yaw = UKismetMathLibrary::FInterpTo(AO_Yaw ,NowCharacter->GetAoYaw() , DeltaSeconds, 10.f);
		AO_Pitch = UKismetMathLibrary::FInterpTo(AO_Pitch , NowCharacter->GetAoPitch() , DeltaSeconds, 10.f);
		WeaponLeftHandTransform = NowCharacter->GetWeaponLeftHandSocket();
	}
}
