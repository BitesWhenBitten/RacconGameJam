// Fill out your copyright notice in the Description page of Project Settings.


#include "UIFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerInput.h"



void UUIFunctionLibrary::SetInputToUIOnly(UUserWidget* WidgetInFocus)
{
	UWorld* World = WidgetInFocus->GetWorld();
	if (World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController)
		{

			PlayerController->PlayerInput->FlushPressedKeys();

			FInputModeUIOnly InputModeUI;
			InputModeUI.SetWidgetToFocus(WidgetInFocus->TakeWidget());
			InputModeUI.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			PlayerController->SetInputMode(InputModeUI);
			PlayerController->SetShowMouseCursor(true);
		}
	}
}

void UUIFunctionLibrary::SetInputToGameAndUI(UUserWidget* WidgetInFocus)
{
	UWorld* World = WidgetInFocus->GetWorld();
	if (World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController)
		{

			PlayerController->PlayerInput->FlushPressedKeys();
			FInputModeGameAndUI InputModeGameAndUI;
			
			InputModeGameAndUI.SetWidgetToFocus(WidgetInFocus->TakeWidget());
			InputModeGameAndUI.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			PlayerController->SetInputMode(InputModeGameAndUI);
			PlayerController->SetShowMouseCursor(true);
		}
	}
}

void UUIFunctionLibrary::SetInputToGame(const UObject* WorldContextObject)
{
	UWorld* World = WorldContextObject->GetWorld();
	if (World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController)
		{
			FInputModeGameOnly InputModeGame;
			PlayerController->SetInputMode(InputModeGame);
			PlayerController->SetShowMouseCursor(false);
		}
	}
}

void UUIFunctionLibrary::ReloadCurrentLevel(const UObject* WorldContextObject)
{
	FString Level = UGameplayStatics::GetCurrentLevelName(WorldContextObject);
	UGameplayStatics::OpenLevel(WorldContextObject, FName(Level));

}

void UUIFunctionLibrary::QuitGame(const UObject* WorldContextObject)
{
	UKismetSystemLibrary::QuitGame(
		WorldContextObject,
		WorldContextObject->GetWorld()->GetFirstPlayerController(), 
		EQuitPreference::Quit, 
		false);
}
