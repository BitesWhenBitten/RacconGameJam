// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "UIFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class RACCOONGAMEJAM_API UUIFunctionLibrary : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static void SetInputToPaused(UUserWidget* WidgetInFocus);
	
	UFUNCTION(BlueprintCallable)
	static void SetInputToInPlay(const UObject* WorldContextObject);

	
	static void ReloadCurrentLevel(const UObject* WorldContextObject);

	static void QuitGame(const UObject* WorldContextObject);

	
};