// Fill out your copyright notice in the Description page of Project Settings.


#include "Jugador.h"

// Sets default values
AJugador::AJugador()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJugador::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AJugador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AJugador::Empezar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Orange, FString::Printf(TEXT("Empezo sin nada")));
}

FString AJugador::Estado()
{
	return " ";
}

FString AJugador::ObtenerAtributos()
{
	return " ";
}

float AJugador::Duracion()
{
	return 0.0f;
}
