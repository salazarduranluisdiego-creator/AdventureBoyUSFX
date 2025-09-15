// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculosLadrillos.h"
#include "Engine/World.h"
#include "ParedLadrillo.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AObstaculosLadrillos::AObstaculosLadrillos():
SeparacionEntreParedesLadrillo(300.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ContadorMovimientoLadrillo = 0; // Inicializamos el contador en 0
}

// Called when the game starts or when spawned
void AObstaculosLadrillos::BeginPlay()
{
	Super::BeginPlay();
	
	GenerarObstaculosLadrillo1();

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AObstaculosLadrillos::MoverParedLadrilloAleatoria, 5.0f, true);
}

// Called every frame
void AObstaculosLadrillos::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AObstaculosLadrillos::GenerarObstaculosLadrillo1()
{
	UWorld* World = GetWorld();
	if (World)
	{
		FVector SpawnLocation = FVector(-100.0f,200.0f, 150.0f);
		FRotator SpawnRotation = FRotator::ZeroRotator;
		FActorSpawnParameters SpawnInfo;
		for (int i = 0; i < 4; ++i)
		{
			FVector UbicacionParedLadrillo = FVector(SpawnLocation.X + i * SeparacionEntreParedesLadrillo, SpawnLocation.Y, SpawnLocation.Z);
			AParedLadrillo* NuevaParedLadrillo = World->SpawnActor<AParedLadrillo>(UbicacionParedLadrillo, SpawnRotation, SpawnInfo);
			if (NuevaParedLadrillo)
			{
				ParedesLadrillGeneradas.Add(NuevaParedLadrillo);
			}
		}
		// Segundo bucle para crear 3 obstaculos adicionales en una grada
		/*for (int i = 0; i < 3; ++i)
		{
			FVector UbicacionParedLadrillo = FVector(SpawnLocation.X + i * 50.0f, SpawnLocation.Y + 200.0f, SpawnLocation.Z + 100.0f);
			AParedLadrillo* NuevaParedLadrillo = World->SpawnActor<AParedLadrillo>(UbicacionParedLadrillo, SpawnRotation, SpawnInfo);
			if (NuevaParedLadrillo)
			{
				ParedesLadrillGeneradas.Add(NuevaParedLadrillo);
			}
		}*/
	}
}

void AObstaculosLadrillos::MoverParedLadrilloAleatoria()
{
	if (ParedesLadrillGeneradas.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No hay paredes de ladrillo generadas para mover."));
		return;
	}
	// Selecciona una pared de ladrillo aleatoriamente
	int32 IndiceAleatorio = FMath::RandRange(0, ParedesLadrillGeneradas.Num() - 1);
	AParedLadrillo* ParedSeleccionada = ParedesLadrillGeneradas[IndiceAleatorio];
	if (ParedSeleccionada)
	{
		// Alterna entre los diferentes tipos de movimiento cada vez que se llama a esta función
		if (ContadorMovimientoLadrillo == 0)
		{
			ParedSeleccionada->bMoviendosePared = true;
			ParedSeleccionada->bMovimientoVerticalPared = false;
			ParedSeleccionada->bMovimientoYPared = false;
			ParedSeleccionada->bMovimientoDiagonalXYPared = false;
			ParedSeleccionada->bMovimientoDiagonalXZPared = false; // Mueve en X
			UE_LOG(LogTemp, Warning, TEXT("Se ha activado el movimiento horizontal (X) para la pared de ladrillo %d"), IndiceAleatorio);
		}
		else if (ContadorMovimientoLadrillo == 1)
		{
			ParedSeleccionada->bMoviendosePared = true;
			ParedSeleccionada->bMovimientoVerticalPared = true; // Mueve en Z
			ParedSeleccionada->bMovimientoYPared = false;
			ParedSeleccionada->bMovimientoDiagonalXYPared = false;
			ParedSeleccionada->bMovimientoDiagonalXZPared = false;
			UE_LOG(LogTemp, Warning, TEXT("Se ha activado el movimiento vertical (Z) para la pared de ladrillo %d"), IndiceAleatorio);
		}
		else if (ContadorMovimientoLadrillo == 2)
		{
			ParedSeleccionada->bMoviendosePared = true;
			ParedSeleccionada->bMovimientoVerticalPared = false;
			ParedSeleccionada->bMovimientoYPared = true; // Mueve en Y
			ParedSeleccionada->bMovimientoDiagonalXYPared = false;
			ParedSeleccionada->bMovimientoDiagonalXZPared = false;
			UE_LOG(LogTemp, Warning, TEXT("Se ha activado el movimiento vertical (Y) para la pared de ladrillo %d"), IndiceAleatorio);
		}
		else if (ContadorMovimientoLadrillo == 3)
		{
			ParedSeleccionada->bMoviendosePared = true;
			ParedSeleccionada->bMovimientoVerticalPared = false;
			ParedSeleccionada->bMovimientoYPared = false; 
			ParedSeleccionada->bMovimientoDiagonalXYPared = true;// Mueve en XY
			ParedSeleccionada->bMovimientoDiagonalXZPared = false;
			UE_LOG(LogTemp, Warning, TEXT("Se ha activado el movimiento vertical (XY) para la pared de ladrillo %d"), IndiceAleatorio);
		}
		else
		{
			ParedSeleccionada->bMoviendosePared = true;
			ParedSeleccionada->bMovimientoVerticalPared = false;
			ParedSeleccionada->bMovimientoYPared = false; 
			ParedSeleccionada->bMovimientoDiagonalXYPared = false;
			ParedSeleccionada->bMovimientoDiagonalXZPared = true;// Mueve en XZ
			UE_LOG(LogTemp, Warning, TEXT("Se ha activado el movimiento vertical (XZ) para la pared de ladrillo %d"), IndiceAleatorio);
		}

		// Actualiza el contador y lo resetea a 0 si llega a 5.
		ContadorMovimientoLadrillo = (ContadorMovimientoLadrillo + 1) % 5;
	}
}
