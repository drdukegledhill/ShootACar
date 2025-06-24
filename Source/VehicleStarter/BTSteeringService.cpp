// Fill out your copyright notice in the Description page of Project Settings.

#include "BTSteeringService.h"
#include <EngineUtils.h>
#include <BehaviorTree/BlackboardComponent.h>
#include "StarterWheeledVehiclePawn.h"
#include "AIWheeledVehicleController.h"

void UBTSteeringService::OnGameplayTaskActivated(UGameplayTask & task)
{
	
}

void UBTSteeringService::OnGameplayTaskDeactivated(UGameplayTask & task)
{
}

void UBTSteeringService::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	UWorld* world = OwnerComp.GetWorld();

	TActorIterator<AStarterWheeledVehiclePawn> PlayerPawnIter(world);

	PlayerPawn = *PlayerPawnIter;

	if (PlayerPawn)
	{
		APawn* OwnerPawn;// = OwnerComp.GetOwner();
		AAIWheeledVehicleController* AIVehicle = Cast<AAIWheeledVehicleController>(OwnerComp.GetAIOwner());
		OwnerPawn = AIVehicle->GetPawn();

		FVector ForwardVector = OwnerPawn->GetActorForwardVector();
		FVector RightVector = OwnerPawn->GetActorRightVector();
		FVector PlayerLocation = PlayerPawn->GetActorLocation();
		FVector TargetDirection = PlayerLocation - OwnerPawn->GetActorLocation();

		float Distance = FVector::DistSquared(PlayerLocation, OwnerPawn->GetActorLocation());
		float Throttle = FMath::Clamp<float>(0.0f, 1.0f, Distance / 5000.0f);

		TargetDirection.Normalize(1.05f);

		float AngleValue = FVector::DotProduct(ForwardVector, TargetDirection);
		float RightValue = FVector::DotProduct(RightVector, TargetDirection);

		float SteerValue = 0.0f; //-RightValue;// < 0.0f ? 1.0f - AngleValue : -1.0f + AngleValue;
		
		if (RightValue < 0.0f)
		{
			SteerValue = AngleValue < 0.0f ? -1.0f : RightValue;
		}
		else
		{
			SteerValue = AngleValue < 0.0f ? 1.0f : RightValue;
		}

		AIVehicle->BlackboardComp->SetValueAsVector("PlayerLocation", OwnerPawn->GetActorLocation());
		AIVehicle->BlackboardComp->SetValueAsFloat("SteeringValue", SteerValue);
		AIVehicle->BlackboardComp->SetValueAsFloat("ThrottleValue", AngleValue < 0 ? -.8f : Throttle);
	}
}
