// Fill out your copyright notice in the Description page of Project Settings.


#include "MedKit.h"

// Sets default values
AMedKit::AMedKit()
{
	MedKitMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("MedKitMesh"));
	MedKitMesh->SetupAttachment(RootComponent);

	OnActorBeginOverlap.AddDynamic(this, &AMedKit::OnOverlap);
}

void AMedKit::OnOverlap(AActor * MyOverlappedActor, AActor * OtherActor)
{
	if ((OtherActor != nullptr) && (OtherActor != this))
	{
		MyCharacter = Cast<AMyCharacter>(OtherActor);

		if (MyCharacter && MyCharacter->GetHealth() < 1.0f)
		{
			MyCharacter->UpdateHealth(100.0f);
			Destroy();
		}
	}
}
