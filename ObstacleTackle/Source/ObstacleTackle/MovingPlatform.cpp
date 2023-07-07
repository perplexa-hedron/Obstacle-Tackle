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
	if (ShouldPlatformReturn())
	{
		FVector MovingDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MovingDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		FVector CurrentVector = GetActorLocation();
		CurrentVector += (PlatformVelocity * Deltatime);
		SetActorLocation(CurrentVector);
		// AddActorLocalOffset(PlatformVelocity * Deltatime);
	}
}

void AMovingPlatform::RotatePlatform(float Deltatime)
{
	AddActorLocalRotation(RotationVelocity * Deltatime);
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	// float PlatformDistance = FVector::Dist(StartLocation, GetActorLocation());
	return PlatformDistance() > MoveDistance;
}
float AMovingPlatform::PlatformDistance() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}