#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoSoldado.generated.h"

UCLASS()
class ADVENTUREBOYUSFX_API AEnemigoSoldado : public AEnemigo
{
	GENERATED_BODY()

public:
	AEnemigoSoldado();

protected:
	virtual void BeginPlay() override;
};