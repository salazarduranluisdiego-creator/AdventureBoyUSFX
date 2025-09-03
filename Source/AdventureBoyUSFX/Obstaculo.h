// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstaculo.generated.h"

UCLASS()
class ADVENTUREBOYUSFX_API AObstaculo : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AObstaculo();

protected:
	//La funcion virtual que las clases hijas anularan
	virtual void Moverse(float DeltaTime);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float velocidad = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MaxDistancia = 300.0f;

	FVector UbicacionInicial;
	FVector UbicacionFinal;
	bool bMovimientoDerecha = true;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Malla")
	UStaticMeshComponent* MallaObstaculo;
};
