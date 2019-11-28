// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "SniperProjectile.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h" 
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "Components/TimelineComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"
#include "Net/UnrealNetwork.h"
#include "MyProjectileGrenade.h"
#include "AbilityShot.h"
#include "TimerManager.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera Component");
	CameraComponent->SetupAttachment(GetMesh(), FName("head"));
	CameraComponent->bUsePawnControlRotation = true;

	SniperSpawn = CreateDefaultSubobject<USceneComponent>("Sniper Spawn");
	SniperSpawn->SetupAttachment(GetMesh(), FName("head"));
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

	//isFire = false;

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

	AltRifleTimerStop = true;

	minRandValRecoilH = -.3f;
	maxRandValRecoilH = .3f;
	JumpHeight = 600.0f;
	canFireAltAgain = true;
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

void AMyCharacter::DoubleJump()
{
	if (DoubleJumpCounter <= 1)
	{
		LaunchCharacter(FVector(0, 0, JumpHeight), false, true);
		DoubleJumpCounter++;
	}
}

void AMyCharacter::Landed(const FHitResult & Hit)
{
	DoubleJumpCounter = 0;
}

void AMyCharacter::Ability()
{
	if (AltRifleProjectileClass != NULL /* && AltRifleTimerStop */ )
	{
		UWorld* const World = GetWorld();
		if (World != NULL)
		{

			//Recoil -= 1;
			//RecoilRecovery -= 0.3;

			//AltRifleTimerStop = false;
			//GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AMyCharacter::StopTimer, 2.0f, false, 5.0f);

			const FRotator SpawnRotation = GetControlRotation();
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			//const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);
			const FVector SpawnLocation = CameraComponent->GetComponentLocation();

			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

			// spawn the projectile at the muzzle
			World->SpawnActor<AAbilityShot>(AbilityProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);

		}
	}
}

void AMyCharacter::StopTimer()
{
	AltRifleTimerStop = true;
	UE_LOG(LogTemp, Warning, TEXT("hello"));
}

void AMyCharacter::ShootAlt(float dt)
{
	if (Role < ROLE_Authority)
	{
		ServerShootAlt(dt);
	}
	if (isAlt)
	{
		if (weaponType == 1)
		{
			if (canFireAltAgain && isFire)
			{
				if (ProjectileClass != NULL)
				{
					UE_LOG(LogTemp, Warning, TEXT("2"));

					UWorld* const World = GetWorld();
					if (World != NULL)
					{
						UE_LOG(LogTemp, Warning, TEXT("3"));

						Recoil -= 1;
						RecoilRecovery -= 0.3;
						//Recoil -= 0;
						//RecoilRecovery -=0 ;

						const FRotator SpawnRotation = GetControlRotation();
						//FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);
						FVector SpawnLocation = ((SniperSpawn != nullptr) ? SniperSpawn->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);
						//FVector SpawnLocation = SniperSpawn->GetComponentLocation();

						FActorSpawnParameters ActorSpawnParams;
						ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

						World->SpawnActor<ASniperProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
						canFireAltAgain = false;
					}
				}
			}
		}
		else if (weaponType == 2)
		{
			UE_LOG(LogTemp, Warning, TEXT("Alt Fire Rifle"));

			if (AltRifleProjectileClass != NULL && AltRifleTimerStop)
			{
				UWorld* const World = GetWorld();
				if (World != NULL)
				{

					Recoil -= 1;
					RecoilRecovery -= 0.3;

					AltRifleTimerStop = false;
					GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AMyCharacter::StopTimer, 2.0f, false, 5.0f);

					const FRotator SpawnRotation = GetControlRotation();
					// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
					//const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);
					const FVector SpawnLocation = CameraComponent->GetComponentLocation();

					//Set Spawn Collision Handling Override
					FActorSpawnParameters ActorSpawnParams;
					ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

					// spawn the projectile at the muzzle
					World->SpawnActor<AMyProjectileGrenade>(AltRifleProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);

				}
			}
		}

	}

	/*if (FireAnimation != NULL)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
		if (AnimInstance != NULL)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}*/
}

void AMyCharacter::Alt()
{
	isAlt = true;
}

void AMyCharacter::AltRelease()
{
	isAlt = false;
	canFireAltAgain = true;
}

void AMyCharacter::ChangeWeapon(int pickUp)
{
	weaponType = pickUp;
}

void AMyCharacter::ServerShoot_Implementation(float dt)
{
	Shoot(dt);
}

bool AMyCharacter::ServerShoot_Validate(float dt)
{
	return true;
}

void AMyCharacter::ServerShootAlt_Implementation(float dt)
{
	ShootAlt(dt);
}

bool AMyCharacter::ServerShootAlt_Validate(float dt)
{
	return true;
}

