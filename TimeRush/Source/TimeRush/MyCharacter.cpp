// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "SniperProjectile.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
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
	CameraComponent->SetupAttachment(GetMesh(), FName("head"));
	CameraComponent->bUsePawnControlRotation = true;
	//CameraComponent->AttachTo(SpringArmComponent, "headSocket");

	//camera = FindComponentByClass<UCameraComponent>();


	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	//FP_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	FP_Gun->SetupAttachment(RootComponent);

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);
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

void AMyCharacter::ToggleAiming()
{
	bIsAiming = !bIsAiming;

	if (bIsAiming)
	{
		ShowSniperOverlay();
		CameraComponent->SetFieldOfView(10.f);
		//GetFirstPersonCameraComponent()->SetFieldOfView(10.f);
		/*camera->SetFieldOfView(10.f);
		if (camera)
		{
			UE_LOG(LogTemp, Warning, TEXT("CAMERA HELLO"));
		}*/
		FP_Gun->SetVisibility(false);
	}
	else
	{
		HideSniperOverlay();
		CameraComponent->SetFieldOfView(90.f);
		//GetFirstPersonCameraComponent()->SetFieldOfView(90.f);
		/*camera->SetFieldOfView(90.f);
		if (camera)
		{
			UE_LOG(LogTemp, Warning, TEXT("CAMERA BYE"));
		}*/
		FP_Gun->SetVisibility(true);
	}
}

void AMyCharacter::OnFire()
{
	if (ProjectileClass != NULL)
	{
		UWorld* const World = GetWorld();
		if (World != NULL)
		{
			UE_LOG(LogTemp, Warning, TEXT("shooting"));
			const FRotator SpawnRotation = GetControlRotation();
			FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

			World->SpawnActor<ASniperProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
		}
	}
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

	PlayerInputComponent->BindAction("Aim", IE_Pressed, this, &AMyCharacter::ToggleAiming);
	PlayerInputComponent->BindAction("Aim", IE_Released, this, &AMyCharacter::ToggleAiming);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AMyCharacter::OnFire);
}

