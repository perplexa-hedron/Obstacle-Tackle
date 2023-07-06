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
	FString Name = GetName();
	UE_LOG(LogTemp, Display, TEXT("Configured %s Moved Distance: %f"), *Name, MoveDistance);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	MovePlatform(DeltaTime);

	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float Deltatime)
{
	FVector CurrentVector = GetActorLocation();
	CurrentVector += (PlatformVelocity * Deltatime);
	SetActorLocation(CurrentVector);
	float PlatformDistance = FVector::Dist(StartLocation, CurrentVector);
	if (PlatformDistance > MoveDistance)
	{
		FString ActorName = GetName();
		float OverShoot = PlatformDistance - MoveDistance;
		UE_LOG(LogTemp, Display, TEXT("Configured Over Shoot of %s Distance: %f"), *ActorName, OverShoot);
		StartLocation = StartLocation + PlatformVelocity.GetSafeNormal() * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
}

void AMovingPlatform::RotatePlatform(float Deltatime)
{
	// float Degree;
	UE_LOG(LogTemp, Display, TEXT("The %s Rotated by: %f"),*GetName());
}