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
	AParedConcreto();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void Moverse(float DeltaTime) override;

};