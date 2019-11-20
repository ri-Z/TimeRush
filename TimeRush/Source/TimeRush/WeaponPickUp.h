// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponPickUp.generated.h"

UCLASS()
class TIMERUSH_API AWeaponPickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponPickUp();

	UPROPERTY(EditAnywhere, Category = "Gameplay")
		float RotationSpeed;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UPROPERTY(EditAnywhere)
		int weaponTypePickup;		


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UStaticMeshComponent *MeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		class USphereComponent *SphereComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
		class UParticleSystem *CollectEffect;


	void PlayEffect();

	
	


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
