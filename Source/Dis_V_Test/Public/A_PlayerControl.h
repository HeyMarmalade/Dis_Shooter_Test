// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "A_PlayerControl.generated.h"

UCLASS()
class DIS_V_TEST_API AA_PlayerControl : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AA_PlayerControl();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	private:
		void MoveForward(float AxisValue);
		void LookUp(float AxisValue);

};
