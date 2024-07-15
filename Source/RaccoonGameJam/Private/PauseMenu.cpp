// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenu.h"
#include "UIFunctionLibrary.h"
#include "Components/Button.h"
#include "RaccoonGameJam/RaccoonGameJamGameMode.h"



bool UPauseMenu::Initialize()
{
	if (!Super::Initialize()) { return false; }

	if (RetryButton)
	{
		RetryButton->OnClicked.AddDynamic(this, &ThisClass::RetryLevelButtonClicked);
	}
	if (QuitButton)
	{
		QuitButton->OnClicked.AddDynamic(this, &ThisClass::QuitGameButtonClicked);
	}

	return true;
}

void UPauseMenu::Setup()
{
	ARaccoonGameJamGameMode* GameMode = Cast<ARaccoonGameJamGameMode>(GetWorld()->GetAuthGameMode());
	GameMode->PauseGame();
	UUIFunctionLibrary::SetInputToPaused(this);
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
}

void UPauseMenu::CloseMenu()
{
	ARaccoonGameJamGameMode* GameMode = Cast<ARaccoonGameJamGameMode>(GetWorld()->GetAuthGameMode());
	GameMode->UnPauseGame();
	UUIFunctionLibrary::SetInputToInPlay(this);
	RemoveFromParent();
}

void UPauseMenu::RetryLevelButtonClicked()
{
	UUIFunctionLibrary::SetInputToInPlay(this);
	UUIFunctionLibrary::ReloadCurrentLevel(this);
}

void UPauseMenu::QuitGameButtonClicked()
{
	UUIFunctionLibrary::QuitGame(this);
}
