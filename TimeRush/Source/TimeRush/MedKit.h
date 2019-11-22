// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCharacter.h"
#include "MedKit.generated.h"

UCLASS()
class TIMERUSH_API AMedKit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMedKit();

protected:
	UFUNCTION()
		void OnOverlap(AActor * MyOverlappedActor, AActor * OtherActor);

	UPROPERTY(EditAnywhere)
		AMyCharacter * MyCharacter;

	UPROPERTY(EditDefaultsOnly)
		class UStaticMeshComponent *MedKitMesh;
};
