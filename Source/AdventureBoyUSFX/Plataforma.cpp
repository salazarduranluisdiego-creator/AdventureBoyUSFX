// Fill out your copyright notice in the Description page of Project Settings.


#include "Plataforma.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
APlataforma::APlataforma()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 1. Inicializa el componente de la malla y lo hace el RootComponent.
	MallaPlataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaPlataforma"));
	RootComponent = MallaPlataforma;

	// 2. Busca la malla del cubo en la ruta correcta del motor
	static ConstructorHelpers::FObjectFinder<UStaticMesh> objetoCubo(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (objetoCubo.Succeeded())
	{
		// 3. Asigna la malla del cubo a la MallaPlataforma, que ahora es un puntero valido.
		MallaPlataforma->SetStaticMesh(objetoCubo.Object);
	}

	// 4. CORRECCIÓN: Escala el actor, no solo el componente de la malla
	// Los valores son: X (largo), Y (ancho), Z (alto)
	SetActorScale3D(FVector(1.0f, 1.0f, 0.1f));
}

// Called when the game starts or when spawned
void APlataforma::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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