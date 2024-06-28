// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RaccoonGameJamGameMode.generated.h"

UCLASS(minimalapi)
class ARaccoonGameJamGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ARaccoonGameJamGameMode();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameMode", meta = (Tooltip = "Length of time in minutes for level."))
	float TotalLevelTime = 1;
		 
private:

	void BuildGameMode();

	void WinGame();

	void LoseGame();

	

	FTimerDelegate TimerDelegate;
	FTimerHandle TimerDelegateHandle;

	bool isGameWon;

};



