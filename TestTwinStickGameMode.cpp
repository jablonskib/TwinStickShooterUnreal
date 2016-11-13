// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "TestTwinStick.h"
#include "Engine.h"
#include "Ghost.h"
#include "TestTwinStickGameMode.h"
#include "TestTwinStickPawn.h"

ATestTwinStickGameMode::ATestTwinStickGameMode()
{
	
	// set default pawn class to our character class
	DefaultPawnClass = ATestTwinStickPawn::StaticClass();
}

void ATestTwinStickGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

	
}

