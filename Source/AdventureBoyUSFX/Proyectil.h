// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Proyectil.generated.h"

UCLASS()
class ADVENTUREBOYUSFX_API AProyectil : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProyectil();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Componente para la malla del proyectil
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* ProyectilMesh;

	// Componente para manejar el movimiento del proyectil.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movimiento")
	UProjectileMovementComponent* ProyectilMovement;
};
