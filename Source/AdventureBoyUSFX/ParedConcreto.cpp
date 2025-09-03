// Fill out your copyright notice in the Description page of Project Settings.


#include "ParedConcreto.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AParedConcreto::AParedConcreto()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> objetoMallaParedConcreto(TEXT("StaticMesh'/Game/ModelosImportados/Concrete_wall.Concrete_wall'"));
	if (objetoMallaParedConcreto.Succeeded())
	{
		MallaObstaculo->SetStaticMesh(objetoMallaParedConcreto.Object);
	}
}

void AParedConcreto::BeginPlay()
{
	Super::BeginPlay();

}

void AParedConcreto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Moverse(DeltaTime);

}

// Aqu� est� la correcci�n: se a�ade la definici�n de la funci�n Moverse
void AParedConcreto::Moverse(float DeltaTime)
{
	// A�ADE AQUI LA LOGICA DE MOVIMIENTO SI ES NECESARIO
}