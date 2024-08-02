// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseMenu.generated.h"


/**
 * 
 */
UCLASS()
class RACCOONGAMEJAM_API UPauseMenu : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual bool Initialize() override;

	UFUNCTION(BlueprintCallable)
	void Setup();

	UFUNCTION(BlueprintCallable)
	void CloseMenu();

protected:

	UPROPERTY(meta = (BindWidget))
	class UButton* RetryButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton;

private:
	
	UFUNCTION()
	void RetryLevelButtonClicked();
	UFUNCTION()
	void QuitGameButtonClicked();



};
