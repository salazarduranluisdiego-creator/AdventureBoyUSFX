// Fill out your copyright notice in the Description page of Project Settings.


#include "Plataforma.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
APlataforma::APlataforma()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Inicializa el componente de la malla y lo hace el RootComponent.
	MallaPlataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaPlataforma"));
	RootComponent = MallaPlataforma;

	// Busca la malla del cubo en la ruta correcta del motor
	static ConstructorHelpers::FObjectFinder<UStaticMesh> objetoCubo(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (objetoCubo.Succeeded())
	{
		// Asigna la malla del cubo a la MallaPlataforma, que ahora es un puntero valido.
		MallaPlataforma->SetStaticMesh(objetoCubo.Object);
	}

	// CORRECCIÓN: Escala el actor, no solo el componente de la malla
	// Los valores son: X (largo), Y (ancho), Z (alto)
	SetActorScale3D(FVector(1.0f, 1.0f, 0.1f));

	VelocidadMovimiento = 100.0f; // Velocidad del movimiento
	LimiteMovimiento = 200.0f;   // Distancia total del movimiento
	bMoviendose = false;         // Bandera para activar el movimiento
	bMovimientoY = false;
	bMovimientoVertical = false;
	bMovimientoDiagonalXY = false;
	bMovimientoDiagonalXZ = false;
}

// Called when the game starts or when spawned
void APlataforma::BeginPlay()
{
	Super::BeginPlay();

	PosicionInicial = GetActorLocation();

}

// Called every frame
void APlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bMoviendose)
	{
		FVector CurrentLocation = GetActorLocation();

		// LÓGICA DE MOVIMIENTO VERTICAL
		if (bMovimientoVertical)
		{
			CurrentLocation.Z += VelocidadMovimiento * DeltaTime;
			SetActorLocation(CurrentLocation);

			// Comprueba si la plataforma ha alcanzado el límite de movimiento
			if (FVector::Distance(PosicionInicial, CurrentLocation) >= LimiteMovimiento)
			{
				// Invierte la dirección del movimiento
				VelocidadMovimiento *= -1;
				// Reinicia la posición inicial para el nuevo tramo del movimiento
				PosicionInicial = GetActorLocation();
			}
		}
		// LÓGICA DE MOVIMIENTO Y
		else if (bMovimientoY)
		{
			CurrentLocation.Y += VelocidadMovimiento * DeltaTime;
			SetActorLocation(CurrentLocation); // Mueve la plataforma

			if (FVector::Distance(PosicionInicial, CurrentLocation) >= LimiteMovimiento)
			{
				VelocidadMovimiento *= -1;
				PosicionInicial = GetActorLocation();
			}
		}
		else if (bMovimientoDiagonalXY)
		{
			CurrentLocation.X += VelocidadMovimiento * DeltaTime;
			CurrentLocation.Y += VelocidadMovimiento * DeltaTime;
			SetActorLocation(CurrentLocation);
			if (FVector::Distance(PosicionInicial, CurrentLocation) >= LimiteMovimiento)
			{
				VelocidadMovimiento *= -1;
				PosicionInicial = GetActorLocation();
			}
		}
		else if (bMovimientoDiagonalXZ)
		{
			CurrentLocation.X += VelocidadMovimiento * DeltaTime;
			CurrentLocation.Z += VelocidadMovimiento * DeltaTime;
			SetActorLocation(CurrentLocation);
			if (FVector::Distance(PosicionInicial, CurrentLocation) >= LimiteMovimiento)
			{
				VelocidadMovimiento *= -1;
				PosicionInicial = GetActorLocation();
			}
		}
		else // Lógica de movimiento horizontal
		{
			CurrentLocation.X += VelocidadMovimiento * DeltaTime;
			SetActorLocation(CurrentLocation);

			// Comprueba si la plataforma ha alcanzado el límite de movimiento
			if (FVector::Distance(PosicionInicial, CurrentLocation) >= LimiteMovimiento)
			{
				// Invierte la dirección del movimiento
				VelocidadMovimiento *= -1;
				// Reinicia la posición inicial para el nuevo tramo del movimiento
				PosicionInicial = GetActorLocation();
			}
		}
	}
}

// Implementación de la función para cambiar y devolver el alto
float APlataforma::AltoPlataforma(float Alto)
{
	if (MallaPlataforma)
	{
		FVector EscalaActual = GetActorScale3D();
		SetActorScale3D(FVector(EscalaActual.X, EscalaActual.Y, Alto));
		return GetActorScale3D().Z;
	}
	return 0.0f;
}

// Implementación de la función para cambiar y devolver el ancho
float APlataforma::AnchoPlataforma(float Ancho)
{
	if (MallaPlataforma)
	{
		FVector EscalaActual = GetActorScale3D();
		SetActorScale3D(FVector(EscalaActual.X, Ancho, EscalaActual.Z));
		return GetActorScale3D().Y;
	}
	return 0.0f;
}

// Implementación de la función para cambiar y devolver la profundidad
float APlataforma::ProfundidadPlataforma(float Profundidad)
{
	if (MallaPlataforma)
	{
		FVector EscalaActual = GetActorScale3D();
		SetActorScale3D(FVector(Profundidad, EscalaActual.Y, EscalaActual.Z));
		return GetActorScale3D().X;
	}
	return 0.0f;
}