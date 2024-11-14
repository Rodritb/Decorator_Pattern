// Copyright Epic Games, Inc. All Rights Reserved.

#include "SIS457_DonkeyKongGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "Jugador.h"
#include "EscudoDecorador.h"
#include "DisparoDecorador.h"

ASIS457_DonkeyKongGameMode::ASIS457_DonkeyKongGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ASIS457_DonkeyKongGameMode::BeginPlay()
{
	Super::BeginPlay();
	/*//Engendramos al jugador principal
	AJugador* JugadorPrincipal = GetWorld()->SpawnActor<AJugador>(AJugador::StaticClass());

	//Engendramos un decorador para correr en el jugador principal
	ADisparoDecorador* Disparo = GetWorld()->SpawnActor<ADisparoDecorador>(ADisparoDecorador::StaticClass());
	Disparo->SetJugador(JugadorPrincipal);

	Jugador = Disparo;
	Jugador->Empezar();
	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Cyan,
		FString::Printf(TEXT("Jugador ahora esta en %s"), *Jugador->Estado()));
	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Cyan,
		FString::Printf(TEXT("Jugador ahora tiene los atributos de %s"), *Jugador->ObtenerAtributos()));
	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Cyan,
		FString::Printf(TEXT("Su duracion es de %.2f"), Jugador->Duracion()));


	//Engendramos un decorador para un escudo en el jugador principal
	AEscudoDecorador* Escudo = GetWorld()->SpawnActor<AEscudoDecorador>(AEscudoDecorador::StaticClass());
	Escudo->SetJugador(Disparo);

	Jugador = Escudo;
	Jugador->Empezar();
	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Emerald,
		FString::Printf(TEXT("Jugador ahora esta en %s"), *Jugador->Estado()));
	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Emerald,
		FString::Printf(TEXT("Jugador ahora tiene los atributos de %s"), *Jugador->ObtenerAtributos()));
	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Emerald,
		FString::Printf(TEXT("Su duracion es de %.2f"), Jugador->Duracion()));*/
}

void ASIS457_DonkeyKongGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}