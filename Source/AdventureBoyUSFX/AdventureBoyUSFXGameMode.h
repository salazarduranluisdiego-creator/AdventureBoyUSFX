// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ParedLadrillo.h"
#include "AdventureBoyUSFXGameMode.generated.h"

UCLASS(minimalapi)
class AAdventureBoyUSFXGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AAdventureBoyUSFXGameMode();

protected:
    virtual void BeginPlay() override;

    // Se cambia el nombre del TArray para que sea mas claro
    TArray<AParedLadrillo*> ObstaculosLadrillos;
};

