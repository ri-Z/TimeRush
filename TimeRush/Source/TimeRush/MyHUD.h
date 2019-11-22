// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class TIMERUSH_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AMyHUD();
	virtual void DrawHUD() override;
	virtual void BeginPlay() override;

private:
	class UTexture2D * CrosshairTex;

	UPROPERTY(EditAnywhere, Category = "Health")
		TSubclassOf<class UUserWidget> HUDWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Health")
		class UUserWidget * CurrentWidget;
};
