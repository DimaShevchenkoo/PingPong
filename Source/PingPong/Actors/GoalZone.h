// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GoalZone.generated.h"

class UBoxComponent;

UCLASS()
class PINGPONG_API AGoalZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGoalZone();
	
	virtual void Tick(float DeltaTime) override;

	bool GetPlayerTargetGoal() {return PlayerTargetGoal;}
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category = Goal)
	bool PlayerTargetGoal{true};
	
private:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;
	UPROPERTY(EditAnywhere)
	UBoxComponent* BoxCollision;

	
};
