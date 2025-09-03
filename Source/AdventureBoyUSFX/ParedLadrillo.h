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
	// La malla se hereda de la clase padre (Pared, que a su vez hereda de Obstaculo).
	// Ya no se necesita una nueva variable de malla aquí.

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Moverse(float DeltaTime) override;
};