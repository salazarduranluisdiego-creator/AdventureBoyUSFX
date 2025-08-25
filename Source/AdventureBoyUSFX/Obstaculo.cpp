// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstaculo.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AObstaculo::AObstaculo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize properties
	MallaObstaculo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaObstaculo"));
	RootComponent = MallaObstaculo;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> objetoMallaObstaculo(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));	

	if (objetoMallaObstaculo.Succeeded())
	{
		MallaObstaculo->SetStaticMesh(objetoMallaObstaculo.Object);
		//MallaBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		UE_LOG(LogTemp, Warning, TEXT("Malla de Obstaculo cargada correctamente"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No se pudo cargar la malla en Obstaculo"));
	}

}
void AObstaculo::Moverse(float Deltatime)
{
	// Implement movement logic here if needed
	// This function can be overridden by derived classes
}
// Called when the game starts or when spawned
void AObstaculo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstaculo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Moverse(DeltaTime);

}


