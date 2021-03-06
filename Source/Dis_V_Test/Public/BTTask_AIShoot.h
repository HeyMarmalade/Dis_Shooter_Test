// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_AIShoot.generated.h"

/**
 * 
 */
UCLASS()
class DIS_V_TEST_API UBTTask_AIShoot : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTask_AIShoot();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory);
};
