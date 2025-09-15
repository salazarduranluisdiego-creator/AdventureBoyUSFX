// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Plataforma.h"
#include "CaminoPlataformas.generated.h"

UCLASS()
class ADVENTUREBOYUSFX_API ACaminoPlataformas : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACaminoPlataformas();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Un arreglo para guardar las plataformas generadas
	UPROPERTY()
	TArray<APlataforma*> PlataformasGeneradas;

	// Variables que controlan la generacion
	UPROPERTY(EditAnywhere, Category = "Generacion")
	float SeparacionEntrePlataformas;

	// Un TMap para controlar el numero de plataformas por cada nivel (piso).
	UPROPERTY(EditAnywhere, Category = "Generacion")
	TMap<int32, int32> ComponentesPorPiso;

	UPROPERTY()
	TMap<int32, APlataforma*> MapaDePlataformas;
	UPROPERTY()
	int32 ContadorMovimiento;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SeleccionarPlataformaManualmente(int32 CodigoPlataforma, int32 AccionPlataforma);

	void MoverPlataformaAleatoria();

	void MoverPlataforma203();

private:
	// Función para generar las plataformas
	void GenerarCamino();
};