// Fill out your copyright notice in the Description page of Project Settings.


#include "VehicleStarterGameModeBase.h"
#include "StarterWheeledVehiclePawn.h"

AVehicleStarterGameModeBase::AVehicleStarterGameModeBase()
{
	DefaultPawnClass = AStarterWheeledVehiclePawn::StaticClass();
}