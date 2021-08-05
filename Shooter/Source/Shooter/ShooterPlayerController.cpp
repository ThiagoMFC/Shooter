// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner) {
	Super::GameHasEnded(EndGameFocus, bIsWinner);
	//UE_LOG(LogTemp, Warning, TEXT("finish"));

	if (bIsWinner) {
		UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
		if (WinScreen) {
			WinScreen->AddToViewport();
		}
	}
	else {
		UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
		if (LoseScreen) {
			LoseScreen->AddToViewport();
		}
	}

	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);

	
}