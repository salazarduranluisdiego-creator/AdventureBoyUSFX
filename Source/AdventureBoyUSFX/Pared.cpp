// Fill out your copyright notice in the Description page of Project Settings.

#include "Pared.h"

// Sets default values
APared::APared()
{
	// Set this actor to call Tick() every frame.� You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// No se necesita crear una nueva malla, ya que se hereda de AObstaculo.
	// El componente MallaObstaculo ya existe y es el RootComponent.
}

// Implementaci�n de la funci�n Moverse
void APared::Moverse(float DeltaTime)
{
	// No hace nada por defecto, se implementar� en las clases hijas.
}

// Called when the game starts or when spawned
void APared::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APared::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Moverse(DeltaTime);
}