// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Plataforma.generated.h"

class UStaticMeshComponent;

UCLASS()
class ADVENTUREBOYUSFX_API APlataforma : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlataforma();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Declaraciones de las funciones para cambiar las dimensiones
	UFUNCTION(BlueprintCallable, Category = "Dimensiones")
	float AltoPlataforma(float Alto);
	UFUNCTION(BlueprintCallable, Category = "Dimensiones")
	float AnchoPlataforma(float Ancho);
	UFUNCTION(BlueprintCallable, Category = "Dimensiones")
	float ProfundidadPlataforma(float Profundidad);

protected:
	// Variable para la malla estatica de la plataforma
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Malla")
	UStaticMeshComponent* MallaPlataforma;
};