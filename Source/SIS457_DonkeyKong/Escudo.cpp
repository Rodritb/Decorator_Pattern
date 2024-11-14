// Fill out your copyright notice in the Description page of Project Settings.


#include "Escudo.h"

// Sets default values
AEscudo::AEscudo()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	mallaEscudo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mallaEscudo->SetStaticMesh(MeshAsset.Object);
	RootComponent = mallaEscudo;

	FVector NewScale(0.1f, 1.0f, 1.0f); // Cambia estos valores según tus necesidades
	SetActorScale3D(NewScale);

}

// Called when the game starts or when spawned
void AEscudo::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEscudo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
