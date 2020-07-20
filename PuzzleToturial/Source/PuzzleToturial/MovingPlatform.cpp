// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
	
	
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	GlobalStartingLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();

	float speed = MovementSpeed * DeltaTime;
	float JournyLength = (GlobalTargetLocation - GlobalStartingLocation).Size();
	float JourneyTraveled = (Location - GlobalStartingLocation).Size();
	
	if (JourneyTraveled >= JournyLength) {
		FVector Swap = GlobalStartingLocation;
		GlobalStartingLocation = GlobalTargetLocation;
		GlobalTargetLocation = Swap;
		}

	FVector Direction = (GlobalTargetLocation - GlobalStartingLocation).GetSafeNormal();
	
	Location += speed * Direction;
	SetActorLocation(Location);

}
