// Fill out your copyright notice in the Description page of Project Settings.

#include "Pilar.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APilar::APilar()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APilar::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APilar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Moverse(DeltaTime);
}
