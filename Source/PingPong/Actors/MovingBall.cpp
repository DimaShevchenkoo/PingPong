// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingBall.h"


#include "Wall.h"
#include "PingPong/PlayerPaddle.h"
#include "Components/BoxComponent.h"
#include "GoalZone.h"
#include "PingPong/PingPongGameModeBase.h"


AMovingBall::AMovingBall()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AMovingBall::OnOverlapBegin);
	
	RootComponent = BoxCollision;
	StaticMeshComponent->SetupAttachment(BoxCollision);
	
}


void AMovingBall::BeginPlay()
{
	Super::BeginPlay();
	BallStartLocation = GetActorLocation();
	SetupBall();
	
}

bool AMovingBall::IsVerticallyOriented(const AActor* Actor, float AngleThreshold)
{
	FRotator ActorRotation = Actor->GetActorRotation();
	float PitchAngle = FMath::Abs(ActorRotation.Pitch);
	float RollAngle = FMath::Abs(ActorRotation.Roll);
	float YawAngle = FMath::Abs(FMath::Abs(ActorRotation.Yaw) - 90.0f);

	return (PitchAngle <= AngleThreshold && RollAngle <= AngleThreshold && YawAngle <= AngleThreshold);
}

void AMovingBall::SetupBall()
{
	FVector RandomDirection = FVector(FMath::FRandRange(-1.0f, 1.0f),
									  FMath::FRandRange(-1.0f, 1.0f),
									  0.0f);
	RandomDirection.Normalize();
	BallMovement = RandomDirection * BallSpeed;
}

void AMovingBall::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if (OtherActor && OtherActor->IsA(AWall::StaticClass()))
	{
		if (IsVerticallyOriented(OtherActor, 10.0f))
		{
			BallMovement.X *= -1.0f;
		}
		else
		{
			BallMovement.Y *= -1.0f;
		}
	}
	else if(OtherActor && OtherActor->IsA(APlayerPaddle::StaticClass()))
	{
		BallMovement.X *= -1.0f;
		BallMovement.Y *= -1.0f;
	}
	else if (OtherActor && OtherActor->IsA(AGoalZone::StaticClass()))
	{
		
		
		APingPongGameModeBase* GameModeBase = GetWorld()->GetAuthGameMode<APingPongGameModeBase>();
		AGoalZone* GoalZone = Cast<AGoalZone>(OtherActor);
		bool ScoreGoal = GoalZone->GetPlayerTargetGoal();
		if (GameModeBase)
		{
			if (ScoreGoal)
			{
				int PlayerScore = GameModeBase->GetPlayerOneScore();
				PlayerScore++;
				GameModeBase->SetPlayerOneScore(PlayerScore);
			}
			else
			{
				int OpponentScore = GameModeBase->GetOpponentScore();
				OpponentScore++;
				GameModeBase->SetOpponentScore(OpponentScore);
			}
		}
		SetActorLocation(BallStartLocation);
		SetupBall();
	}
	
}


void AMovingBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation() + BallMovement * DeltaTime;
	SetActorLocation(NewLocation);
}





