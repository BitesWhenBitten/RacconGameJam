// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelUI.h"
#include "RaccoonGameJamGameMode.h"
#include "RaccoonGameJamCharacter.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Internationalization/Text.h"
#include "UIFunctionLibrary.h"




void ULevelUI::Setup()
{
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);

	GameMode = Cast<ARaccoonGameJamGameMode>(GetWorld()->GetAuthGameMode());
	GameMode->OnGameOver.BindUObject(this, &ThisClass::GameOver);
}

void ULevelUI::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (GameMode) 
	{
		TimeRemaining = GameMode->GetTimeRemaining();
	}

}

bool ULevelUI::Initialize()
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

void ULevelUI::RetryLevelButtonClicked()
{
	UUIFunctionLibrary::SetInputToInPlay(this);
	UUIFunctionLibrary::ReloadCurrentLevel(this);
}

void ULevelUI::QuitGameButtonClicked()
{
	UUIFunctionLibrary::QuitGame(this);
}

void ULevelUI::TurnOnButtons()
{
	if (QuitButton)
	{
		QuitButton->SetIsEnabled(true);
		QuitButton->SetVisibility(ESlateVisibility::Visible);
	}
	if (RetryButton)
	{
		RetryButton->SetIsEnabled(true);
		RetryButton->SetVisibility(ESlateVisibility::Visible);
	}
}

void ULevelUI::GameOver(bool bGameWon)
{
	isGamePlaying = false;

	GameMode->OnGameOver.Unbind();

	UUIFunctionLibrary::SetInputToPaused(this);
	TurnOnButtons();

	if (bGameWon)
	{
		GameWon();
	}
	else
	{
		GameLost();
	}
	
}


void ULevelUI::GameWon()
{
	ARaccoonGameJamCharacter* Character = Cast<ARaccoonGameJamCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	
	FText WinMessage;

	if (Character)
	{
		FString TrashWon = FString::Printf(TEXT("Total Trash Won: %i"), (int)Character->GetTrashSum());

		WinMessage = FText::FromString("You escaped with trash! " + TrashWon);
	}
	else
	{
		WinMessage = FText::FromString("You escaped with trash!");
	}

	EndText->SetText(WinMessage);
	EndText->SetIsEnabled(true);
	EndText->SetVisibility(ESlateVisibility::Visible);
}

void ULevelUI::GameLost()
{
	FText LoseMessage = FText::FromString("You failed to escape with trash! Give it another shot!");

	EndText->SetText(LoseMessage);
	EndText->SetIsEnabled(true);
	EndText->SetVisibility(ESlateVisibility::Visible);
}
