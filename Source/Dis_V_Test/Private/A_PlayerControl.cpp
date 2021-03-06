// Fill out your copyright notice in the Description page of Project Settings.

#include "A_PlayerControl.h"

// Sets default values
AA_PlayerControl::AA_PlayerControl()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AA_PlayerControl::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AA_PlayerControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AA_PlayerControl::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

