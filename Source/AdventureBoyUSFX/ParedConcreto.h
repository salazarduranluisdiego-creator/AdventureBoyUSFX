// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pared.h"
#include "ParedConcreto.generated.h"

UCLASS()
class ADVENTUREBOYUSFX_API AParedConcreto : public APared
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParedConcreto();

protected:
	//Declaracion de la malla especifica para la pared de concreto
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category ="Mesh")
	class UStaticMeshComponent* MallaParedConcreto;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Moverse(float DeltaTime) override;	

};
