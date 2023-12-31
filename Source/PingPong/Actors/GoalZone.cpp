// Fill out your copyright notice in the Description page of Project Settings.


#include "GoalZone.h"
#include "Components/BoxComponent.h"


// Sets default values
AGoalZone::AGoalZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));

	RootComponent = StaticMeshComponent;
	BoxCollision->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void AGoalZone::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void AGoalZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}





