// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingBall.generated.h"


class APingPongGameModeBase;
class UProjectileMovementComponent;
class APlayerPaddle;
class UBoxComponent;
class UCapsuleComponent;
class USphereComponent;

UCLASS()
class PINGPONG_API AMovingBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingBall();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
							int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereCollision;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComponent;
	UPROPERTY()
	APlayerPaddle* PlayerPaddle;

	void SetupBall();
	bool IsVerticallyOriented(const AActor* Actor, float AngleThreshold = 10.0f);
	bool RandomBool = FMath::RandBool();

	UPROPERTY(EditAnywhere)
	float BallSpeed { 200.f };
	
	FVector BallMovement{};
	FVector BallStartLocation{};
	FVector BallInitialVelocity = FVector(1.0f, 1.0f, 0.0f).GetSafeNormal();
	FVector BallVelocity;
	
};
