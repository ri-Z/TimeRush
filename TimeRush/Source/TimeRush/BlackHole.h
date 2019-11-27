// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlackHole.generated.h"

UCLASS()
class TIMERUSH_API ABlackHole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlackHole();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UStaticMeshComponent* MeshComp;

	/*UPROPERTY(VisibleAnywhere, Category = "Components")
		class UStaticMeshComponent* MatComp;*/

	//inner sphere destroys the overlapping components
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class USphereComponent* InnerSphereComponent;

	//outter sphere pulls components (that are physically simulating) towards the centre of the actor
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class USphereComponent* OuterSphereComponent;

	//marked with ufunction to bind to overlap event
	UFUNCTION()
		void OverlapInnerSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
