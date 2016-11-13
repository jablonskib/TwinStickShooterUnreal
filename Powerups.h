// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TestTwinStickPawn.h"
#include "Powerups.generated.h"


UENUM()
enum class EPowerupTypes : uint8
{
	FASTER_SHOT,
	INCREASE_DAMAGE,
	SPEED_UP
};

UCLASS()
class TESTTWINSTICK_API APowerups : public AActor
{
	GENERATED_BODY()

private:
	int32 randomType;
public:	
	// Sets default values for this actor's properties
	APowerups();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	EPowerupTypes powerupType;

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ColliderInfo")
	class USphereComponent* sphereC;
	
	ATestTwinStickPawn* player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	FString name;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
