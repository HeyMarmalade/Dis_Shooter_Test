// Fill out your copyright notice in the Description page of Project Settings.

#include "V_PlayerControl.h"
#include "Gun.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AV_PlayerControl::AV_PlayerControl()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	jumping = false;

}

// Called when the game starts or when spawned
void AV_PlayerControl::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Gun->SetOwner(this);
	
}

bool AV_PlayerControl::IsDead() const
{
	return Health <= 0;
}

// Called every frame
void AV_PlayerControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (jumping)
	{
		Jump();
	}

}

// Called to bind functionality to input
void AV_PlayerControl::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//All Player button inputs
	PlayerInputComponent->BindAxis(("MoveForward"), this, &AV_PlayerControl::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(("MoveRight"), this, &AV_PlayerControl::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &AV_PlayerControl::CheckJump);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &AV_PlayerControl::CheckJump);
	PlayerInputComponent->BindAction(TEXT("ShootGun"), IE_Pressed, this, &AV_PlayerControl::Shoot);
}

float AV_PlayerControl::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	float DamageDealt = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageDealt = FMath::Min(Health, DamageDealt);
	Health -= DamageDealt;
	//UE_LOG(LogTemp, Warning, TEXT("Health left %f"), Health);
	if (IsDead())
	{
		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	return DamageDealt;
}

void AV_PlayerControl::CheckJump()
{
	if (jumping) 
	{
		jumping = false;
	}

	else
	{
		jumping = true;
	}
}

void AV_PlayerControl::MoveForward(float AxisValue) 
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AV_PlayerControl::MoveRight(float AxisValue) 
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AV_PlayerControl::Shoot() 
{
	Gun->ShootGun();
}


