// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "SniperProjectile.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h" 
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "Components/TimelineComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera Component");
	CameraComponent->SetupAttachment(GetMesh(), FName("head"));
	CameraComponent->bUsePawnControlRotation = true;

	//camera = FindComponentByClass<UCameraComponent>();


	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	//FP_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	FP_Gun->bCastDynamicShadow = true;
	FP_Gun->CastShadow = true;
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	FP_Gun->SetupAttachment(GetMesh(), FName("hand_r"));

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);

	isFire = false;

	SetReplicates(true);
	SetReplicateMovement(true);
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	weaponType = 1;

	FullHealth = 1000.0f;
	Health = FullHealth;
	HealthPercentage = 1.0f;
	bCanBeDamaged = true;
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

//FRotator AMyCharacter::GetAimOffsets() const
//{
//	const FVector AimDirWS = GetBaseAimRotation().Vector();
//	const FVector AimDirLS = ActorToWorld().InverseTransformVectorNoScale(AimDirWS);
//	const FRotator AimRotLS = AimDirLS.Rotation();
//
//	return AimRotLS;
//}

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

void AMyCharacter::ChangeWeapon(int pickUp)
{
	weaponType = pickUp;
}

void AMyCharacter::Shoot(float dt)
{
	//AMyCharacter* character = Cast<AMyCharacter>(Controller);
	//Recoil = RSaver;
	//RecoilRecovery = RRSaver;

	if (isFire)
	{
		if (weaponType == 1)
		{
			//fireRate = 1;

			if (ProjectileClass != NULL)
			{
				UWorld* const World = GetWorld();
				if (World != NULL)
				{
					if (World->GetTimeSeconds() > nextShot)
					{

						Recoil -= 1;
						RecoilRecovery -= 0.3f;

						const FRotator SpawnRotation = GetControlRotation();
						FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

						FActorSpawnParameters ActorSpawnParams;
						ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

						World->SpawnActor<ASniperProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
					}
					nextShot = World->GetTimeSeconds() + fireRate;
				}
			}
		}
		else if (weaponType == 2)
		{
			fireRate = 0.1f;

			FHitResult* HitResult = new FHitResult();
			FVector StartTrace = CameraComponent->GetComponentLocation();
			FVector ForwardVector = CameraComponent->GetForwardVector();
			FVector EndTrace = ((ForwardVector * 2000.f) + StartTrace);
			FCollisionQueryParams* TraceParams = new FCollisionQueryParams();
			UWorld* const World = GetWorld();

			if (World->GetTimeSeconds() > nextShot)
			{

				Recoil -= .3f;
				RecoilRecovery -= 0.10f;
				UE_LOG(LogTemp, Warning, TEXT("fireRate: %f"), fireRate);


				if (GetWorld()->LineTraceSingleByChannel(*HitResult, StartTrace, EndTrace, ECC_Visibility, *TraceParams))
				{
					DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Black, false, 5.f);


					//UE_LOG(LogTemp, Warning, TEXT("I should recoil now"));
					UE_LOG(LogTemp, Warning, TEXT("ApplyPitch%f : "), ApplyPitch);
					//UE_LOG(LogTemp, Warning, TEXT("DT%f : "), DeltaTime);
				}

				nextShot = World->GetTimeSeconds() + fireRate;
			}
		}
	}
}

float AMyCharacter::GetHealth()
{
	return HealthPercentage;
}

FText AMyCharacter::GetHealthIntText()
{
	int32 HP = FMath::RoundHalfFromZero(HealthPercentage * 100);
	FString HPS = FString::FromInt(HP);
	FString HealthHUD = HPS + FString(TEXT("%"));
	FText HPTEXT = FText::FromString(HealthHUD);
	return HPTEXT;
}

//void AMyCharacter::SetDamageState()
//{
//	bCanBeDamaged = true;
//}

bool AMyCharacter::PlayFlash()
{
	if (redFlash)
	{
		redFlash = false;
		return true;
	}
	return false;
}

void AMyCharacter::ReceivePointDamage(float Damage, const class UDamageType * DamageType, FVector HitLocation, FVector HitNormal, class UPrimitiveComponent * HitComponent, FName BoneName, FVector ShotFromDirection, class AController * InstigatedBy, AActor * DamageCauser, const FHitResult & HitInfo)
{
	//bCanBeDamaged = false;
	redFlash = true;

	UpdateHealth(-Damage);
}

void AMyCharacter::UpdateHealth(float HealthChange)
{
	Health += HealthPercentage;
	Health = FMath::Clamp(Health, 0.0f, FullHealth);
	HealthPercentage = Health / FullHealth;
}

void AMyCharacter::OnFireRelease()
{
	isFire = false;
}

void AMyCharacter::OnFire()
{
	isFire = true;
}

void AMyCharacter::ToggleAiming()
{
	if (weaponType == 1)
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
}

//FRotator AMyCharacter::GetViewRotation() const
//{
//	if (Controller)
//	{
//		return Controller->GetControlRotation();
//	}
//	return FRotator(RemoteViewPitch * 360.0f / 255.0f, GetActorRotation().Yaw, 0.f);
//}

//void AMyCharacter::OnFire()
//{
//	if (ProjectileClass != NULL)
//	{
//		UWorld* const World = GetWorld();
//		if (World != NULL)
//		{
//			UE_LOG(LogTemp, Warning, TEXT("shooting"));
//			const FRotator SpawnRotation = GetControlRotation();
//			FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);
//
//			FActorSpawnParameters ActorSpawnParams;
//			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
//
//			World->SpawnActor<ASniperProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
//		}
//	}
//}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Recoil = FMath::FInterpTo(Recoil, 0, DeltaTime, 10.0f);
	RecoilRecovery = FMath::FInterpTo(RecoilRecovery, -Recoil, DeltaTime, 20.0f);
	ApplyPitch = Recoil + RecoilRecovery;

	this->AddControllerPitchInput(ApplyPitch);
	this->AddControllerYawInput(ApplyPitch);

	Shoot(DeltaTime);

	//if (!IsLocallyControlled())
	//{
	//	//FRotator newRot = CameraComponent->RelativeRotation;
	//	//FRotator newRot = GetActorRotation();
	//	FRotator newRot = GetControlRotation();
	//	//this->AddControllerPitchInput(RemoteViewPitch * 360.0f / 255.0f);
	//	if (newRot.Pitch == 0.f)
	//	{
	//		/*newRot.Pitch = RemoteViewPitch * 360.0f / 255.0f;
	//		CameraComponent->SetRelativeRotation(newRot);*/
	//		this->AddControllerPitchInput(RemoteViewPitch * 360.0f / 255.0f);
	//	}
	//}

	//CameraComponent->SetWorldRotation(GetViewRotation());
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
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &AMyCharacter::OnFireRelease);
}