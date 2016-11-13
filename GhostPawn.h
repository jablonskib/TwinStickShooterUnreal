// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "TestTwinStickPawn.h"
#include "GhostPawn.generated.h"

UENUM()
enum class EGhostTypes : uint8
{
	SMALL,
	LARGE
};

UCLASS()
class TESTTWINSTICK_API AGhostPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGhostPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
	float speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
	int32 health;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
	bool isAlive;

	int32 damageAmount;
	
	int32 randomType;
	FVector pointBetween;
	void DestroyFromContact();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
	EGhostTypes ghostType;

	ATestTwinStickPawn* pawn;
	UFUNCTION()
	void OnActorCollide(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
};
