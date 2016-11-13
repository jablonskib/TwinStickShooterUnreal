// Fill out your copyright notice in the Description page of Project Settings.

#include "TestTwinStick.h"
#include "TestTwinStickPawn.h"
#include "TestTwinStickProjectile.h"
#include "Engine.h"
#include "GhostPawn.h"


// Sets default values
AGhostPawn::AGhostPawn()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	isAlive = true;
	OnActorHit.AddDynamic(this, &AGhostPawn::OnActorCollide);

	randomType = FMath::RandRange(0, 1);

	switch (randomType)
	{
		case 0:
			ghostType = EGhostTypes::SMALL;
			break;
		case 1:
			ghostType = EGhostTypes::LARGE;
			break;
	}

	if (ghostType == EGhostTypes::SMALL)
	{
		health = 3;
		speed = 5;
		damageAmount = 1;
	}
	else
	{
		health = 5;
		speed = 3;
		damageAmount = 3;
	}


}

// Called when the game starts or when spawned
void AGhostPawn::BeginPlay()
{
	Super::BeginPlay();
	pawn = Cast<ATestTwinStickPawn>(GetWorld()->GetFirstPlayerController());
}

// Called every frame
void AGhostPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	pawn = Cast<ATestTwinStickPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (pawn != NULL)
	{
		pointBetween = GetActorLocation() - pawn->GetActorLocation();
		if (pointBetween.Size() < 300.0f)
		{
			DestroyFromContact();
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Pawn not found for some reason?"));
	}

	if (health <= 0)
	{

		ATestTwinStickPawn *player = Cast<ATestTwinStickPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
		player->score += 20;
		Destroy();
	}

	ATestTwinStickPawn *player = Cast<ATestTwinStickPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (!player)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("Player not found."));
		return;
	}

	

	FVector toPlayer = player->GetActorLocation() - GetActorLocation();
	toPlayer.Normalize();
	

	FRotator rotateToPlayer = toPlayer.Rotation();
	rotateToPlayer.Pitch = 0;
	RootComponent->SetWorldRotation(rotateToPlayer);
}

// Called to bind functionality to input
void AGhostPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}


void AGhostPawn::OnActorCollide(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->IsA(ATestTwinStickProjectile::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Yellow, TEXT("ProjectileCollided"));
		health -= 1;
	}
}

void AGhostPawn::DestroyFromContact()
{
	GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Magenta, TEXT("Too Close To Enemy"));
	pawn->health -= damageAmount;
	Destroy();
}


