// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Delegates/Delegate.h"
#include "RaccoonGameJamGameMode.generated.h"

DECLARE_DELEGATE_OneParam(FOnGameModeTimerExpired, bool bGameWon);


UCLASS(minimalapi)
class ARaccoonGameJamGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ARaccoonGameJamGameMode();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode", meta = (Tooltip = "Length of time in minutes for level."))
	float TotalLevelTime = 1;

	float GetTimeRemaining();

	FOnGameModeTimerExpired OnGameOver;

	UFUNCTION(BlueprintCallable)
	void EndGame();

private:

	void BuildGameMode();

	

	void LoseGame();
	void WinGame();

	

	FTimerDelegate TimerDelegate;
	FTimerHandle TimerDelegateHandle;

	bool isGameWon;

};



