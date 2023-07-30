// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerPaddle.generated.h"

class UBoxComponent;
class UStaticMeshComponent;




UCLASS()
class PINGPONG_API APlayerPaddle : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerPaddle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void Move(float AxisValue);

private:
	UPROPERTY(EditAnywhere)
	UBoxComponent* BoxCollision;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComponent;
	
	
	UPROPERTY(EditAnywhere, Category = Movement)
	float PaddleSpeed {};
	float MaxPaddleLocationY = 565.f;
	float MinPaddleLocationY = -565.f;

	FVector PaddleStartLocation{};
	
	
	
	
};
