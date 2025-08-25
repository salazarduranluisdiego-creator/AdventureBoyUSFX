// Fill out your copyright notice in the Description page of Project Settings.


#include "PilarSimple.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APilarSimple::APilarSimple()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Cargar la malla del pilar simple.
	static ConstructorHelpers::FObjectFinder<UStaticMesh> objetoMallaPilarSimple(TEXT("StaticMesh'/Game/ModelosImportados/Castle_wall_pCylinder1.Castle_wall_pCylinder1'"));
	if (objetoMallaPilarSimple.Succeeded())
	{
		// Usar el componente de malla heredado y asignarle el static mesh.
		MallaObstaculo->SetStaticMesh(objetoMallaPilarSimple.Object);
	}
}

// Called when the game starts or when spawned
void APilarSimple::BeginPlay()
{
	Super::BeginPlay();
	UbicacionInicial = GetActorLocation();
}

// Called every frame
void APilarSimple::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Moverse(DeltaTime);
}

void APilarSimple::Moverse(float DeltaTime)
{
	// Implementación del movimiento para el pilar simple
	FVector UbicacionActual = GetActorLocation();

	float DistanciaRecorrida = FVector::Dist(UbicacionActual, UbicacionInicial);

	if (bMovimientoDerecha)
	{
		UbicacionActual.Z += velocidad * DeltaTime;
		if (DistanciaRecorrida >= MaxDistancia)
		{
			bMovimientoDerecha = false;
		}
	}
	else
	{
		UbicacionActual.Z -= velocidad * DeltaTime;
		if (DistanciaRecorrida <= 10.0f)
		{
			bMovimientoDerecha = true;
		}
	}
	SetActorLocation(UbicacionActual);
}