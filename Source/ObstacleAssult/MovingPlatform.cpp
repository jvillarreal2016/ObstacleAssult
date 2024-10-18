// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Move Platforms Forward
	//Get Current Location
	FVector CurrentLocation = GetActorLocation();
	// Add vector to that location
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
	//set location
	SetActorLocation(CurrentLocation);
	//send platform back if gone too far
	// check how far we've moved
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
	//reverse direction of motion if gone too far
	if (DistanceMoved > MoveDistance)
	{
		PlatformVelocity = -PlatformVelocity;
		StartLocation = CurrentLocation;
	}

}

