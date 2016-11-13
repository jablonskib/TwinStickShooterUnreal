// Fill out your copyright notice in the Description page of Project Settings.

#include "TestTwinStick.h"
#include "Powerups.h"


// Sets default values
APowerups::APowerups()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	sphereC = CreateDefaultSubobject<USphereComponent>(TEXT("spherecollider"));

	sphereC->OnComponentBeginOverlap.AddDynamic(this, &APowerups::OnOverlapBegin);
	randomType = FMath::RandRange(0, 2);
	switch (randomType)
	{
		case 0:
			powerupType = EPowerupTypes::FASTER_SHOT;
			name = "fasterShot";
			break;
		case 1:
			powerupType = EPowerupTypes::INCREASE_DAMAGE;
			break;
		case 2:
			powerupType = EPowerupTypes::SPEED_UP;
			name = "speedIncrease";
			break;
	}

}

// Called when the game starts or when spawned
void APowerups::BeginPlay()
{
	Super::BeginPlay();
	player = Cast<ATestTwinStickPawn>(GetWorld()->GetFirstPlayerController());
}

// Called every frame
void APowerups::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	player = Cast<ATestTwinStickPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	SetActorRelativeRotation(FRotator(0, DeltaTime * 5.0f * 5.0f, 0));

}

void APowerups::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor == player)
	{
		GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Orange, TEXT("Powerup picked up " + name));
		player->SetPowerup(name);
		Destroy();
	}
}


