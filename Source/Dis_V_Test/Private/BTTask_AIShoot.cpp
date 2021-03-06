// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_AIShoot.h"
#include "AIController.h"
#include "V_PlayerControl.h"

UBTTask_AIShoot::UBTTask_AIShoot()
{
	NodeName = "Shoot";
}

EBTNodeResult::Type UBTTask_AIShoot::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	AV_PlayerControl* Character = Cast<AV_PlayerControl>(OwnerComp.GetAIOwner()->GetPawn());
	if (Character == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	Character->Shoot();

	return EBTNodeResult::Succeeded;
}
