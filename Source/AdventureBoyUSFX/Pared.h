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
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
