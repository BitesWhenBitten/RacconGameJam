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

}

void ULevelUI::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (GameMode) 
	{
		TimeRemaining = GameMode->GetTimeRemaining();
	}

}