void AMyCharacter::Shoot(float dt)
{
	if (Role < ROLE_Authority)
	{
		ServerShoot(dt);
	}

	if (weaponType == 1)
	{
		fireRate = 0.5;
		//change damage var
		//change recoil
	}
	else if (weaponType == 2)
	{
		fireRate = 0.1;
		//change damage var
	}


	if (isFire && !isAlt)
	{

		FHitResult* HitResult = new FHitResult();
		FVector StartTrace = CameraComponent->GetComponentLocation();
		FVector ForwardVector = CameraComponent->GetForwardVector();
		FVector EndTrace = ((ForwardVector * 2000.f) + StartTrace);
		FCollisionQueryParams* TraceParams = new FCollisionQueryParams();
		UWorld* const World = GetWorld();

		if (World->GetTimeSeconds() > nextShot)
		{

			float randResult = FMath::RandRange(minRandValRecoilH, maxRandValRecoilH);
			Recoil -= .3f;
			RecoilRecovery -= 0.3f;
			RecoilH -= randResult;
			RecoilRecovery -= randResult;

			UE_LOG(LogTemp, Warning, TEXT("fireRate: %f"), fireRate);


			if (GetWorld()->LineTraceSingleByChannel(*HitResult, StartTrace, EndTrace, ECC_Visibility, *TraceParams))
			{
				DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Black, false, 5.f);
				//ATargetTest* TestTarget = Cast<ATargetTest>(HitResult->Actor.Get());

				//if (TestTarget != NULL && TestTarget->IsPendingKill())
				//{
				//	TestTarget->DamageTarget(50.f); //use damage var
				//}
			}

			nextShot = World->GetTimeSeconds() + fireRate;
		}

	}

	/*if (FireAnimation != NULL)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
		if (AnimInstance != NULL)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}*/
}

float AMyCharacter::GetHealth()
{
	return HealthPercentage;
}

void AMyCharacter::UpdateHealthServer_Implementation(AMyCharacter * character, float hp)
{
	UE_LOG(LogTemp, Warning, TEXT("server handled"));
	//UpdateHealthClient(character, hp);
	Health += hp;
	Health = FMath::Clamp(Health, 0.0f, FullHealth);
	HealthPercentage = Health / FullHealth;
	redFlash = true;
	UE_LOG(LogTemp, Warning, TEXT("handled damage on %f"), Health);
}

bool AMyCharacter::UpdateHealthServer_Validate(AMyCharacter * character, float hp)
{
	return true;
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

//void AMyCharacter::ReceivePointDamage(float Damage, const class UDamageType * DamageType, FVector HitLocation, FVector HitNormal, class UPrimitiveComponent * HitComponent, FName BoneName, FVector ShotFromDirection, class AController * InstigatedBy, AActor * DamageCauser, const FHitResult & HitInfo)
//{
//	//bCanBeDamaged = false;
//	redFlash = true;
//
//	//UpdateHealth(-Damage);
//	UpdateHealthServer(this, -Damage);
//}

float AMyCharacter::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	redFlash = true;

	UE_LOG(LogTemp, Warning, TEXT("handled damage on %s"), *FString(this->GetName()));
	UpdateHealthServer(this, -DamageAmount);

	return 0.0f;
}

void AMyCharacter::UpdateHealth(float HealthChange)
{
	Health += HealthChange;
	Health = FMath::Clamp(Health, 0.0f, FullHealth);
	HealthPercentage = Health / FullHealth;
}

//void AMyCharacter::UpdateHealth_Implementation(float HealthChange)
//{
//	Health += HealthChange;
//	Health = FMath::Clamp(Health, 0.0f, FullHealth);
//	HealthPercentage = Health / FullHealth;
//}
//
//bool AMyCharacter::UpdateHealth_Validate(float HealthChange)
//{
//	return true;
//}

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

void AMyCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AMyCharacter, FullHealth);
	DOREPLIFETIME(AMyCharacter, Health);
	DOREPLIFETIME(AMyCharacter, HealthPercentage);
	DOREPLIFETIME(AMyCharacter, redFlash);
}


// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Shoot(DeltaTime);
	ShootAlt(DeltaTime);

	Recoil = FMath::FInterpTo(Recoil, 0, DeltaTime, 10.0f);
	RecoilRecovery = FMath::FInterpTo(RecoilRecovery, -Recoil, DeltaTime, 20.0f);
	ApplyPitch = Recoil + RecoilRecovery;


	RecoilH = FMath::FInterpTo(RecoilH, 0, DeltaTime, 10.0f);
	RecoilRecoveryH = FMath::FInterpTo(RecoilRecoveryH, -RecoilH, DeltaTime, 20.0f);
	ApplyPitchH = RecoilH + RecoilRecoveryH;

	this->AddControllerPitchInput(ApplyPitch);
	this->AddControllerYawInput(ApplyPitchH);

	
		FRotator newRot = CameraComponent->RelativeRotation;
		//FRotator newRot = GetActorRotation();
		//FRotator newRot = GetControlRotation();
		//this->AddControllerPitchInput(RemoteViewPitch * 360.0f / 255.0f);
			newRot.Pitch = RemoteViewPitch * 360.0f / 255.0f;
			CameraComponent->SetRelativeRotation(newRot);
			//this->AddControllerPitchInput(RemoteViewPitch * 360.0f / 255.0f);
	

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

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::DoubleJump);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AMyCharacter::BeginSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AMyCharacter::EndSprint);

	PlayerInputComponent->BindAction("Aim", IE_Pressed, this, &AMyCharacter::ToggleAiming);
	PlayerInputComponent->BindAction("Aim", IE_Released, this, &AMyCharacter::ToggleAiming);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AMyCharacter::OnFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &AMyCharacter::OnFireRelease);

	PlayerInputComponent->BindAction("Ability", IE_Pressed, this, &AMyCharacter::Ability);

	PlayerInputComponent->BindAction("Aim", IE_Pressed, this, &AMyCharacter::Alt);
	PlayerInputComponent->BindAction("Aim", IE_Released, this, &AMyCharacter::AltRelease);
}