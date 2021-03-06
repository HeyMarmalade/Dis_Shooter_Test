// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_PlayerSeen.generated.h"

/**
 * 
 */
UCLASS()
class DIS_V_TEST_API UBTService_PlayerSeen : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTService_PlayerSeen();
protected:
	virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds);
};

