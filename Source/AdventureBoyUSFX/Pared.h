// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "Pared.generated.h"


UCLASS()
class ADVENTUREBOYUSFX_API APared : public AObstaculo
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APared();

protected:
	// La malla y los metodos BeginPlay y Tick se heredan de AObstaculo.
	virtual void BeginPlay() override;

	virtual void Moverse(float DeltaTime) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};