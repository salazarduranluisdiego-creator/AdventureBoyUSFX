// Copyright Epic Games, Inc. All Rights Reserved.

#include "AdventureBoyUSFXGameMode.h"
#include "AdventureBoyUSFXCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "CaminoPlataformas.h"
#include "ObstaculosLadrillos.h"
#include "ParedLadrillo.h"
#include "HordaEnemigos.h"
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
		// Declara y define las variables de spawn para las plataformas
		FVector SpawnLocationPlataformas = FVector(0.0f, 0.0f, 100.0f);
		FRotator SpawnRotation = FRotator::ZeroRotator;
		FActorSpawnParameters SpawnInfo;

		// Spawnea el actor CaminoPlataformas
		ACaminoPlataformas* Camino = World->SpawnActor<ACaminoPlataformas>(SpawnLocationPlataformas, SpawnRotation, SpawnInfo);


		FVector SpawnLocationObstaculos = FVector(-300.0f, 300.0f, 130.0f);
		FRotator SpawnRotationObstaculos = FRotator::ZeroRotator;
		FActorSpawnParameters SpawnInfoObstaculos;

		AObstaculosLadrillos* Obstaculos = World->SpawnActor<AObstaculosLadrillos>(SpawnLocationObstaculos, SpawnRotationObstaculos, SpawnInfoObstaculos);




		
		// --- Lógica para los obstáculos de ladrillo ---

		// Declara y define las variables de spawn para los obstáculos
		/*FVector SpawnLocationObstaculos = FVector(0.0f, 0.0f, 500.0f);

		// Bucle para crear 4 obstaculos
		for (int i = 0; i < 4; ++i)
		{
			// Crea un nuevo obstaculo de la clase ParedLadrillo y lo agrega al TArray
			AParedLadrillo* NuevoObstaculo = World->SpawnActor<AParedLadrillo>(SpawnLocationObstaculos, SpawnRotation, SpawnInfo);
			ObstaculosLadrillos.Add(NuevoObstaculo);

			// Calcula la posicion del siguiente obstaculo
			SpawnLocationObstaculos.X += 150.0f; // Ajusta la distancia entre los obstaculos
		}*/

		// Segundo bucle para crear 3 obstaculos adicionales en una grada
		/*for (int i = 0; i < 3; ++i)
		{
			AParedLadrillo* NuevoObstaculo = World->SpawnActor<AParedLadrillo>(SpawnLocationObstaculos, SpawnRotation, SpawnInfo);
			ObstaculosLadrillos.Add(NuevoObstaculo);

			// Ajusta la posicion del siguiente obstaculo para la grada
			SpawnLocationObstaculos.X += 50.0f; // Distancia horizontal
			SpawnLocationObstaculos.Z += 150.0f; // Altura de la grada
		}*/



		// --- Lógica para la Horda de Enemigos (similar a CaminoPlataformas) ---
		FVector HordaSpawnLocation = FVector(-490.0f, 610.0f, 218.0f);

		// Spawnea el actor de la Horda de Enemigos directamente, como CaminoPlataformas
		AHordaEnemigos* Horda = World->SpawnActor<AHordaEnemigos>(HordaSpawnLocation, SpawnRotation, SpawnInfo);

		if (Horda)
		{
			UE_LOG(LogTemp, Warning, TEXT("Horda de enemigos creada con exito."));
		}
	}
}