// Fill out your copyright notice in the Description page of Project Settings.

/*  Adapted: Sam's Pattuzzi's Code (GameDev/Udemy) for creating these Task
*/
#include "BTTask_ClearBlackboardValue.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_ClearBlackboardValue::UBTTask_ClearBlackboardValue()
{
	NodeName = TEXT("Clear Blackboard Value");
}

EBTNodeResult::Type UBTTask_ClearBlackboardValue::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());


	return EBTNodeResult::Succeeded;
}
