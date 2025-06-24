// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIWheeledVehicleController.generated.h"

/**
 * 
 */
UCLASS()
class VEHICLESTARTER_API AAIWheeledVehicleController : public AAIController
{
	GENERATED_BODY()

public:

	class UChaosVehicleMovementComponent* VehicleMovementComp;
	class UBehaviorTreeComponent* BehaviorTreeComp;
	class UBlackboardComponent* BlackboardComp;

public:

	AAIWheeledVehicleController();

	virtual void OnPossess(APawn* InPawn) override;

	virtual void Tick(float DeltaSeconds) override;
	
};
