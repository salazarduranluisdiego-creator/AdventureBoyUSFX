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

protected:
	//Nueva variable para la amlla especifica de ParedLaadrillo
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	class UStaticMeshComponent* MallaParedLadrillo;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Velocidad = 150.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MaxDistancia = 200.0f;

	FVector UbicacionInicial;
	FVector UbicacionFinal;
	bool bMovimientoDerecha = true;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
