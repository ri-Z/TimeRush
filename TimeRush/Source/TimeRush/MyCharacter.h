// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class TIMERUSH_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float value);
	void MoveRight(float value);
	void BeginSprint();
	void EndSprint();
	void BeginCrouch();
	void EndCrouch();

	int weaponType;
	void OnFireRelease();
	bool isFire;
	bool isAlt;
	bool canFireAltAgain;
	bool AltRifleTimerStop;

	UPROPERTY(EditAnywhere)
		float fireRate;

	float nextShot;

	UPROPERTY(EditAnywhere)
		float Recoil;

	UPROPERTY(EditAnywhere)
		float RecoilRecovery;

	UPROPERTY(EditAnywhere)
		float RecoilH;

	UPROPERTY(EditAnywhere)
		float RecoilRecoveryH;

	float ApplyPitch;
	float ApplyPitchH;
	float minRandValRecoilH;
	float maxRandValRecoilH;
	virtual void Landed(const FHitResult& Hit) override;
	

	void OnFire();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		class UCameraComponent *CameraComponent;
	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class USpringArmComponent *SpringArmComponent;*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		class USceneComponent *SniperSpawn;

	bool bIsSprinting = false;

	UPROPERTY(BlueprintReadWrite)
	bool bIsAiming;

	//UCameraComponent* camera;

	UFUNCTION(BlueprintImplementableEvent)
		void ShowSniperOverlay();
	UFUNCTION(BlueprintImplementableEvent)
		void HideSniperOverlay();
	
	UFUNCTION()
	void ToggleAiming();

	UFUNCTION()
		void ShootAlt(float DeltaTime);

	UFUNCTION()
		void Alt();

	UFUNCTION()
		void AltRelease();

	void Ability();

	/*UFUNCTION(BlueprintCallable, Category = "Game|Weapon")
		FRotator GetAimOffsets() const;*/

	UFUNCTION()
		void Shoot(float DeltaTime);

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
		class USkeletalMeshComponent* FP_Gun;

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
		class USceneComponent* FP_MuzzleLocation;

	/* Health System */
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Health")
		float FullHealth;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Health")
		float Health;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Health")
		float HealthPercentage;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Health")
		bool redFlash;

	UFUNCTION(BlueprintPure, Category = "Health")
		FText GetHealthIntText();

	/*UFUNCTION()
		void SetDamageState();*/

	UFUNCTION(BlueprintPure, Category = "Health")
		bool PlayFlash();

	// tentar por public
	//void ReceivePointDamage(float Damage, const class UDamageType * DamageType, FVector HitLocation, FVector HitNormal, class UPrimitiveComponent * HitComponent, FName BoneName, FVector ShotFromDirection, class AController * InstigatedBy, AActor * DamageCauser, const FHitResult & HitInfo);
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;
	/* Health System */

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return CameraComponent; }

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
		TSubclassOf<class ASniperProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
		FVector GunOffset;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
		TSubclassOf<class AMyProjectileGrenade> AltRifleProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
		TSubclassOf<class AAbilityShot> AbilityProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
		class UAnimMontage* FireAnimation;

	void ChangeWeapon(int pickUp);

	/* Health System */
	UFUNCTION(BlueprintPure, Category = "Health")
		float GetHealth();

	UFUNCTION(/*Server, Reliable, WithValidation, */BlueprintCallable, Category = "Health") // should be on protected
		void UpdateHealth(float HealthChange);
	/* Health System */

	//FRotator GetViewRotation() const override;

	UFUNCTION(Server, Reliable, WithValidation) // should be on protected
		void UpdateHealthServer(AMyCharacter* character, float hp);

	/*UFUNCTION(NetMulticast, Reliable)
		void UpdateHealthClient(AMyCharacter* character, float hp);*/

	UFUNCTION(Server, Reliable, WithValidation) // should be on protected
		void ServerShoot(float DeltaTime);

	UFUNCTION(Server, Reliable, WithValidation)
		void ServerShootAlt(float DeltaTime);

	UPROPERTY()
		int DoubleJumpCounter;
	UPROPERTY(EditAnywhere)
		float JumpHeight;
	UFUNCTION()
		void DoubleJump();

	void StopTimer();

	struct FTimerHandle MemberTimerHandle;
};
