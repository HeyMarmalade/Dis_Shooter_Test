// Fill out your copyright notice in the Description page of Project Settings.

#include "Gun.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SkeletalMeshComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject <USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh-> SetupAttachment(Root);
}

void AGun::ShootGun()
{
	UGameplayStatics::SpawnEmitterAttached(PartShot, Mesh, TEXT("MuzzleFlash"));
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr) return;
	AController* OwnerController = OwnerPawn->GetController();
	if (OwnerController == nullptr) return;

	//Gets the location and Rotation of viewpoint
	FVector Location;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(Location, Rotation);
	FVector End = Location + Rotation.Vector() * MaxRange;
	
	
	FHitResult Hit;
	//Bullet kept hitting player, Forums suggested Params, seems to be working perfectly.
	FCollisionQueryParams Params(NAME_None, true, OwnerPawn);
	Params.AddIgnoredActor(this);
	bool bSuccess = GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
	if (bSuccess)
	{
		FVector ShotDirection = -Rotation.Vector();
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), BulletHit , Hit.Location, ShotDirection.Rotation());
		
		AActor* HitActor = Hit.GetActor();
		if(HitActor != nullptr)
		{
			FPointDamageEvent DamEvent(Damage, Hit, ShotDirection, nullptr);
			HitActor->TakeDamage(Damage, DamEvent, OwnerController, this);
		}
	}
}
// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

