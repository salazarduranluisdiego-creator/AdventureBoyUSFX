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
	int32 NumeroDePlataformas;

	UPROPERTY(EditAnywhere, Category = "Generacion")
	float SeparacionEntrePlataformas;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Función para generar las plataformas
	void GenerarCamino();
};