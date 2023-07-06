// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLETACKLE_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, Category = "Motion")
	FVector PlatformVelocity = FVector(100, 0, 0);
	
	UPROPERTY(EditAnywhere, Category = "Rotation")
	FRotator RotationVelocity;

	UPROPERTY(EditAnywhere, Category = "Motion")
	float MoveDistance = 100;

	FVector StartLocation;

	void MovePlatform(float Deltatime);
	void RotatePlatform(float Deltatime);
	bool ShouldPlatformReturn() const;
	float PlatformDistance() const;
};
