// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeRushGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "MyHUD.h"

ATimeRushGameModeBase::ATimeRushGameModeBase() : Super()
{
	HUDClass = AMyHUD::StaticClass();
}

void ATimeRushGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	/*SetCurrentState(EGamePlayState::EPlaying);

	MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));*/
}

void ATimeRushGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*if (MyCharacter)
	{
		if (FMath::IsNearlyZero(MyCharacter->GetHealth(), 0.001f))
		{
			SetCurrentState(EGamePlayState::EGameOver);
		}
	}*/
}

//EGamePlayState ATimeRushGameModeBase::GetCurrentState() const
//{
//	return CurrentState;
//}
//
//void ATimeRushGameModeBase::SetCurrentState(EGamePlayState NewState)
//{
//	CurrentState = NewState;
//	HandleNewState(CurrentState);
//}
//
//void ATimeRushGameModeBase::HandleNewState(EGamePlayState NewState)
//{
//	switch (NewState)
//	{
//	case EGamePlayState::EPlaying:
//		break;
//	case EGamePlayState::EGameOver:
//		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
//		break;
//	case EGamePlayState::EUnknown:
//		break;
//	default:
//		break;
//	}
//}
