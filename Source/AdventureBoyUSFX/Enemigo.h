// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"

#include "Enemigo.generated.h"



UCLASS()
class ADVENTUREBOYUSFX_API AEnemigo : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemigo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* MallaEnemigo;
private: 
	float salud;
	float velocidadMovimiento;
	float velocidadAtaque;
	float VelocidadSalto;
	float velocidadGiro;
	float Armadura;
	float danoAtaque;
	float Nivel;
	float experiencia;

	bool bVivo;
	bool bActivo;

};
