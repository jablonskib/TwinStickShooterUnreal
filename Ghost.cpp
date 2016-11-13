// Fill out your copyright notice in the Description page of Project Settings.

#include "TestTwinStick.h"
#include "TestTwinStickPawn.h"
#include "Engine.h"
#include "Ghost.h"


// Sets default values
AGhost::AGhost()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGhost::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGhost::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	ATestTwinStickPawn *player = Cast<ATestTwinStickPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (!player)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("Player not found."));
		return;
	}

	FVector toPlayer = player->GetActorLocation() - GetActorLocation();
	toPlayer.Normalize();

	AddMovementInput(toPlayer, speed*DeltaTime);

	FRotator rotateToPlayer = toPlayer.Rotation();
	rotateToPlayer.Pitch = 0;
	RootComponent->SetWorldRotation(rotateToPlayer);


}

// Called to bind functionality to input
void AGhost::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

