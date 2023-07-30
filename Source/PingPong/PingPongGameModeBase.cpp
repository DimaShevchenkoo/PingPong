// Copyright Epic Games, Inc. All Rights Reserved.


#include "PingPongGameModeBase.h"


void APingPongGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	StartGame();
}

APingPongGameModeBase::APingPongGameModeBase()
{
	SetScoreToZero();
	bIsGameActive = false;
}

void APingPongGameModeBase::SetScoreToZero()
{
	PlayerScore = 0;
	OpponentScore = 0;  
}

void APingPongGameModeBase::StartGame()
{
	bIsGameActive = true;
	SetScoreToZero();
}

void APingPongGameModeBase::EndGame()
{
	if (!bIsGameActive) return;
	
	if (PlayerScore >= ScoreToWin )
	{
		WhoWon = "Player won";
		bIsGameActive = false;
	}
	else if (OpponentScore >= ScoreToWin)
	{
		WhoWon = "AI won";
		bIsGameActive = false;
	}
}


void APingPongGameModeBase::ResetGame()
{
	SetScoreToZero();
	BeginPlay();
}





