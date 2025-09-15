// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pared.h"
#include "ParedLadrillo.generated.h"

UCLASS()
class ADVENTUREBOYUSFX_API AParedLadrillo : public APared
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AParedLadrillo();

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	FVector PosicionInicialPared;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	float VelocidadMovimientoPared;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	float LimiteMovimientoPared;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	bool bMoviendosePared;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	bool bMovimientoVerticalPared = false;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	bool bMovimientoYPared = false;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	bool bMovimientoDiagonalXYPared = false;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	bool bMovimientoDiagonalXZPared = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};