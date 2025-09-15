// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CaminoPlataformas.h"
#include "ObstaculosLadrillos.h"
#include "ParedLadrillo.h"
#include "HordaEnemigos.h"
#include "AdventureBoyUSFXGameMode.generated.h"
UCLASS(minimalapi)
class AAdventureBoyUSFXGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAdventureBoyUSFXGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	TSubclassOf<class AHordaEnemigos> ClaseHorda;

protected:
	virtual void BeginPlay() override;

	// El TArray necesita UPROPERTY() para que el Garbage Collector funcione correctamente
	/*UPROPERTY()
	TArray<AParedLadrillo*> ObstaculosLadrillos;*/

};
