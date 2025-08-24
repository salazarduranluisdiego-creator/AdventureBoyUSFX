// Fill out your copyright notice in the Description page of Project Settings.


#include "ParedConcreto.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AParedConcreto::AParedConcreto()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MallaParedConcreto = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaParedConcreto"));	
	RootComponent = MallaParedConcreto;	

	static ConstructorHelpers::FObjectFinder<UStaticMesh> objetoMallaParedConcreto(TEXT("StaticMesh'/Game/ModelosImportados/Concrete_wall.Concrete_wall'"));	
if (objetoMallaParedConcreto.Succeeded())
{
	MallaParedConcreto->SetStaticMesh(objetoMallaParedConcreto.Object);
}
}

// Called when the game starts or when spawned
void AParedConcreto::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AParedConcreto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

