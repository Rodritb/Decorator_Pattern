// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Proyectil.generated.h"

UCLASS()
class SIS457_DONKEYKONG_API AProyectil : public AActor
{
	GENERATED_BODY()

	UStaticMeshComponent* ProyectilMesh;

public:
	// Sets default values for this actor's properties
	AProyectil();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	virtual void Mover(float DeltaTime);
	float vel;

};
