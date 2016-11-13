// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "GameFramework/GameMode.h"
#include "TestTwinStickGameMode.generated.h"


UCLASS(minimalapi)
class ATestTwinStickGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ATestTwinStickGameMode();
	
	

	void Tick(float DeltaTime);
};



