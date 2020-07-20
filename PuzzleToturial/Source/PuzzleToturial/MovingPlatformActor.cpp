// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/StaticMeshComponent.h "
#include "MovingPlatformActor.h"

// Sets default values
AMovingPlatformActor::AMovingPlatformActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachTo(Root);
	
	Mesh->SetMobility(EComponentMobility::Movable);

	//Root->SetMobility(EComponentMobility::Movable);

}

// Called when the game starts or when spawned
void AMovingPlatformActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingPlatformActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	float speed = MovementSpeed * DeltaTime;
	FVector currentLocation=GetActorLocation();
	currentLocation += FVector(speed, 0, 0);
	SetActorLocation(currentLocation);
	
}

