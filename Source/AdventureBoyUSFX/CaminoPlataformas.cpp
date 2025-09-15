// Fill out your copyright notice in the Description page of Project Settings.


#include "CaminoPlataformas.h"
#include "Engine/World.h"
#include "Plataforma.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ACaminoPlataformas::ACaminoPlataformas() :
	SeparacionEntrePlataformas(300.0f)
{
	PrimaryActorTick.bCanEverTick = true;
	ComponentesPorPiso = { {1, 5}, {2, 4}, {3, 2},{4, 5 } };
	ContadorMovimiento = 0; // Inicializamos el contador en 0
}

// Called when the game starts or when spawned
void ACaminoPlataformas::BeginPlay()
{
	Super::BeginPlay();

	// Llama a la función de generación cuando el juego inicia
	GenerarCamino();

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ACaminoPlataformas::MoverPlataformaAleatoria, 5.0f, true);
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
		FVector SpawnLocation = FVector(-600.0f, 50.0f, 500.0f);
		FRotator SpawnRotation = FRotator::ZeroRotator;
		FActorSpawnParameters SpawnInfo;

		for (TPair<int32, int32> Elemento : ComponentesPorPiso)
		{
			int32 Piso = Elemento.Key;
			int32 NumPlataformas = Elemento.Value;

			// Mueve la altura de spawn para cada nuevo piso, pero a partir de la POSICIÓN DE INICIO Z.

			float AlturaPiso = SpawnLocation.Z + (Piso - 1) * 200.0f;

			FVector PosicionActual = FVector(-600.0f, SpawnLocation.Y, AlturaPiso);

			for (int i = 0; i < NumPlataformas; ++i)
			{
				FVector UbicacionPlataforma = FVector(PosicionActual.X, PosicionActual.Y, AlturaPiso);
				APlataforma* NuevaPlataforma = World->SpawnActor<APlataforma>(UbicacionPlataforma, SpawnRotation, SpawnInfo);

				if (NuevaPlataforma)
				{
					PlataformasGeneradas.Add(NuevaPlataforma);

					int32 CodigoUbicacion = Piso * 100 + (i + 1);
					MapaDePlataformas.Add(CodigoUbicacion, NuevaPlataforma);

					// Actualiza la posición X para la siguiente plataforma
					PosicionActual.X += SeparacionEntrePlataformas;
				}
			}
		}
	}
}
void ACaminoPlataformas::MoverPlataformaAleatoria()
{
	if (MapaDePlataformas.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No hay plataformas en el mapa para mover."));
		return;
	}

	// Selecciona un piso al azar
	TArray<int32> Keys;
	ComponentesPorPiso.GetKeys(Keys);
	int32 RandomPiso = FMath::RandRange(0, Keys.Num() - 1);
	int32 PisoElegido = Keys[RandomPiso];

	// Selecciona un número de plataforma al azar de ese piso
	int32 NumPlataformasEnPiso = ComponentesPorPiso[PisoElegido];
	int32 PlataformaElegida = FMath::RandRange(1, NumPlataformasEnPiso);

	// Calcula el código único para obtener la plataforma del mapa
	int32 CodigoPlataforma = PisoElegido * 100 + PlataformaElegida;

	// Obtiene la plataforma del TMap
	APlataforma** PlataformaEncontrada = MapaDePlataformas.Find(CodigoPlataforma);

	if (PlataformaEncontrada)
	{
		APlataforma* PlataformaAMover = *PlataformaEncontrada;
		// Alterna el estado de movimiento.
		if (PlataformaAMover->bMoviendose)
		{
			// Si la plataforma ya se está moviendo, la detiene.
			PlataformaAMover->bMoviendose = false;
			PlataformaAMover->VelocidadMovimiento = FMath::Abs(PlataformaAMover->VelocidadMovimiento);
			PlataformaAMover->PosicionInicial = PlataformaAMover->GetActorLocation();
			UE_LOG(LogTemp, Warning, TEXT("Se ha detenido el movimiento de la plataforma con codigo %d"), CodigoPlataforma);
		}
		else
		{
			if (ContadorMovimiento == 0)
			{
				PlataformaAMover->bMoviendose = true;
				PlataformaAMover->bMovimientoVertical = false; // Mueve en X
				PlataformaAMover->bMovimientoY = false;
				PlataformaAMover->bMovimientoDiagonalXY = false;
				PlataformaAMover->bMovimientoDiagonalXZ = false;
				UE_LOG(LogTemp, Warning, TEXT("Se ha activado el movimiento horizontal (X) para la plataforma %d"), CodigoPlataforma);
			}
			else if (ContadorMovimiento == 1)
			{
				PlataformaAMover->bMoviendose = true;
				PlataformaAMover->bMovimientoVertical = true; // Mueve en Z
				PlataformaAMover->bMovimientoY = false;
				PlataformaAMover->bMovimientoDiagonalXY = false;
				PlataformaAMover->bMovimientoDiagonalXZ = false;
				UE_LOG(LogTemp, Warning, TEXT("Se ha activado el movimiento vertical (Z) para la plataforma %d"), CodigoPlataforma);
			}
			else if (ContadorMovimiento == 2)
			{
				PlataformaAMover->bMoviendose = true;
				PlataformaAMover->bMovimientoVertical = false;
				PlataformaAMover->bMovimientoY = true; // Mueve en Y
				PlataformaAMover->bMovimientoDiagonalXY = false;
				PlataformaAMover->bMovimientoDiagonalXZ = false;
				UE_LOG(LogTemp, Warning, TEXT("Se ha activado el movimiento horizontal (Y) para la plataforma %d"), CodigoPlataforma);
			}
			else if (ContadorMovimiento == 3)
			{
				PlataformaAMover->bMoviendose = true;
				PlataformaAMover->bMovimientoVertical = false;
				PlataformaAMover->bMovimientoY = false;
				PlataformaAMover->bMovimientoDiagonalXY = true; // Mueve en diagonal XY
				PlataformaAMover->bMovimientoDiagonalXZ = false;
				UE_LOG(LogTemp, Warning, TEXT("Se ha activado el movimiento diagonal XY para la plataforma %d"), CodigoPlataforma);
			}
			else
			{
				PlataformaAMover->bMoviendose = true;
				PlataformaAMover->bMovimientoVertical = false;
				PlataformaAMover->bMovimientoY = false;
				PlataformaAMover->bMovimientoDiagonalXY = false;
				PlataformaAMover->bMovimientoDiagonalXZ = true; // Mueve en diagonal XZ
				UE_LOG(LogTemp, Warning, TEXT("Se ha activado el movimiento diagonal XZ para la plataforma %d"), CodigoPlataforma);
			}

			// Actualiza el contador y lo resetea a 0 si llega a 5.
			ContadorMovimiento = (ContadorMovimiento + 1) % 5;
		}
	}
}
// Nueva función agregada aquí, al final del archivo.
void ACaminoPlataformas::SeleccionarPlataformaManualmente(int32 CodigoPlataforma, int32 AccionPlataforma)
{
	APlataforma** PlataformaEncontrada = MapaDePlataformas.Find(CodigoPlataforma);

	if (PlataformaEncontrada)
	{
		APlataforma* PlataformaAMover = *PlataformaEncontrada;

		// Apaga todos los movimientos para evitar conflictos.
		PlataformaAMover->bMoviendose = false;
		PlataformaAMover->bMovimientoVertical = false;
		PlataformaAMover->bMovimientoY = false;
		PlataformaAMover->bMovimientoDiagonalXY = false;
		PlataformaAMover->bMovimientoDiagonalXZ = false;
		PlataformaAMover->VelocidadMovimiento = FMath::Abs(PlataformaAMover->VelocidadMovimiento);
		PlataformaAMover->PosicionInicial = PlataformaAMover->GetActorLocation();

		// Asigna el movimiento según el valor de AccionPlataforma.
		switch (AccionPlataforma)
		{
		case 0: // Mover en X
			PlataformaAMover->bMoviendose = true;
			UE_LOG(LogTemp, Warning, TEXT("Se ha activado el movimiento horizontal (X) para la plataforma %d"), CodigoPlataforma);
			break;
		case 1: // Mover en Z
			PlataformaAMover->bMoviendose = true;
			PlataformaAMover->bMovimientoVertical = true;
			UE_LOG(LogTemp, Warning, TEXT("Se ha activado el movimiento vertical (Z) para la plataforma %d"), CodigoPlataforma);
			break;
		case 2: // Mover en Y
			PlataformaAMover->bMoviendose = true;
			PlataformaAMover->bMovimientoY = true;
			UE_LOG(LogTemp, Warning, TEXT("Se ha activado el movimiento horizontal (Y) para la plataforma %d"), CodigoPlataforma);
			break;
		case 3: // Mover en diagonal XY
			PlataformaAMover->bMoviendose = true;
			PlataformaAMover->bMovimientoDiagonalXY = true;
			UE_LOG(LogTemp, Warning, TEXT("Se ha activado el movimiento diagonal XY para la plataforma %d"), CodigoPlataforma);
			break;
		case 4: // Mover en diagonal XZ
			PlataformaAMover->bMoviendose = true;
			PlataformaAMover->bMovimientoDiagonalXZ = true;
			UE_LOG(LogTemp, Warning, TEXT("Se ha activado el movimiento diagonal XZ para la plataforma %d"), CodigoPlataforma);
			break;
		default:
			UE_LOG(LogTemp, Warning, TEXT("Accion de plataforma no valida. Ningun movimiento ha sido asignado."));
			break;
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No se encontro una plataforma con el codigo %d."), CodigoPlataforma);
	}
}
void ACaminoPlataformas::MoverPlataforma203()
{
	// Llama a la función principal con los valores fijos.
	SeleccionarPlataformaManualmente(203, 4);
}