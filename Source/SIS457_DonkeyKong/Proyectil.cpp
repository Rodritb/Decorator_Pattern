// Fill out your copyright notice in the Description page of Project Settings.


#include "Proyectil.h"
#include "Jugador.h"

// Sets default values
AProyectil::AProyectil()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	// Carga estática del mesh para el proyectil
  // Utiliza FObjectFinder para buscar y cargar el asset del mesh para el proyectil
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		ProjectileMeshAsset(TEXT("StaticMesh'/Game/Meshes/Projectile.Projectile'"));

	ProyectilMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh0"));
	ProyectilMesh->SetStaticMesh(ProjectileMeshAsset.Object);

	FVector NewScale(1.0f, 1.0f, 1.0f); // Cambia estos valores según tus necesidades
	SetActorScale3D(NewScale);
	vel = 1000;
}

// Called when the game starts or when spawned
void AProyectil::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AProyectil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Mover(DeltaTime);
}

void AProyectil::Mover(float DeltaTime)
{

	FVector NewLocation = GetActorLocation() + GetActorForwardVector() * vel * GetWorld()->GetDeltaSeconds();
	//FVector NewLocation = GetActorLocation() + FVector(0.0f, -vel, 0.0f) * DeltaTime;
	SetActorLocation(NewLocation);

}

