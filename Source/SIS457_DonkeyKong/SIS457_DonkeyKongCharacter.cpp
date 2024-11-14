// Copyright Epic Games, Inc. All Rights Reserved.

#include "SIS457_DonkeyKongCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Proyectil.h"
#include "Jugador.h"
#include "EscudoDecorador.h"
#include "DisparoDecorador.h"


ASIS457_DonkeyKongCharacter::ASIS457_DonkeyKongCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f, 0.f, 75.f);
	CameraBoom->SetRelativeRotation(FRotator(0.f, 180.f, 0.f));

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)


}



void ASIS457_DonkeyKongCharacter::BeginPlay()
{
	Super::BeginPlay();

	ACharacter* Mario = Cast<ACharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (Mario) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue,
			FString::Printf(TEXT("Mario encontrado")));
	}

	//Engendramos al jugador principal
	//AJugador* JugadorPrincipal = GetWorld()->SpawnActor<AJugador>(AJugador::StaticClass());

	//Engendramos un decorador para correr en el jugador principal
	ADisparoDecorador* Disparo = GetWorld()->SpawnActor<ADisparoDecorador>(ADisparoDecorador::StaticClass());
	Disparo->SetJugador(Mario);

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
		FString::Printf(TEXT("Su duracion es de %.2f"), Jugador->Duracion()));
}

void ASIS457_DonkeyKongCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




//////////////////////////////////////////////////////////////////////////
// Input

void ASIS457_DonkeyKongCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	//PlayerInputComponent->BindAction("Empezar", IE_Released, this, &ADisparoDecorador::Empezar);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASIS457_DonkeyKongCharacter::MoveRight);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &ASIS457_DonkeyKongCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ASIS457_DonkeyKongCharacter::TouchStopped);
}

void ASIS457_DonkeyKongCharacter::MoveRight(float Value)
{
	// add movement in that direction
	AddMovementInput(FVector(0.f, -1.f, 0.f), Value);


}

void ASIS457_DonkeyKongCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}

void ASIS457_DonkeyKongCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}
