#pragma once
#include "CoreMinimal.h"
#include "Arma.h"
#include "Proyectil.h"
#include "Components/StaticMeshComponent.h"
#include "ArcoArma.generated.h"
// Declaración de reenvío: le dice al compilador que la clase ACaballero existe.
class ACaballero;
UCLASS()
class ADVENTUREBOYUSFX_API AArcoArma : public AArma
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AArcoArma();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Componente para la malla del arco.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* ArcoMesh;

	// Variable para especificar la clase de Proyectil que se generará.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Disparo")
	TSubclassOf<AProyectil> ProyectilClass;

	// Función para disparar un proyectil.
	UFUNCTION(BlueprintCallable, Category = "Disparo")
	void Disparar();

	// Puntero para referenciar al caballero que usa esta arma.
	UPROPERTY()
	TWeakObjectPtr<ACaballero> CaballeroPortador;
};