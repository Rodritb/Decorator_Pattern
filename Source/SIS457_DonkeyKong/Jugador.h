// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DecoradorInterface.h"
#include "GameFramework/Actor.h"
#include "Jugador.generated.h"
UCLASS()
class SIS457_DONKEYKONG_API AJugador : public AActor, public IDecoradorInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AJugador();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	void Empezar() override;
	FString Estado() override;
	FString ObtenerAtributos() override;
	float Duracion() override;
};