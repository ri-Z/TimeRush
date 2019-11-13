// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm Component");
	//SpringArmComponent->bUsePawnControlRotation = true; // FAZ COM QUE CAMERA SE MOVA, I GUESS
	//SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera Component");
	//CameraComponent->SetupAttachment(GetMesh(), FName("head"));
	CameraComponent->bUsePawnControlRotation = true;
	//CameraComponent->AttachTo(SpringArmComponent, "headSocket");
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyCharacter::MoveForward(float value)
{
	if (value != 0.0f)
	{
		if (bIsSprinting)
			value *= 2;

		AddMovementInput(GetActorForwardVector(), value / 2); //Max Walk Speed property
	}
}

void AMyCharacter::MoveRight(float value)
{
	if (value != 0.0f)
	{
		if (bIsSprinting)
			value *= 2;

		AddMovementInput(GetActorRightVector(), value / 2); //Max Walk Speed property
	}
}

void AMyCharacter::BeginSprint()
{
	bIsSprinting = true;
}

void AMyCharacter::EndSprint()
{
	bIsSprinting = false;
}

void AMyCharacter::BeginCrouch()
{
	Crouch();
}

void AMyCharacter::EndCrouch()
{
	UnCrouch();
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AMyCharacter::BeginCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AMyCharacter::EndCrouch);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::Jump);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AMyCharacter::BeginSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AMyCharacter::EndSprint);
}

