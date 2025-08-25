// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h" // Ahora hereda de AObstaculo
#include "Pilar.generated.h"

UCLASS()
class ADVENTUREBOYUSFX_API APilar : public AObstaculo
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APilar();

protected:
	// La malla del pilar, que será común para todos los pilares
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Malla")
	UStaticMeshComponent* MallaPilar;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};