// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackHole.h"
#include "MyCharacter.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABlackHole::ABlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	//NOT WORKING, BLOWS THE EDITOR - THERE IS STUFF ABOUT THIS ON THE INTERNET - SO I USED THE BLUEPRINTS HERE
	/*MatComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MatComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MatComp->SetupAttachment(MeshComp);*/

	InnerSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("InnerSphereComp"));
	InnerSphereComponent->SetSphereRadius(100);
	InnerSphereComponent->SetupAttachment(MeshComp);

	//bind to event
	InnerSphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ABlackHole::OverlapInnerSphere);

	OuterSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("OuterSphereComp"));
	OuterSphereComponent->SetSphereRadius(3000);
	OuterSphereComponent->SetupAttachment(MeshComp);

	InitialLifeSpan = 3.0f;
}

void ABlackHole::OverlapInnerSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACharacter* OtherCharacter = Cast<ACharacter>(OtherActor);

	if (OtherActor || OtherCharacter)
	{
		OtherActor->Destroy();
	}
}

// Called every frame
void ABlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//find all overlapping components that can collide and may be physically simulating
	TArray<UPrimitiveComponent*> OverlappingComps;
	/*for (UPrimitiveComponent* character : OverlappingComps)
	{
		ACharacter* OverlappingCharacterActor = Cast<ACharacter>(character);
	}*/
	OuterSphereComponent->GetOverlappingComponents(OverlappingComps);

	for (int32 i = 0; i < OverlappingComps.Num(); i++)
	{
		UPrimitiveComponent* PrimComp = OverlappingComps[i];
		if (PrimComp && PrimComp->IsSimulatingPhysics())
		{
			//the component we are looking for! it needs to be simulating in order to apply forces
			const float SphereRadius = OuterSphereComponent->GetScaledSphereRadius();
			const float ForceStrength = -2000; // negative value to make it pull towards the origin instead of pushing away

			PrimComp->AddRadialForce(GetActorLocation(), SphereRadius, ForceStrength, ERadialImpulseFalloff::RIF_Linear, true);
			//PrimComp->AddRadialForce(GetActorLocation(), SphereRadius, ForceStrength, ERadialImpulseFalloff::RIF_Constant, true);
		}
	}
}

