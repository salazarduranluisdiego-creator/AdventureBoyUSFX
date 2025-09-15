// Fill out your copyright notice in the Description page of Project Settings.

#include "Caballero.h"
#include "EnemigoSoldado.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "ArcoArma.h"

// Sets default values
ACaballero::ACaballero()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Se elimina la creacion en el constructor para evitar errores.
	// El objeto se generará en BeginPlay.

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> EsqueletoAsset(TEXT("SkeletalMesh'/Game/ModelosImportados/Dwarf_Idle.Dwarf_Idle'"));
	if (EsqueletoAsset.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(EsqueletoAsset.Object);
	}

	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
}

// Called when the game starts or when spawned
void ACaballero::BeginPlay()
{
	Super::BeginPlay();

	// Verificamos si la clase del arco ha sido asignada en el editor.
	if (ArcoArmaClass)
	{
		// Genera una instancia del ArcoArma.
		ArcoInstance = GetWorld()->SpawnActor<AArcoArma>(ArcoArmaClass);

		if (ArcoInstance)
		{
			// ¡Aquí está la clave! Ligamos el arco al caballero.
			// `this` se refiere a la instancia actual del caballero.
			ArcoInstance->CaballeroPortador = this;

			// Adjunta el arma a la malla del caballero.
			// Asegúrate de que el nombre del socket ("hand_rSocket") exista en tu esqueleto.
			FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
			ArcoInstance->AttachToComponent(GetMesh(), AttachmentRules, FName("hand_rSocket"));
		}
	}
}

// Called every frame
void ACaballero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACaballero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACaballero::DispararConArco()
{
	// Verificamos si la instancia del arco existe y es válida.
	if (ArcoInstance)
	{
		// Llamamos a la función Disparar del arco.
		ArcoInstance->Disparar();
	}
}

