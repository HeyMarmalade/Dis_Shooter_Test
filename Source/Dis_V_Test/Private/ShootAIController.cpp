// Fill out your copyright notice in the Description page of Project Settings.

#include "ShootAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "BehaviorTree/BlackboardComponent.h"

void AShootAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AITree != nullptr)
	{
		//gets variables values
		RunBehaviorTree(AITree);
		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	}
}

void AShootAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}

	