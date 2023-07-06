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
	UE_LOG(LogTemp, Display, TEXT("Configured Moved Distance: %f"),MoveDistance);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{

	// Move platform forward
	// get current location
	FVector CurrentVector = GetActorLocation();
	//  add vector to that location
	//  set the location
	CurrentVector += (PlatformVelocity*DeltaTime);
	// CurrentVector.Y += 2;
	SetActorLocation(CurrentVector);
	// move the platform backward
	//  check the location
	float PlatformDistance = FVector::Dist(StartLocation,CurrentVector);
	// reverse the motion
	// if(PlatformDistance > MoveDistance){
	// 	PlatformVelocity = -PlatformVelocity;
	// 	StartLocation = CurrentVector;
	// }
	if(PlatformDistance > MoveDistance){
		float OverShoot = PlatformDistance - MoveDistance;
		UE_LOG(LogTemp, Display, TEXT("Configured Over Shoot Distance: %f"),OverShoot);
		StartLocation = StartLocation + PlatformVelocity.GetSafeNormal() * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
}
