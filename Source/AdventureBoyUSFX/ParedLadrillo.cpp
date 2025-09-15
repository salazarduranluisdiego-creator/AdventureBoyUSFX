// Fill out your copyright notice in the Description page of Project Settings.


#include "ParedLadrillo.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AParedLadrillo::AParedLadrillo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> objetoMallaParedLadrillo(TEXT("StaticMesh'/Game/ModelosImportados/Castle_wall_pCube1.Castle_wall_pCube1'"));
	if (objetoMallaParedLadrillo.Succeeded())
	{
		MallaObstaculo->SetStaticMesh(objetoMallaParedLadrillo.Object);
	}

	VelocidadMovimientoPared = 100.0f; // Velocidad del movimiento
	LimiteMovimientoPared = 200.0f;   // Distancia total del movimiento
	bMoviendosePared = false;         // Bandera para activar el movimiento
	bMovimientoYPared = false;
	bMovimientoVerticalPared = false;
	bMovimientoDiagonalXYPared = false;
	bMovimientoDiagonalXZPared = false;
}

// Called when the game starts or when spawned
void AParedLadrillo::BeginPlay()
{
	Super::BeginPlay();
	
	UbicacionInicial = GetActorLocation();	

}

// Called every frame
void AParedLadrillo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bMoviendosePared)
	{
		FVector CurrentLocation = GetActorLocation();

		// LÓGICA DE MOVIMIENTO VERTICAL
		if (bMovimientoVerticalPared)
		{
			CurrentLocation.Z += VelocidadMovimientoPared * DeltaTime;
			SetActorLocation(CurrentLocation);

			// Comprueba si la plataforma ha alcanzado el límite de movimiento
			if (FVector::Distance(PosicionInicialPared, CurrentLocation) >= LimiteMovimientoPared)
			{
				// Invierte la dirección del movimiento
				VelocidadMovimientoPared *= -1;	
				// Reinicia la posición inicial para el nuevo tramo del movimiento
				PosicionInicialPared = GetActorLocation();
			}
		}
		// LÓGICA DE MOVIMIENTO Y
		else if (bMovimientoYPared)
		{
			CurrentLocation.Y += VelocidadMovimientoPared * DeltaTime;
			SetActorLocation(CurrentLocation); // Mueve la plataforma

			if (FVector::Distance(PosicionInicialPared, CurrentLocation) >= LimiteMovimientoPared)
			{
				VelocidadMovimientoPared *= -1;
				PosicionInicialPared = GetActorLocation();
			}
		}
		else if (bMovimientoDiagonalXYPared)
		{
			CurrentLocation.X += VelocidadMovimientoPared * DeltaTime;
			CurrentLocation.Y += VelocidadMovimientoPared * DeltaTime;
			SetActorLocation(CurrentLocation);
			if (FVector::Distance(PosicionInicialPared, CurrentLocation) >= LimiteMovimientoPared)
			{
				VelocidadMovimientoPared *= -1;
				PosicionInicialPared = GetActorLocation();
			}
		}
		else if (bMovimientoDiagonalXZPared)
		{
			CurrentLocation.X += VelocidadMovimientoPared * DeltaTime;
			CurrentLocation.Z += VelocidadMovimientoPared * DeltaTime;
			SetActorLocation(CurrentLocation);
			if (FVector::Distance(PosicionInicialPared, CurrentLocation) >= LimiteMovimientoPared)
			{
				VelocidadMovimientoPared *= -1;
				PosicionInicialPared = GetActorLocation();
			}
		}
		else // Lógica de movimiento horizontal
		{
			CurrentLocation.X += VelocidadMovimientoPared * DeltaTime;
			SetActorLocation(CurrentLocation);

			// Comprueba si la plataforma ha alcanzado el límite de movimiento
			if (FVector::Distance(PosicionInicialPared, CurrentLocation) >= LimiteMovimientoPared)
			{
				// Invierte la dirección del movimiento
				VelocidadMovimientoPared *= -1;
				// Reinicia la posición inicial para el nuevo tramo del movimiento
				PosicionInicialPared = GetActorLocation();
			}
		}
	}
}


