// Fill out your copyright notice in the Description page of Project Settings.


#include "SniperProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Target.h"
#include "MyCharacter.h"
#include "Engine.h"
#include "UnrealNetwork.h"


// Sets default values
ASniperProjectile::ASniperProjectile()
{
	ProjectileSpeed = 40000.0f;
	GravityDelay = 0.1f;
	GravityScale = 3.5f;


	ProjectileCollision = CreateDefaultSubobject<UBoxComponent>(FName("ProjectileCollision"));
	ProjectileCollision->InitBoxExtent(FVector(2.f));
	ProjectileCollision->BodyInstance.SetCollisionProfileName("Projectile");
	/*ProjectileCollision->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	ProjectileCollision->SetSimulatePhysics(true);
	ProjectileCollision->SetNotifyRigidBodyCollision(true);*/
	ProjectileCollision->OnComponentHit.AddDynamic(this, &ASniperProjectile::OnProjectileHit);
	SetRootComponent(ProjectileCollision);

	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = ProjectileCollision;
	ProjectileMovement->InitialSpeed = ProjectileSpeed;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.0f;


	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("ProjectileMesh"));
	ProjectileMesh->SetupAttachment(RootComponent);

	ProjectileParticles = CreateDefaultSubobject<UParticleSystemComponent>(FName("ProjectileParticles"));
	ProjectileParticles->SetupAttachment(RootComponent);

	//If the bullet doesn't hit anything after 3 seconds, destroy it
	InitialLifeSpan = 3.0f;


	SetReplicates(true);
	SetReplicateMovement(true);

	bReplicates = true;
	//bReplicateInstigator = true;
	bNetUseOwnerRelevancy = true;
}

// Called when the game starts or when spawned
void ASniperProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	// after GravityDelay amount of time, make the bullet start dropping
	FTimerHandle DummyHandle;
	GetWorldTimerManager().SetTimer(DummyHandle, this, &ASniperProjectile::ApplyGravity, GravityDelay, false);
}

void ASniperProjectile::OnProjectileHit(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	//if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && (OtherActor->IsA(ATarget::StaticClass())))
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && (OtherActor->IsA(AMyCharacter::StaticClass())))
	{
		MyCharacter = Cast<AMyCharacter>(OtherActor);
		MyHit = Hit;

		if (Hit.BoneName != NAME_None)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("You hit the bots: %s"), *Hit.BoneName.ToString()));
		}

		if (MyCharacter)
		{
			UE_LOG(LogTemp, Warning, TEXT("IM HERE"));
			//ApplyDamage(/*MyCharacter*/);
			//MyCharacter->UpdateHealth(-200.f);
			MyCharacter->UpdateHealthServer(MyCharacter, -20.0f);
		}
		
		//OtherActor->Destroy();
	}

	Destroy();
}

void ASniperProjectile::ApplyGravity()
{
	ProjectileMovement->ProjectileGravityScale = GravityScale;
}

void ASniperProjectile::ApplyDamage_Implementation(/*AMyCharacter Character*/)
{
	//UGameplayStatics::ApplyPointDamage(MyCharacter, 200.0f, GetActorLocation(), MyHit, nullptr, this, SniperDamageType);
	/*AActor * OtherActor;
	OtherActor = Cast<AActor>(Character);
	UGameplayStatics::ApplyPointDamage(OtherActor, 200.0f, GetActorLocation(), MyHit, nullptr, this, SniperDamageType);*/
}

bool ASniperProjectile::ApplyDamage_Validate()
{
	return true;
}


