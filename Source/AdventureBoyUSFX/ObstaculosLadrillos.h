// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParedLadrillo.h"
#include "ObstaculosLadrillos.generated.h"

UCLASS()
class ADVENTUREBOYUSFX_API AObstaculosLadrillos : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstaculosLadrillos();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	TArray<AParedLadrillo*> ParedesLadrillGeneradas;

	UPROPERTY(EditAnywhere, Category = "Generacion")
	float SeparacionEntreParedesLadrillo;

	UPROPERTY()
	int32 ContadorMovimientoLadrillo;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MoverParedLadrilloAleatoria();

private:
	// Función para generar los obstáculos de ladrillo
	void GenerarObstaculosLadrillo1();

};
