// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenu.h"
#include "UIFunctionLibrary.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"


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
	UUIFunctionLibrary::SetInputToGameAndUI(this);
	UGameplayStatics::SetGamePaused(this, true);
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
}

void UPauseMenu::CloseMenu()
{
	UGameplayStatics::SetGamePaused(this, false);
	UUIFunctionLibrary::SetInputToGame(this);
	RemoveFromParent();
}

void UPauseMenu::RetryLevelButtonClicked()
{
	UUIFunctionLibrary::SetInputToGame(this);
	UUIFunctionLibrary::ReloadCurrentLevel(this);
}

void UPauseMenu::QuitGameButtonClicked()
{
	UUIFunctionLibrary::QuitGame(this);
}
