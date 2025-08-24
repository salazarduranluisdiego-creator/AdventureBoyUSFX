// Copyright Epic Games, Inc. All Rights Reserved.

#include "AdventureBoyUSFXGameMode.h"
#include "AdventureBoyUSFXCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAdventureBoyUSFXGameMode::AAdventureBoyUSFXGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
