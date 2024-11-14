// Fill out your copyright notice in the Description page of Project Settings.


#include "EscudoDecorador.h"
#include "Escudo.h"
#include "SIS457_DonkeyKong.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEscudoDecorador::AEscudoDecorador()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEscudoDecorador::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEscudoDecorador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEscudoDecorador::Empezar()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Orange, FString::Printf(TEXT("Ahora tiene 1 capa")));

	APawn* Player1 = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (Player1)
	{
		FVector ubicacion = Player1->GetActorLocation() + FVector(20.0f, 40.0f, -15.0f);
		FRotator rotacion = Player1->GetActorRotation();
		AEscudo* NewProj0 = GetWorld()->SpawnActor<AEscudo>(ubicacion, rotacion);
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, TEXT("Mario con escudo"));
	}
}

FString AEscudoDecorador::Estado()
{
	estado = " Protegerse con Escudo";
	return Super::Estado() + estado;
}

FString AEscudoDecorador::ObtenerAtributos()
{
	atributos = " Escudo activo ";
	return Super::ObtenerAtributos() + atributos;
}

float AEscudoDecorador::Duracion()
{
	return Super::Duracion() + 5.f;
}