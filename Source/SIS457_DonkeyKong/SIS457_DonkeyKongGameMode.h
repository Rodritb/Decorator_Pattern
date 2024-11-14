// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DecoradorInterface.h"
#include "GameFramework/GameModeBase.h"
#include "SIS457_DonkeyKongGameMode.generated.h"
UCLASS(minimalapi)
class ASIS457_DonkeyKongGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASIS457_DonkeyKongGameMode();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	IDecoradorInterface* Jugador;
};