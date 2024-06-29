// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LevelUI.generated.h"

/**
 * 
 */
UCLASS()
class RACCOONGAMEJAM_API ULevelUI : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	void Setup();

	UFUNCTION()
	void TimerExpired(bool bGameWon);

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

protected:


	UPROPERTY(BlueprintReadonly)
	float TimeRemaining;

	UPROPERTY(BlueprintReadonly)
	bool isGamePlaying = true;

private:

	class ARaccoonGameJamGameMode* GameMode;



};
