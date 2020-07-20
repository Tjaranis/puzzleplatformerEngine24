// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLETOTURIAL_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyProperties", Meta = (MakeEditWidget = true))
	FVector TargetLocation;

private:
	float MovementSpeed = 100;
	FVector GlobalTargetLocation;
	FVector GlobalStartingLocation;
};
