// Fill out your copyright notice in the Description page of Project Settings.

#include "Pilar.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APilar::APilar()
{
	// Permite que el actor sea "tickeable"
	PrimaryActorTick.bCanEverTick = true;

	// Busca la malla del cilindro en el contenido del motor.
	static ConstructorHelpers::FObjectFinder<UStaticMesh> objetoMallaPilar(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));

	// Si la malla se carga correctamente, la asigna al componente MallaObstaculo que hereda
	if (objetoMallaPilar.Succeeded())
	{
		// ASIGNA LA MALLA AL COMPONENTE HEREDADO (MallaObstaculo)
		MallaObstaculo->SetStaticMesh(objetoMallaPilar.Object);
		// Opcional: Escala el pilar para que se vea más alto
		MallaObstaculo->SetWorldScale3D(FVector(0.5f, 0.5f, 2.0f));
		UE_LOG(LogTemp, Warning, TEXT("Malla de Pilar cargada correctamente"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No se pudo cargar la malla en Pilar"));
	}
}

// Called when the game starts or when spawned
void APilar::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APilar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Moverse(DeltaTime);
}