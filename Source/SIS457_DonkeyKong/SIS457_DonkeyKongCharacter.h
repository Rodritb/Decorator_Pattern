// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "DecoradorInterface.h"
#include "CoreMinimal.h"
#include "DecoradorInterface.h"
#include "GameFramework/Character.h"
#include "SIS457_DonkeyKongCharacter.generated.h"
UCLASS(config = Game)
class ASIS457_DonkeyKongCharacter : public ACharacter, public IDecoradorInterface
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

protected:

	/** Called for side to side input */
	void MoveRight(float Val);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface


public:
	ASIS457_DonkeyKongCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	IDecoradorInterface* Jugador;

public:
	void Empezar() override {};
	FString Estado() override { return " "; };
	FString ObtenerAtributos() override { return  ""; };
	float Duracion() override { return 0.f; };
};
