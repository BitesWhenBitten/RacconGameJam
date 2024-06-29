// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RaccoonGameJamGameMode.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FOnGameModeTimerExpired, bool, bGameWon);


UCLASS(minimalapi)
class ARaccoonGameJamGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ARaccoonGameJamGameMode();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameMode", meta = (Tooltip = "Length of time in minutes for level."))
	float TotalLevelTime = 1;

	float GetTimeRemaining();

	FOnGameModeTimerExpired OnGameModeTimerExpired;
		 
private:

	void BuildGameMode();

	void WinGame();

	void LoseGame();

	

	FTimerDelegate TimerDelegate;
	FTimerHandle TimerDelegateHandle;

	bool isGameWon;

};



