// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcoArma.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Proyectil.h"
#include "Caballero.h" // Incluimos la definición completa de Caballero aquí.

// Sets default values
AArcoArma::AArcoArma()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ArcoMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ArcoMesh"));
	// Establecer el componente de malla como el componente raíz del actor.
	RootComponent = ArcoMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/ModelosImportados/BOW_AND_ARROW_Cube.BOW_AND_ARROW_Cube'"));

	if (MeshAsset.Succeeded())
	{
		ArcoMesh->SetStaticMesh(MeshAsset.Object);

		// La escala se establece como un vector (X, Y, Z). Para reducir 10 veces,
		ArcoMesh->SetWorldScale3D(FVector(0.1f, 0.1f, 0.1f));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No se pudo encontrar el asset de la malla del arco."));
	}
}

// Called when the game starts or when spawned
void AArcoArma::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AArcoArma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AArcoArma::Disparar()
{
	// Verifica si se ha asignado una clase de proyectil en el editor
	if (ProyectilClass)
	{
		// Obtiene la ubicación y rotación del arma
		FVector SpawnLocation = GetActorLocation();
		FRotator SpawnRotation = GetActorRotation();

		// Genera el proyectil en la ubicación y rotación del arma
		AProyectil* NuevoProyectil = GetWorld()->SpawnActor<AProyectil>(ProyectilClass, SpawnLocation, SpawnRotation);

		// Ejemplo: El arma puede saber quién la está usando a través del puntero CaballeroPortador.
		if (CaballeroPortador.IsValid())
		{
			// Podemos acceder a las funciones y propiedades del caballero.
			FString NombreDelCaballero = CaballeroPortador->GetName();
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("El arco está siendo disparado por: %s"), *NombreDelCaballero));
		}
	}
}