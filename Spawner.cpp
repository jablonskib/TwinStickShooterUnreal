// Fill out your copyright notice in the Description page of Project Settings.

#include "TestTwinStick.h"
#include "Engine.h"
#include "GhostPawn.h"
#include "Spawner.h"


// Sets default values
ASpawner::ASpawner()
{
	randomSpawn = 0;
	timeElapsed = 0;
	static ConstructorHelpers::FObjectFinder<UBlueprint> ghostBlueprint(TEXT("Blueprint'/Game/BP_GhostP.BP_GhostP'"));
	if (ghostBlueprint.Object)
	{
		ghosts = (UClass*)ghostBlueprint.Object->GeneratedClass;
	}
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawner::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	timeElapsed += DeltaTime;

	if (timeElapsed >= timeToSpawn)
	{

		randomSpawn = FMath::RandRange(0, 1);
		
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::FromInt(randomSpawn));
		GetWorld()->SpawnActor<AGhostPawn>(ghosts, spawnPoints[randomSpawn]->GetActorLocation(), spawnPoints[randomSpawn]->GetActorRotation());


		timeElapsed = 0;

	}
}

