// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pilar.h" // Incluye la clase padre
#include "PilarSimple.generated.h"

UCLASS()
class ADVENTUREBOYUSFX_API APilarSimple : public APilar
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APilarSimple();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Sobrescribe el método Moverse de la clase padre (AObstaculo)
	virtual void Moverse(float DeltaTime) override;
};