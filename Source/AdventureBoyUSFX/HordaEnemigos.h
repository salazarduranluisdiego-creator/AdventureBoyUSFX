// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Caballero.h"
#include "HordaEnemigos.generated.h"

UCLASS()
class ADVENTUREBOYUSFX_API AHordaEnemigos : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHordaEnemigos();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// La clase de enemigo que se generará, la configuras en el editor.
	UPROPERTY(EditAnywhere, Category = "Spawn Settings")
	TSubclassOf<ACaballero> ClaseCaballero;

	// Un TMap para controlar el número de enemigos por cada fila.
	UPROPERTY(EditAnywhere, Category = "Spawn Settings")
	TMap<int32, int32> NumeroEnemigosPorColumna;

	// Un TMap para guardar la ubicación de los caballeros en un formato de código.
	UPROPERTY()
	TMap<int32, ACaballero*> FormacionHorda;

	// Un TArray para guardar todas las instancias de Caballero creadas.
	UPROPERTY()
	TArray<ACaballero*> Escuadron;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
	bool bHordaMoviendose; // Variable para controlar el movimiento.

	// Nueva variable para manejar el temporizador
	FTimerHandle TimerHandle_MoverHorda;
	FTimerHandle TimerHandle_DetenerHorda;

public: 

	// Se le asigna un valor por defecto para no tener que especificarlo cada vez que se llama a la función
	UFUNCTION(BlueprintCallable, Category = "Movimiento Horda")
	void MoverHordaEnX(float Velocidad = 100.0f);

	UFUNCTION(BlueprintCallable, Category = "Movimiento Horda")
	void MoverHordaEnY(float Velocidad = 100.0f);

private:
	// Función para generar la horda de caballeros.
	void GenerarHorda();

	// Nueva función que será llamada por el temporizador
	void IniciarMovimiento();
	void DetenerMovimiento(); 
};