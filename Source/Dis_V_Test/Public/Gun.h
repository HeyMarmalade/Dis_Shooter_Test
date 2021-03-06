// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class DIS_V_TEST_API AGun : public AActor
{
	GENERATED_BODY()
	
	UAnimSequence *Anim;
public:	
	// Sets default values for this actor's properties
	AGun();

	void ShootGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* Mesh;
	
	UPROPERTY(EditAnywhere)
		UParticleSystem * PartShot;
	UPROPERTY(EditAnywhere)
		UParticleSystem * BulletHit;

	UPROPERTY(EditAnywhere)
		float MaxRange = 1000;

	UPROPERTY(EditAnywhere)
		float Damage = 10;
};
