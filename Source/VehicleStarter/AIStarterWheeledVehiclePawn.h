// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "BehaviorTree/BehaviorTree.h"
#include "AIStarterWheeledVehiclePawn.generated.h"

/**
 * 
 */
UCLASS()
class VEHICLESTARTER_API AAIStarterWheeledVehiclePawn : public AWheeledVehiclePawn
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	UBehaviorTree* BehaviorTree;

public:
	AAIStarterWheeledVehiclePawn();

	// Begin Actor interface
	virtual void Tick(float Delta) override;
protected:
	virtual void BeginPlay() override;

};
