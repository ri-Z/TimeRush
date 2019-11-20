// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponPickUp.h"
#include "Components/SphereComponent.h"
#include "MyCharacter.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AWeaponPickUp::AWeaponPickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh Component");
	MeshComponent->SetupAttachment(RootComponent);

	SphereComponent = CreateDefaultSubobject<USphereComponent>("Sphere Component");
	SphereComponent->SetupAttachment(MeshComponent);

}

void AWeaponPickUp::NotifyActorBeginOverlap(AActor * OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (dynamic_cast<AMyCharacter*>(OtherActor) != nullptr)
	{
		AMyCharacter* character = Cast<AMyCharacter>(OtherActor);
		character->ChangeWeapon(weaponTypePickup);
		PlayEffect();
		Destroy(this);

	}

}

void AWeaponPickUp::BeginPlay()
{
	Super::BeginPlay();

}

void AWeaponPickUp::PlayEffect()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, CollectEffect, GetActorLocation());
}


// Called every frame
void AWeaponPickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0, RotationSpeed * DeltaTime, 0));

}

