// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PingPongGameModeBase.generated.h"

class AMovingBall;
class APlayerPaddle;
/**
 * 
 */
class UUserWidget;





UCLASS()
class PINGPONG_API APingPongGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	
	virtual void BeginPlay() override;

	APingPongGameModeBase();

	
	UFUNCTION(BlueprintCallable)
	void EndGame();
	
	
	
	void SetPlayerOneScore(int Value) { PlayerScore = Value; }
	void SetOpponentScore(int Value) { OpponentScore = Value; }
	
	UFUNCTION(BlueprintCallable)
	bool GetIsGameActive() { return bIsGameActive; }
	
	UFUNCTION(BlueprintCallable)
	FString GetWhoWon() {return WhoWon;}
	
	UFUNCTION(BlueprintCallable)
	int32 GetScoreToWin() { return ScoreToWin; }
	UFUNCTION(BlueprintCallable)
	int32 GetPlayerOneScore() {return PlayerScore;}
	UFUNCTION(BlueprintCallable)
	int32 GetOpponentScore()  {return OpponentScore;}

private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess))
	int32 ScoreToWin{};
	int32 PlayerScore{};
	int32 OpponentScore{};
	
	FString WhoWon;

	bool bIsGameActive{true};
	
	void ResetGame();
	void SetScoreToZero();
	void StartGame();
};


