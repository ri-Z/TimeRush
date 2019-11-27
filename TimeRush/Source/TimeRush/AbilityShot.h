// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilityShot.generated.h"

UCLASS()
class TIMERUSH_API AAbilityShot : public AActor
{
	GENERATED_BODY()

		/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		class USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		class UProjectileMovementComponent* ProjectileMovement;


public:	
	// Sets default values for this actor's properties
	AAbilityShot();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "FX")
		class UParticleSystem* ExplosionParticles;

	UFUNCTION()
		void OnAbility();

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	FORCEINLINE class USphereComponent* GetCollisionComp() const { return CollisionComp; }

	FORCEINLINE class UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }


};
