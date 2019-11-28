// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class TIMERUSH_API AMyGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	/*UFUNCTION()
		int CountDroppedItems();

	UFUNCTION(Server, Reliable, WithValidation)
		void ServerCountDroppedItems();

	UPROPERTY()
		int ServerCountItems;

	UFUNCTION(NetMulticast, Reliable)
		void MulticastFinishCollection(bool succeded);*/
};
