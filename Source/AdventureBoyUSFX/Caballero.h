// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h" // Incluye el encabezado de la clase padre
#include "Caballero.generated.h"

UCLASS()
class ADVENTUREBOYUSFX_API ACaballero : public AEnemigo
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACaballero();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
