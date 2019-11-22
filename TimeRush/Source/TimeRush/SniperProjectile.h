// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "SniperProjectile.generated.h"

UCLASS()
class TIMERUSH_API ASniperProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASniperProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	UPROPERTY(EditDefaultsOnly)
		UBoxComponent* ProjectileCollision;

	UPROPERTY(EditDefaultsOnly)
		class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditDefaultsOnly)
		class UStaticMeshComponent *ProjectileMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
		class UParticleSystemComponent *ProjectileParticles;

	UPROPERTY(EditDefaultsOnly)
		float ProjectileSpeed;

	//amount of seconds to wait until bullet begins dropping
	UPROPERTY(EditDefaultsOnly)
		float GravityDelay;

	//scale for the gravity acting upon bullet
	UPROPERTY(EditDefaultsOnly)
		float GravityScale;

	UFUNCTION()
		void OnProjectileHit(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& SweepResult);

	// when called, gravity will start effecting the bullet, making it drop.
	UFUNCTION()
		void ApplyGravity();

	UFUNCTION()
		void ApplyDamage();

	UPROPERTY(EditAnywhere)
		AActor * MyCharacter;

	UPROPERTY(EditAnywhere)
		FHitResult MyHit;

	UPROPERTY(EditAnywhere)
		TSubclassOf<UDamageType> SniperDamageType;
};
