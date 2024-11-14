// Fill out your copyright notice in the Description page of Project Settings.


#include "DecoradorBase.h"

// Sets default values
ADecoradorBase::ADecoradorBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADecoradorBase::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADecoradorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADecoradorBase::SetJugador(AActor* _Jugador)
{
	Jugador = Cast<IDecoradorInterface>(_Jugador);
	if (!Jugador)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("No se realizo la conversion a tipo DecoradorInterface")));
	}
}

void ADecoradorBase::Empezar()
{
	if (!Jugador)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Estado(): Jugador es null")));
		return;
	}
	else
	{
		return Jugador->Empezar();
	}
}

FString ADecoradorBase::Estado()
{
	if (!Jugador)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Estado(): Jugador es null")));
		return " ";
	}
	else
	{
		return Jugador->Estado();
	}
}

FString ADecoradorBase::ObtenerAtributos()
{
	if (!Jugador)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Estado(): Jugador es null")));
		return " ";
	}
	else
	{
		return Jugador->ObtenerAtributos();
	}
}

float ADecoradorBase::Duracion()
{
	if (!Jugador)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Purple, FString::Printf(TEXT("Estado(): Jugador es null")));
		return 0.f;
	}
	else
	{
		return Jugador->Duracion();
	}
}
