// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShootAIController.generated.h"

/**
 * 
 */
UCLASS()
class DIS_V_TEST_API AShootAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaSeconds) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		class UBehaviorTree* AITree;
	/*UPROPERTY(EditAnywhere)
		float SightRadius = 200f;
		*/
};
