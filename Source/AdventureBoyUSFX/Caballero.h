// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "EnemigoSoldado.h" 
#include "ArcoArma.h"
#include "Caballero.generated.h"

UCLASS()
class ADVENTUREBOYUSFX_API ACaballero : public AEnemigoSoldado
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACaballero();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arma")
	TSubclassOf<AArcoArma> ArcoArmaClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Función que el caballero usará para disparar con su arco.
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void DispararConArco();

private:
	// Puntero para guardar la instancia del arma generada.
	// Usamos un puntero crudo ya que funciona en todas las versiones de UE4.
	UPROPERTY()
	AArcoArma* ArcoInstance;
};
