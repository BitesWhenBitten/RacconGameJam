// Copyright Epic Games, Inc. All Rights Reserved.

#include "RaccoonGameJamGameMode.h"
#include "RaccoonGameJamCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARaccoonGameJamGameMode::ARaccoonGameJamGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_RaccoonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ARaccoonGameJamGameMode::BeginPlay()
{
	Super::BeginPlay();
	BuildGameMode();

}



float ARaccoonGameJamGameMode::GetTimeRemaining()
{
	return GetWorldTimerManager().GetTimerRemaining(TimerDelegateHandle);	
}

void ARaccoonGameJamGameMode::BuildGameMode()
{
	//start a timer, use variable later to be assigned from Level BPs

	//pull in Level Time from Level asset

	//multiply Level time by 60 for minute conversion
	float LevelTimeInSeconds = TotalLevelTime * 60;

	TimerDelegate = FTimerDelegate::CreateUObject(this, &ARaccoonGameJamGameMode::LoseGame);

	//set the timer
	GetWorldTimerManager().SetTimer(TimerDelegateHandle, TimerDelegate, LevelTimeInSeconds, false);

}

void ARaccoonGameJamGameMode::WinGame()
{
	//clear timer
	GetWorldTimerManager().ClearTimer(TimerDelegateHandle);
	// unbind timer delegate
	TimerDelegate.Unbind();

	isGameWon = true;

	OnGameModeTimerExpired.ExecuteIfBound(isGameWon);
}

void ARaccoonGameJamGameMode::LoseGame()
{
	// unbind timer delegate
	TimerDelegate.Unbind();

	isGameWon = false;

	OnGameModeTimerExpired.ExecuteIfBound(isGameWon);

}
