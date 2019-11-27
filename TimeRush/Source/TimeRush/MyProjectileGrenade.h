// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyProjectileGrenade.generated.h"

UCLASS()
class TIMERUSH_API AMyProjectileGrenade : public AActor
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
	AMyProjectileGrenade();

	UPROPERTY(EditAnywhere, Category = "FX")
		class UParticleSystem* ExplosionParticles;

	UPROPERTY(EditAnywhere, Category = "Projectile")
		float Radius = 500.f;

	virtual void BeginPlay() override;

	UFUNCTION()
		void OnDetonate();

	/** called when projectile hits something */
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	FORCEINLINE class USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	FORCEINLINE class UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }

};
