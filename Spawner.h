// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class TESTTWINSTICK_API ASpawner : public AActor
{
	GENERATED_BODY()
	
private:
	int32 randomSpawn;
public:	
	// Sets default values for this actor's properties
	ASpawner();

	UPROPERTY(EditAnywhere, Category = "Spawn Info")
		TArray<AActor*> spawnPoints;

	UPROPERTY(EditAnywhere, Category = "Spawn Info")
		float timeToSpawn;

	float timeElapsed;

	FRandomStream* random;

	TSubclassOf<class AGhostPawn> ghosts;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
