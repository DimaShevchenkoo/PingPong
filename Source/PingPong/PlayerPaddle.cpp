// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPaddle.h"

#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerPaddle::APlayerPaddle()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->SetCollisionProfileName("NoCollision");
	
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));

	
	BoxCollision->SetupAttachment(RootComponent);
	StaticMeshComponent->SetupAttachment(BoxCollision);
	
	
}

// Called when the game starts or when spawned
void APlayerPaddle::BeginPlay()
{
	Super::BeginPlay();
	PaddleStartLocation = GetActorLocation();
}

// Called every frame
void APlayerPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void APlayerPaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MovePlatform"), this, &APlayerPaddle::Move);
}



void APlayerPaddle::Move(float AxisValue)
{
	FVector NewPaddleLocation{GetActorLocation()};
	// Calculating paddle location by multiplying by delta seconds to avoid incorrect calculation for different systems  
	NewPaddleLocation.Y +=  PaddleSpeed * AxisValue * UGameplayStatics::GetWorldDeltaSeconds(GetWorld());
	
	float ClampedY = FMath::Clamp(NewPaddleLocation.Y, MinPaddleLocationY, MaxPaddleLocationY);
	
	SetActorLocation(FVector(NewPaddleLocation.X, ClampedY, NewPaddleLocation.Z), true);
}









