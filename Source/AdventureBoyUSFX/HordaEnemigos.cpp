// Fill out your copyright notice in the Description page of Project Settings.

#include "HordaEnemigos.h"
#include "Engine/World.h"
#include "Caballero.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AHordaEnemigos::AHordaEnemigos()
{
	PrimaryActorTick.bCanEverTick = true;
	NumeroEnemigosPorColumna = { {1, 3}, {2, 3}, {3, 3} };
	bHordaMoviendose = false;
}

// Called when the game starts or when spawned
void AHordaEnemigos::BeginPlay()
{
	Super::BeginPlay();

	GenerarHorda();

	// Inicia el temporizador.
	// Llama a la función IniciarMovimiento() después de 3.0 segundos.
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle_MoverHorda,
		this,
		&AHordaEnemigos::IniciarMovimiento,
		3.0f, // Retraso de 3.0 segundos
		false // Se ejecuta una sola vez
	);

}

void AHordaEnemigos::GenerarHorda()
{
	UWorld* World = GetWorld();
	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("ERROR: El mundo no es valido."));
		return;
	}

	FVector SpawnOrigin = FVector(-1600.0f,-10.0f, 218.0f);
	FRotator SpawnRotation = FRotator::ZeroRotator;
	FActorSpawnParameters SpawnInfo;

	// Itera sobre el TMap para generar enemigos por columna
	for (TPair<int32, int32> Elemento : NumeroEnemigosPorColumna)
	{
		int32 Columna = Elemento.Key;
		int32 NumCaballerosEnColumna = Elemento.Value;
		float PosicionXColumna = SpawnOrigin.X + (Columna - 1) * 250.0f; // La posición X se basa en la columna.

		// Bucle de filas en orden inverso para que los caballeros se generen de adelante hacia atrás
		for (int32 Fila = NumCaballerosEnColumna; Fila >= 1; --Fila)
		{
			float PosicionYFila = SpawnOrigin.Y + (Fila - 1) * 200.0f; //  La posición Y se basa en la fila.
			FVector UbicacionCaballero = FVector(PosicionXColumna, PosicionYFila, SpawnOrigin.Z);
			ACaballero* NuevoCaballero = World->SpawnActor<ACaballero>(UbicacionCaballero, SpawnRotation, SpawnInfo);
			if (NuevoCaballero)
			{
				int32 CodigoIdentificador = Columna * 100 + Fila;
				FormacionHorda.Add(CodigoIdentificador, NuevoCaballero);
				Escuadron.Add(NuevoCaballero);
				UE_LOG(LogTemp, Warning, TEXT("Generado Caballero con codigo %d en la columna %d y fila %d."), CodigoIdentificador, Columna, Fila);
			}
		}
	}
}
void AHordaEnemigos::MoverHordaEnX(float Velocidad)
{
	for (ACaballero* Caballero : Escuadron)
	{
		if (Caballero)
		{
			FVector NuevaPosicion = Caballero->GetActorLocation() + FVector(Velocidad, 0.0f, 0.0f);
			Caballero->SetActorLocation(NuevaPosicion);
		}
	}
}

void AHordaEnemigos::MoverHordaEnY(float Velocidad)
{
	for (ACaballero* Caballero : Escuadron)
	{
		if (Caballero)
		{
			FVector NuevaPosicion = Caballero->GetActorLocation() + FVector(0.0f, Velocidad, 0.0f);
			Caballero->SetActorLocation(NuevaPosicion);
		}
	}
}
void AHordaEnemigos::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Solo moverá la horda si la variable booleana es verdadera.
	if (bHordaMoviendose)
	{
		MoverHordaEnY(30.0f * DeltaTime);
		MoverHordaEnX(0.0f * DeltaTime);
	}
}

void AHordaEnemigos::IniciarMovimiento()
{
	UE_LOG(LogTemp, Warning, TEXT("El temporizador ha terminado. La horda comenzara a moverse."));
	bHordaMoviendose = true; // Activa el movimiento.

	// Inicia el temporizador para detener el movimiento después de 10 segundos.
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle_DetenerHorda,
		this,
		&AHordaEnemigos::DetenerMovimiento,
		10.0f,
		false
	);
}
void AHordaEnemigos::DetenerMovimiento()
{
	UE_LOG(LogTemp, Warning, TEXT("El temporizador ha terminado. La horda se detiene."));
	bHordaMoviendose = false; // Desactiva el movimiento.
}
