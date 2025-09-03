// Copyright Epic Games, Inc. All Rights Reserved.

#include "AdventureBoyUSFXGameMode.h"
#include "AdventureBoyUSFXCharacter.h"
#include "UObject/ConstructorHelpers.h"

#include "ParedLadrillo.h"
#include "Kismet/GameplayStatics.h"

AAdventureBoyUSFXGameMode::AAdventureBoyUSFXGameMode()
{
    // set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != NULL)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
}

void AAdventureBoyUSFXGameMode::BeginPlay()
{
    Super::BeginPlay();

    UWorld* World = GetWorld();

    if (World)
    {
        // Posición inicial del primer obstaculo
        FVector SpawnLocation = FVector(0.0f, 0.0f, 500.0f);
        FRotator SpawnRotation = FRotator::ZeroRotator;
        FActorSpawnParameters SpawnInfo;

        // Bucle para crear 3 obstaculos
        for (int i = 0; i < 3; ++i)
        {
            // Crea un nuevo obstaculo de la clase ParedLadrillo y lo agrega al TArray
            AParedLadrillo* NuevoObstaculo = World->SpawnActor<AParedLadrillo>(SpawnLocation, SpawnRotation, SpawnInfo);
            ObstaculosLadrillos.Add(NuevoObstaculo);

            // Calcula la posicion del siguiente obstaculo
            SpawnLocation.X += 150.0f; // Ajusta la distancia entre los obstaculos
        }

        for (int i = 0; i < 3; ++i)
        {
            AParedLadrillo* NuevoObstaculo = World->SpawnActor<AParedLadrillo>(SpawnLocation, SpawnRotation, SpawnInfo);
            ObstaculosLadrillos.Add(NuevoObstaculo);

            // Ajusta la posicion del siguiente obstaculo para la grada
            SpawnLocation.X += 50.0f; // Distancia horizontal
            SpawnLocation.Z += 150.0f; // Altura de la grada
        }
    }
}