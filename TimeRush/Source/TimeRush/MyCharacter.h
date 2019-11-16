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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float value);
	void MoveRight(float value);
	void BeginSprint();
	void EndSprint();
	void BeginCrouch();
	void EndCrouch();

	void OnFire();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		class UCameraComponent *CameraComponent;
	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class USpringArmComponent *SpringArmComponent;*/

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

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
		class USkeletalMeshComponent* FP_Gun;

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
		class USceneComponent* FP_MuzzleLocation;

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
};
