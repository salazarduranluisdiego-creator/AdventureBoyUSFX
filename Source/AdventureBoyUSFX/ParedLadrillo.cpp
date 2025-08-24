// Fill out your copyright notice in the Description page of Project Settings.


#include "ParedLadrillo.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AParedLadrillo::AParedLadrillo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MallaParedLadrillo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaParedLadrillo"));	
	RootComponent = MallaParedLadrillo;	

	static ConstructorHelpers::FObjectFinder<UStaticMesh> objetoMallaParedLadrillo(TEXT("StaticMesh'/Game/ModelosImportados/Castle_wall_pCube1.Castle_wall_pCube1'"));
	if (objetoMallaParedLadrillo.Succeeded())
	{
		MallaParedLadrillo->SetStaticMesh(objetoMallaParedLadrillo.Object);
	}
}

// Called when the game starts or when spawned
void AParedLadrillo::BeginPlay()
{
	Super::BeginPlay();
	
	UbicacionInicial = GetActorLocation();	
	UbicacionFinal = UbicacionInicial;
	UbicacionFinal.Y += MaxDistancia;
}

// Called every frame
void AParedLadrillo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector UbicacionActual = GetActorLocation();

	float DistanciaRecorrida = FVector::Dist(GetActorLocation(), UbicacionInicial);

	if (bMovimientoDerecha)
	{
		UbicacionActual.Y += Velocidad * DeltaTime;
		if (DistanciaRecorrida >= MaxDistancia)
		{
			bMovimientoDerecha = false;
		}
	}
	else
	{
		UbicacionActual.Y -= Velocidad * DeltaTime;
		if (DistanciaRecorrida <=0.1f)
		{
			bMovimientoDerecha = true;
		}
	}
	SetActorLocation(UbicacionActual);
}

