// Fill out your copyright notice in the Description page of Project Settings.


#include "Proyectil.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AProyectil::AProyectil()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProyectilMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProyectilMesh"));
	RootComponent = ProyectilMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/ModelosImportados/BOW_AND_ARROW_Cylinder_001.BOW_AND_ARROW_Cylinder_001'"));

	if (MeshAsset.Succeeded())
	{
		ProyectilMesh->SetStaticMesh(MeshAsset.Object);

		// Opcional: ajustar la escala si el modelo es muy grande o pequeño.
		ProyectilMesh->SetWorldScale3D(FVector(0.2f,0.2f, 0.2f));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No se pudo encontrar el asset de la malla del proyectil."));
	}
	// Crea y configura el componente de movimiento.
	ProyectilMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProyectilMovement"));
	ProyectilMovement->InitialSpeed = 1000.0f; // Velocidad inicial del proyectil
	ProyectilMovement->MaxSpeed = 1000.0f; // Velocidad máxima del proyectil
	ProyectilMovement->ProjectileGravityScale = 0.0f; // Elimina la gravedad para que vaya en línea recta.
}

// Called when the game starts or when spawned
void AProyectil::BeginPlay()
{
	Super::BeginPlay();
	
	// Hace que el proyectil desaparezca 5 segundos después de ser generado.
	SetLifeSpan(5.0f);
}

// Called every frame
void AProyectil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

