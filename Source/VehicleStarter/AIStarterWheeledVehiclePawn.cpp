// Fill out your copyright notice in the Description page of Project Settings.


#include "AIStarterWheeledVehiclePawn.h"
#include "ChaosWheeledVehicleMovementComponent.h"
#include "StarterVehicleFrontWheel.h"
#include "StarterVehicleRearWheel.h"
#include "UObject/ConstructorHelpers.h"

AAIStarterWheeledVehiclePawn::AAIStarterWheeledVehiclePawn()
{
	// Car mesh
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> CarMesh(TEXT("/Game/Vehicles/SportsCar/SKM_SportsCar"));
	GetMesh()->SetSkeletalMesh(CarMesh.Object);
	GetMesh()->SetSimulatePhysics(true);

	static ConstructorHelpers::FClassFinder<UObject> AnimBPClass(TEXT("/Game/Vehicles/SportsCar/SportsCar_AnimBP"));
	GetMesh()->SetAnimInstanceClass(AnimBPClass.Class);

	// Simulation
	UChaosWheeledVehicleMovementComponent* Vehicle4W = CastChecked<UChaosWheeledVehicleMovementComponent>(GetVehicleMovement());

	FChaosWheelSetup Wheel_Setup;

	Wheel_Setup.AdditionalOffset = FVector(0.0f, 0.0f, 0.0f);
	Wheel_Setup.WheelClass = UStarterVehicleFrontWheel::StaticClass();

	Wheel_Setup.BoneName = FName("Phys_Wheel_FL");
	Vehicle4W->WheelSetups.Add(Wheel_Setup);

	Wheel_Setup.BoneName = FName("Phys_Wheel_FR");
	Vehicle4W->WheelSetups.Add(Wheel_Setup);

	Wheel_Setup.WheelClass = UStarterVehicleRearWheel::StaticClass();
	Wheel_Setup.BoneName = FName("Phys_Wheel_BL");
	Vehicle4W->WheelSetups.Add(Wheel_Setup);

	Wheel_Setup.BoneName = FName("Phys_Wheel_BR");
	Vehicle4W->WheelSetups.Add(Wheel_Setup);
}

void AAIStarterWheeledVehiclePawn::Tick(float Delta)
{
	Super::Tick(Delta);
}

void AAIStarterWheeledVehiclePawn::BeginPlay()
{
	Super::BeginPlay();
}
