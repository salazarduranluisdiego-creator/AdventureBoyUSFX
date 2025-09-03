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

	Moverse(DeltaTime);
}

void AParedLadrillo::Moverse(float DeltaTime)
{
	FVector UbicacionActual = GetActorLocation();

	float DistanciaRecorrida = FVector::Dist(UbicacionActual, UbicacionInicial);

	if (bMovimientoDerecha)
	{
		UbicacionActual.Y += velocidad * DeltaTime;
		if (DistanciaRecorrida >= MaxDistancia)
		{
			bMovimientoDerecha = false;
		}
	}
	else
	{
		UbicacionActual.Y -= velocidad * DeltaTime;
		if (DistanciaRecorrida <= 10.0f)
		{
			bMovimientoDerecha = true;
		}
	}

	SetActorLocation(UbicacionActual);
}

