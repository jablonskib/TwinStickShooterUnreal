// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WidgetBlueprint.h"
#include "GameHUDWidget.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TESTTWINSTICK_API UGameHUDWidget : public UWidgetBlueprint
{
	GENERATED_BODY()
	
	UGameHUDWidget();

public:
	int32 score;
	
	
};
