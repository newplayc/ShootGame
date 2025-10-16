// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootGame/Public/ShootGameController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AShootGameController::BeginPlay()
{
	Super::BeginPlay();
	
	check(MappingContext);
	check(MoveInputAction);
	check(TurnInputAction);
	
	if (auto EnhancedInputPlayerSub =  ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		EnhancedInputPlayerSub->AddMappingContext(MappingContext,0);	
	}
}

void AShootGameController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent * EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveInputAction ,ETriggerEvent::Triggered,this,&AShootGameController::Move);
	EnhancedInputComponent->BindAction(TurnInputAction ,ETriggerEvent::Triggered,this,&AShootGameController::Turn);
}

void AShootGameController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D V2d  = InputActionValue.Get<FVector2D>();
	FRotator URotator =  FRotator(0 , GetControlRotation().Yaw,0);
	const FVector ForwardVector = FRotationMatrix(URotator).GetUnitAxis(EAxis::X);
	const FVector RightVector = FRotationMatrix(URotator).GetUnitAxis(EAxis::Y);


	float Delta =  GetWorld()->DeltaTimeSeconds;
	
	if (GetPawn())
	{
		GetPawn()->AddMovementInput(ForwardVector ,1 / Delta *  V2d.Y);
		GetPawn()->AddMovementInput(RightVector ,1 / Delta *  V2d.X);
	}
}

void AShootGameController::Turn(const FInputActionValue& InputActionValue)
{
	const FVector2D V2d  = InputActionValue.Get<FVector2D>();

	AddYawInput( V2d.X);
	AddPitchInput(V2d.Y);
}


