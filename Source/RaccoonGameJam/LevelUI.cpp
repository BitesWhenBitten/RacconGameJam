// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelUI.h"
#include "RaccoonGameJamGameMode.h"
#include "TimerManager.h"
#include "Engine/World.h"


void ULevelUI::Setup()
{
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);

	GameMode = Cast<ARaccoonGameJamGameMode>(GetWorld()->GetAuthGameMode());
	GameMode->OnGameModeTimerExpired.AddDynamic(this, &ThisClass::TimerExpired);
}

void ULevelUI::TimerExpired()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.0f,
			FColor::Cyan,
			FString::Printf(TEXT("The timer expired!"))
		);
	}
}

void ULevelUI::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (GameMode) 
	{
		TimeRemaining = GameMode->GetTimeRemaining();
	}

}
