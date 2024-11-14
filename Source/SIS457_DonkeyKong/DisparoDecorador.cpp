// Fill out your copyright notice in the Description page of Project Settings.


#include "DisparoDecorador.h"
#include "SIS457_DonkeyKong.h"
#include "Jugador.h"
#include "Proyectil.h"
#include "Kismet/GameplayStatics.h"

ADisparoDecorador::ADisparoDecorador()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void ADisparoDecorador::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADisparoDecorador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	proyectilRecord += 1;
	if (proyectilRecord >= 50)
	{
		Empezar();
		proyectilRecord = 0;
	}

}

void ADisparoDecorador::Empezar()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Ahora tiene 2 capas")));

	APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (Player)
	{
		FVector ubicacion = Player->GetActorLocation() + FVector(0.0f, 0.0f, 20.0f);
		FRotator rotacion = Player->GetActorRotation();
		AProyectil* NewProj0 = GetWorld()->SpawnActor<AProyectil>(ubicacion, rotacion);
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, TEXT("¡Disparo realizado!"));
	}


}

FString ADisparoDecorador::Estado()
{
	estado = "Estado disparador";
	return Super::Estado() + estado;
}

FString ADisparoDecorador::ObtenerAtributos()
{
	atributos = "Poder disparar";
	return Super::ObtenerAtributos() + atributos;
}

float ADisparoDecorador::Duracion()
{
	return Super::Duracion() + 15.f;

}
