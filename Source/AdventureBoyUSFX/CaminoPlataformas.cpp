// Fill out your copyright notice in the Description page of Project Settings.


#include "CaminoPlataformas.h"
#include "Engine/World.h"
#include "Plataforma.h"

// Sets default values
ACaminoPlataformas::ACaminoPlataformas() :
	NumeroDePlataformas(5),
	SeparacionEntrePlataformas(200.0f)
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACaminoPlataformas::BeginPlay()
{
	Super::BeginPlay();

	// Llama a la funci�n de generaci�n cuando el juego inicia
	GenerarCamino();
}

// Called every frame
void ACaminoPlataformas::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACaminoPlataformas::GenerarCamino()
{
	UWorld* World = GetWorld();
	if (World)
	{
		// AQUI ESTA EL CAMBIO: Define una posici�n inicial fija en lugar de usar GetActorLocation()
		FVector SpawnLocation = FVector(50.0f, 50.0f, 100.0f);
		FRotator SpawnRotation = FRotator::ZeroRotator;
		FActorSpawnParameters SpawnInfo;

		for (int i = 0; i < NumeroDePlataformas; ++i)
		{
			APlataforma* NuevaPlataforma = World->SpawnActor<APlataforma>(SpawnLocation, SpawnRotation, SpawnInfo);
			if (NuevaPlataforma)
			{
				PlataformasGeneradas.Add(NuevaPlataforma);

				// Actualiza la posici�n para la siguiente plataforma, movi�ndola en el eje X
				SpawnLocation.X += SeparacionEntrePlataformas;
			}
		}
	}
}