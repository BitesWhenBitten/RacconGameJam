// Copyright Epic Games, Inc. All Rights Reserved.

#include "RaccoonGameJamGameMode.h"
#include "RaccoonGameJamCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARaccoonGameJamGameMode::ARaccoonGameJamGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
